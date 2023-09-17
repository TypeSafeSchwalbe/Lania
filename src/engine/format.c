
#include "format.h"


char* format(AllocHandler alloc_handler, const char* fmt, ...) {
    va_list argp;
    va_start(argp, fmt);
    size_t result_size = vsnprintf(NULL, 0, fmt, argp);
    va_start(argp, fmt);
    char* result = (char*) (alloc_handler)(sizeof(char) * result_size + 1);
    vsprintf(result, fmt, argp);
    return result;
}