#ifndef _NGX_HTTP_PROXY_HANDLER_H_INCLUDED_
#define _NGX_HTTP_PROXY_HANDLER_H_INCLUDED_


#include <ngx_config.h>
#include <ngx_array.h>
#include <ngx_http.h>


typedef struct {
    int dummy;
} ngx_http_proxy_ctx_t;


extern ngx_http_module_t  ngx_http_proxy_module;


#endif /* _NGX_HTTP_PROXY_HANDLER_H_INCLUDED_ */
