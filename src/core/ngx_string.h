#ifndef _NGX_STRING_H_INCLUDED_
#define _NGX_STRING_H_INCLUDED_


#include <ngx_config.h>


typedef struct {
    int   len;
    char *data;
} ngx_str_t;

#define ngx_snprintf              snprintf
#define ngx_vsnprintf             vsnprintf

#define ngx_memcpy(dst, src, n)   memcpy(dst, src, n)
#define ngx_cpymem(dst, src, n)   memcpy(dst, src, n) + n

char *ngx_cpystrn(char *dst, char *src, size_t n);


#endif /* _NGX_STRING_H_INCLUDED_ */
