#ifndef _NGX_CONFIG_H__INCLUDED_
#define _NGX_CONFIG_H__INCLUDED_

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef intptr_t        ngx_int_t;
typedef intptr_t        ngx_flag_t;
typedef uintptr_t       ngx_uint_t;

typedef ngx_uint_t      ngx_atomic_uint_t;
typedef ngx_uint_t      ngx_err_t;

#define NGX_INT32_LEN   sizeof("-2147483648") - 1
#define NGX_INT64_LEN   sizeof("-9223372036854775808") - 1

#define ngx_stdin           0
#define ngx_stdout          1
#define ngx_stderr          2

#define NGX_ERROR_LOG_PATH ""

#endif
