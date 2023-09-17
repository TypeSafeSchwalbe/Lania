
#pragma once


void console_init();

void console_clear();

int console_width();

int console_height();

char* console_read_line();

int console_read_char();

void console_set_raw(char enabled);
