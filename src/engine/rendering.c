
#include <stdio.h>
#include <limits.h>
#include <string.h>

#include "rendering.h"
#include "console.h"


RenderBuffer make_buffer(unsigned short width, unsigned short height) {
    RenderBuffer new;
    new.width = width;
    new.height = height;
    new.char_data = malloc(sizeof(char[RENDER_BUFFER_CHAR_BUFFER_SIZE]) * new.width * new.height);
    new.depth_data = malloc(sizeof(short) * new.width * new.height);
    for(unsigned short y = 0; y < new.height; y += 1) {
        for(unsigned short x = 0; x < new.width; x += 1) {
            strcpy(new.char_data[new.width * y + x], " ");
            new.depth_data[new.width * y + x] = SHRT_MIN;
        }
    }
    return new;
}

void clear_buffer(RenderBuffer* b) {
    for(unsigned short y = 0; y < b->height; y += 1) {
        for(unsigned short x = 0; x < b->width; x += 1) {
            strcpy(b->char_data[b->width * y + x], " ");
            b->depth_data[b->width * y + x] = SHRT_MIN;
        }
    }
}

void write_onto_buffer(RenderBuffer* b, signed int x, signed int y, const char* c, signed short depth) {
    if(x < 0 || x >= b->width) { return; }
    if(y < 0 || y >= b->height) { return; }
    if(c == NULL) { return; }
    if(b->depth_data[b->width * y + x] > depth) { return; }
    strcpy(b->char_data[b->width * y + x], c);
    b->depth_data[b->width * y + x] = depth;
}

void write_line_onto_buffer(RenderBuffer* buffer, signed int dest_x, signed int dest_y, const char* char_prefix, const char* text, const char* char_postfix, size_t length, signed short depth) {
    size_t char_prefix_length = strlen(char_prefix);
    char char_buffer[char_prefix_length + 1 + strlen(char_postfix) + 1];
    strcpy(char_buffer, char_prefix);
    strcpy(char_buffer + char_prefix_length + 1, char_postfix);
    for(size_t c = 0; c < length; c += 1) {
        char_buffer[char_prefix_length] = text[c];
        write_onto_buffer(buffer, dest_x + c, dest_y, char_buffer, depth);
    }
}

void print_buffer(RenderBuffer* b) {
    for(unsigned short y = 0; y < b->height; y += 1) {
        for(unsigned short x = 0; x < b->width; x += 1) {
            printf(b->char_data[b->width * y + x]);
        }
        printf("\n");
    }
}

void free_buffer(RenderBuffer* b) {
    free(b->char_data);
    free(b->depth_data);
}


void render_object(RenderBuffer* dest, const RenderObject* o, signed int anchor_x, signed int anchor_y) {
    for(signed short y = 0; y < o->height; y += 1) {
        signed int dy = anchor_y - o->anchor_y + y;
        for(signed short x = 0; x < o->width; x += 1) {
            signed int dx = anchor_x - o->anchor_x + x;
            write_onto_buffer(dest, dx, dy, o->data[y][x], anchor_y);
        }
    }
}