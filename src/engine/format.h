
#pragma once

#include <stdarg.h>
#include <stdio.h>


typedef void* (*AllocHandler)(size_t alloc_size);

char* format(AllocHandler alloc_handler, const char* fmt, ...);


#define FORMAT(destv_name, lengthv_name, fmt, ...) \
    size_t lengthv_name = snprintf(NULL, 0, fmt, __VA_ARGS__); \
    char destv_name[sizeof(char) * lengthv_name + 1]; \
    sprintf(destv_name, fmt, __VA_ARGS__);
    