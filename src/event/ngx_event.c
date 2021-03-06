
#include <ngx_config.h>
#include <ngx_core.h>
#include <ngx_types.h>
#include <ngx_string.h>
#include <ngx_log.h>
#include <ngx_alloc.h>
#include <ngx_listen.h>
#include <ngx_connection.h>
#include <ngx_event.h>
#include <ngx_event_accept.h>
#include <ngx_select_module.h>

ngx_connection_t    *ngx_connections;
ngx_event_t         *ngx_read_events, *ngx_write_events;
// 三个全局数组
// 既然Event作为抽象 而且包含上层connection 那么为什么还用全局conn数组? 直接malloc不行吗
ngx_event_type_e     ngx_event_type = NGX_SELECT_EVENT;
ngx_event_actions_t  ngx_event_actions;

static int (*ngx_event_init[]) (int max_connections, ngx_log_t *log) = {
    ngx_select_init,
};

// 一级抽象
// Event作为抽象层 用泛指针封装了上层connection ---> 底层select/epoll/kqueue得回调传参为(Event, rw_event)
// event_action作为抽象层 目的是绑定上层Event->底层io得关系 ---> add/del(Event, rw_event)
// 依赖反转 依赖反转得骨是event_action->process

void ngx_pre_thread(ngx_array_t *ls, ngx_pool_t *pool, ngx_log_t *log)
{
    int  i, fd;
    ngx_listen_t *s;

    /* STUB */
    int max_connections = 512;

    if (ngx_init_events(max_connections, log) == NGX_ERROR)
        exit(1);

    ngx_connections = ngx_alloc(sizeof(ngx_connection_t)
                                                       * max_connections, log);
    ngx_read_events = ngx_alloc(sizeof(ngx_event_t) * max_connections, log);
    ngx_write_events = ngx_alloc(sizeof(ngx_event_t) * max_connections, log);

    /* for each listening socket */
    s = (ngx_listen_t *) ls->elts;
    for (i = 0; i < ls->nelts; i++) {

        fd = s[i].fd;

        ngx_memzero(&ngx_connections[fd], sizeof(ngx_connection_t));
        ngx_memzero(&ngx_read_events[fd], sizeof(ngx_event_t));

        ngx_connections[fd].fd = fd;
        ngx_connections[fd].family = s[i].family;
        ngx_connections[fd].socklen = s[i].socklen;
        ngx_connections[fd].sockaddr = ngx_palloc(pool, s[i].socklen);
        ngx_connections[fd].addr = s[i].addr;
        ngx_connections[fd].addr_text = s[i].addr_text;
        ngx_connections[fd].addr_textlen = s[i].addr_textlen;
        ngx_connections[fd].post_accept_timeout = s[i].post_accept_timeout;

        ngx_connections[fd].server = s[i].server;
        ngx_connections[fd].handler = s[i].handler;
        ngx_connections[fd].log = s[i].log;

        ngx_test_null(ngx_read_events[fd].log,
                      ngx_palloc(pool, sizeof(ngx_log_t)), /* void */ ; );
        ngx_memcpy(ngx_read_events[fd].log, ngx_connections[fd].log,
                   sizeof(ngx_log_t));
        ngx_read_events[fd].data = &ngx_connections[fd];
        ngx_read_events[fd].event_handler = &ngx_event_accept;
        ngx_read_events[fd].listening = 1;

        ngx_read_events[fd].available = 0;

#if (HAVE_DEFERRED_ACCEPT)
        ngx_read_events[fd].deferred_accept = s[i].deferred_accept;
#endif
        ngx_add_event(&ngx_read_events[fd], NGX_READ_EVENT, 0);
    }
}

void ngx_worker(ngx_log_t *log)
{
    while (1) {
        ngx_log_debug(log, "ngx_worker cycle");

        ngx_process_events(log);
    }
}
