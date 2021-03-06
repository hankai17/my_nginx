cmake_minimum_required(VERSION 3.13)
project(my_nginx C)

set(CMAKE_C_STANDARD 11)

include_directories(src/core)
include_directories(src/event)
include_directories(src/event/modules)
include_directories(src/http)
include_directories(src/http/modules)
include_directories(src/os/unix)
#include_directories(src/os/unix/freebsd)

add_executable(my_nginx
        src/core/nginx.c
        src/core/nginx.h
        src/core/ngx_alloc.c
        src/core/ngx_alloc.h
        src/core/ngx_array.c
        src/core/ngx_array.h
        src/core/ngx_auto_config.h
        src/core/ngx_config.h
        src/core/ngx_config_command.c
        src/core/ngx_config_command.h
        src/core/ngx_connection.h
        src/core/ngx_core.h
        src/core/ngx_file.h
        src/core/ngx_hunk.c
        src/core/ngx_hunk.h
        src/core/ngx_listen.c
        src/core/ngx_listen.h
        src/core/ngx_log.c
        src/core/ngx_log.h
        src/core/ngx_server.h
        src/core/ngx_string.c
        src/core/ngx_string.h
        src/core/ngx_table.h
        src/event/modules/ngx_select_module.c
        src/event/modules/ngx_select_module.h
        src/event/ngx_event.c
        src/event/ngx_event.h
        src/event/ngx_event_accept.c
        src/event/ngx_event_accept.h
        src/event/ngx_event_close.c
        src/event/ngx_event_close.h
        src/event/ngx_event_mutex.c
        src/event/ngx_event_recv.c
        src/event/ngx_event_write.c
        src/event/ngx_event_write.h
        src/http/modules/ngx_http_event_proxy_handler.c
        src/http/modules/ngx_http_event_proxy_handler.h
        src/http/modules/ngx_http_index_handler.c
        src/http/modules/ngx_http_index_handler.h
        #src/http/modules/ngx_http_ssi_filter.c
        src/http/modules/ngx_http_static_handler.c
        src/http/ngx_http.c
        src/http/ngx_http.h
        src/http/ngx_http_config.c
        src/http/ngx_http_config.h
        src/http/ngx_http_core.c
        src/http/ngx_http_core.h
        src/http/ngx_http_event.c
        src/http/ngx_http_get_time.c
        src/http/ngx_http_header.h
        src/http/ngx_http_header_filter.c
        src/http/ngx_http_modules.c
        src/http/ngx_http_output_filter.c
        src/http/ngx_http_output_filter.h
        src/http/ngx_http_parse.c
        src/http/ngx_http_write_filter.c
        src/http/ngx_http_write_filter.h
        src/os/unix/ngx_errno.h
        src/os/unix/ngx_files.c
        src/os/unix/ngx_files.h
        src/os/unix/ngx_recv.h
        src/os/unix/ngx_sendfile.h
        src/os/unix/ngx_sendv.c
        src/os/unix/ngx_sendv.h
        src/os/unix/ngx_socket.h
        src/os/unix/ngx_time.c
        src/os/unix/ngx_time.h
        src/os/unix/ngx_types.h)
