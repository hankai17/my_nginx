#ifndef __NGX_LOG_H_INCLUDED_
#define __NGX_LOG_H_INCLUDED_

#include "ngx_config.h"

typedef struct ngx_log_s ngx_log_t;
typedef struct ngx_open_file_s ngx_open_file_t;
typedef u_char *(*ngx_log_handler_pt) (ngx_log_t *log, u_char *buf, size_t len);

struct ngx_open_file_s {
    ngx_uint_t         fd;
    const char* name;
    void (*flush)(ngx_open_file_t *file, ngx_log_t *log);
    void *      data;
};

struct ngx_log_s {
    uint32_t            log_level; 
    ngx_open_file_t    *file;
    ngx_atomic_uint_t   connection;
    ngx_log_handler_pt  handler;
    void               *data;
    char               *action;
};

ngx_log_t *ngx_log_init(u_char *prefix);
//ngx_log_t *ngx_log_create(ngx_cycle_t *cycle, ngx_str_t *name);

void ngx_log_error_core(ngx_uint_t level, ngx_log_t *log,  \
    ngx_err_t err, const char *fmt, ...);

#define ngx_log_error(level, log, args...) \
    if ((log)->log_level >= level) ngx_log_error_core(level, log, args)
#define ngx_log_debug(level, log, args...) \
    if ((log)->log_level >= level && level) \
        ngx_log_error_core(NGX_LOG_DEBUG, log, args) \

#endif

