#ifndef _NGX_CONNECTION_H_INCLUDED_
#define _NGX_CONNECTION_H_INCLUDED_

#include <ngx_array.h>
#include <ngx_socket.h>
#include <ngx_log.h>
#include <ngx_hunk.h>
#include <ngx_alloc.h>
#include <ngx_server.h>
#include <ngx_event.h>

typedef struct ngx_connection_s  ngx_connection_t;

struct ngx_connection_s {
    int     fd;
    void            *data;

    /* STUB */
    ngx_array_t     *requests;
    int              requests_len;

#ifdef NGX_EVENT
    ngx_event_t      *read;
    ngx_event_t      *write;
#endif

    off_t             sent;

    ngx_log_t        *log;
    int             (*handler)(ngx_connection_t *c);
    ngx_server_t     *server;
    ngx_server_t     *servers;
    ngx_pool_t       *pool;

    int               family;
    struct sockaddr  *sockaddr;
    socklen_t         socklen;
    size_t            addr;
    char             *addr_text;
    size_t            addr_textlen;

    ngx_hunk_t       *buffer;
    unsigned int      post_accept_timeout;

    unsigned          unexpected_eof:1;
};

#endif
