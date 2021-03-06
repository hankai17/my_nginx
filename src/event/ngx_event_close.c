
#include <ngx_config.h>
#include <ngx_core.h>
#include <ngx_types.h>
#include <ngx_connection.h>
#include <ngx_event_close.h>


int ngx_event_close_connection(ngx_event_t *ev)
{
    int rc;
    ngx_connection_t *c = (ngx_connection_t *) ev->data;

    ngx_assert((c->fd != -1), return NGX_ERROR, c->log,
               "ngx_event_close: already closed");

    ngx_destroy_pool(c->pool);

    if ((rc = ngx_close_socket(c->fd)) == -1)
        ngx_log_error(NGX_LOG_ERR, c->log, ngx_socket_errno,
                      "ngx_event_close: close failed");

    if (c->read->next)
        ngx_del_event(c->read, NGX_READ_EVENT);

    if (c->write->next)
        ngx_del_event(c->write, NGX_WRITE_EVENT);

    c->fd = -1;

    return rc;
}
