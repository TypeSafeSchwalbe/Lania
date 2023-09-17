
#pragma once

#include <stdlib.h>


typedef struct Vector {
    size_t size;
    size_t malloc_size;
    size_t item_size;
    char* content;
} Vector;

Vector vector_new(size_t item_size);

void vector_push(Vector* v, void* item);

void vector_pop(Vector* v);

void* vector_get(Vector* v, size_t index);

void vector_set(Vector* v, size_t index, void* item);

void vector_free(Vector* v);