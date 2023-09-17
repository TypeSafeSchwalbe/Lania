
#include <stdlib.h>
#include <stdio.h>

#include "console.h"


void console_clear() {
    printf("\033[H\033[J");
}


#ifdef _WIN32

    #include <windows.h>

    void console_init() {
        HANDLE in = GetStdHandle(STD_INPUT_HANDLE);
        HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
        DWORD mode;
        GetConsoleMode(in, &mode);
        mode |= ENABLE_VIRTUAL_TERMINAL_INPUT;
        SetConsoleMode(in, mode);
        GetConsoleMode(out, &mode);
        mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
        SetConsoleMode(out, mode);
    }

    int console_width() {
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        return csbi.srWindow.Right - csbi.srWindow.Left + 1;
    }

    int console_height() {
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        return csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    }

    void console_set_raw(char enabled) {
        HANDLE in = GetStdHandle(STD_INPUT_HANDLE);
        DWORD mode;
        GetConsoleMode(in, &mode);
        if(enabled) {
            mode &= ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT);
        } else {
            mode |= ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT;
        }
        SetConsoleMode(in, mode);
    }

#else

    #include <sys/ioctl.h>
    #include <unistd.h>
    #include <termios.h>

    void console_init() {}

    int console_width() {
        struct winsize w;
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
        return w.ws_col;
    }

    int console_height() {
        struct winsize w;
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
        return w.ws_row;
    }

    void console_set_raw(char enabled) {
        struct termios t;
        tcgetattr(STDIN_FILENO, &t);
        if(enabled) {
            t.c_lflag &= ~(ECHO | ICANON);
        } else {
            t.c_lflag |= ECHO | ICANON;
        }
        tcsetattr(STDIN_FILENO, TCSAFLUSH, &t);
    }

#endif


char* console_read_line() {
    int content_ms = 64;
    char* content = malloc(content_ms + 1);
    int ci = 0;
    for(;;) {
        int c = console_read_char();
        if(c == EOF || c == '\n') { break; }
        if(ci >= content_ms) {
            content_ms *= 2;
            content = realloc(content, content_ms + 1);
        }
        content[ci] = c;
        ci += 1;
    }
    content = realloc(content, ci + 1);
    content[ci] = '\0';
    return content;
}

int console_read_char() {
    int c = fgetc(stdin);
    return c == '\r'? '\n' : c;
}