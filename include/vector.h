#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>

struct vector {
    size_t size;
    size_t capacity;
    size_t ele_size;
    void * data;
};

#define RESIZING_RATE 2

/* 8 MB Rough Memory Limit */
#define MAX_VECTOR_SIZE 1 << 23


struct vector *init_vec(size_t ele_size);
void resize_vec(struct vector *vec);
void append_vec(struct vector *vec, void *value);
void print_vec(struct vector *vec);

#endif