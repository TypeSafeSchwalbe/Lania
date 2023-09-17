
#pragma once

#include <stdlib.h>


#define RENDER_BUFFER_CHAR_BUFFER_SIZE 16

typedef struct RenderBuffer {
    char (*char_data)[RENDER_BUFFER_CHAR_BUFFER_SIZE];
    signed short* depth_data;
    unsigned short width;
    unsigned short height;
} RenderBuffer;

RenderBuffer make_buffer(unsigned short width, unsigned short height);

void clear_buffer(RenderBuffer* b);

void write_onto_buffer(RenderBuffer* b, signed int x, signed int y, const char* c, signed short depth);

void write_line_onto_buffer(RenderBuffer* buffer, signed int dest_x, signed int dest_y, const char* char_prefix, const char* text, const char* char_postfix, size_t length, signed short depth);

void print_buffer(RenderBuffer* b);

void free_buffer(RenderBuffer* b);


typedef struct RenderObject {
    char*** data;
    unsigned char width;
    unsigned char height;
    signed char anchor_x;
    signed char anchor_y;
} RenderObject;

void render_object(RenderBuffer* dest, const RenderObject* o, signed int anchor_x, signed int anchor_y);