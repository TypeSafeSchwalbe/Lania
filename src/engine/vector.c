
#include <string.h>

#include "vector.h"


Vector vector_new(size_t item_size) {
    Vector new;
    new.item_size = item_size;
    new.malloc_size = 16;
    new.size = 0;
    new.content = malloc(new.malloc_size * new.item_size);
    return new;
}

void vector_push(Vector* v, void* item) {
    v->size += 1;
    if(v->size > v->malloc_size) {
        v->malloc_size *= 2;
        v->content = realloc(v->content, v->malloc_size * v->item_size);
    }
    memcpy(v->content + (v->size - 1) * v->item_size, item, v->item_size);
}

void vector_pop(Vector* v) {
    v->size -= 1;
}

void* vector_get(Vector* v, size_t index) {
    return v->content + index * v->item_size;
}

void vector_set(Vector* v, size_t index, void* item) {
    memcpy(v->content + index * v->item_size, item, v->item_size);
}

void vector_free(Vector* v) {
    free(v->content);
}