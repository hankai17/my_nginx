#ifndef _NGX_STRING_H_INCLUDED
#define _NGX_STRING_H_INCLUDED

#include "ngx_config.h"

typedef struct {
    size_t      len;
    u_char     *data;
} ngx_str_t;

typedef struct {
    ngx_str_t   key;
    ngx_str_t   value;
} ngx_keyval_t;

#define ngx_tolower(c) (u_char) ((c >= 'A' && c <= 'Z') ? (c | 0x20) : c)
#define ngx_toupper(c) (u_char) ((c >= 'a' && c <= 'z') ? (c & ~0x20) : c)

#define ngx_strcmp(s1, s2) strcmp((const char*)s1, (const char*)s2)
#define ngx_strncmp(s1, s2, n) strncmp((const char*)s1, (const char*)s2, n)
#define ngx_strstr(s1, s2) strstr((const char*)s1, (const char*)s2)
#define ngx_strlen(s1) strlen((const char*)s1)
#define ngx_strchr(s1, c) strchr((const char*)s1, (int)c)

#define ngx_memzero(buf, n) (void)memset(buf, 0, n)
#define ngx_memset(buf, c, n) (void)memset(buf, c, n)
#define ngx_memcpy(dst, src, n) (void)memcpy(dst, src, n)
#define ngx_memmove(dst, src, n) (void)memmove(dst, src, n)
#define ngx_memcmp(s1, s2, n) memcmp((const char *)s1, (const char*)s2, n)


#endif

