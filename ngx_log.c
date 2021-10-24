#include "ngx_log.h"

static ngx_log_t        ngx_log;
static ngx_open_file_t  ngx_log_file;
ngx_uint_t              ngx_use_stderr = 1;

ngx_log_t *
ngx_log_init(u_char *prefix)
{
    u_char *p, *name;
    size_t nlen, plen;
    
    ngx_log.file = &ngx_log_file;
    ngx_log.log_level = NGX_LOG_NOTICE;
    name = (u_char *)NGX_ERROR_LOG_PATH;

    nlen = ngx_strlen(name);
    if (nlen == 0) {
        ngx_log_file.fd =  ngx_stderr;
        return &ngx_log;
    }
    p = NULL;
    if (name[0] != '/') {
        if (prefix) {
            plen = ngx_strlen(prefix);
        } else {
        }
    }
}
