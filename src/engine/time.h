
#pragma once


#ifdef _WIN32

    #include <windows.h>

    #define time_sleep_ms(t) Sleep(t)

#else

    #include <unistd.h>

    #define time_sleep_ms(t) usleep(t * 1000)

#endif


