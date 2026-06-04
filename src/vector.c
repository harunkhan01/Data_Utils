#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stddef.h>

#include "vector.h"


struct vector *init_vec(size_t ele_size){
    struct vector *vec = malloc(sizeof(struct vector));
    vec->size = 0;
    vec->capacity = 2;
    vec->ele_size = ele_size;
    vec->data = malloc(ele_size * vec->capacity);

    return vec;
}

void resize_vec(struct vector *vec){
    size_t new_capacity = vec->capacity * RESIZING_RATE;

    if (new_capacity * vec->ele_size > MAX_VECTOR_SIZE){
        printf("Unreasonable memory request for vector. Exiting...\n");
        exit(0);
    }

    vec->data = realloc(vec->data, new_capacity * sizeof(vec->ele_size));

    vec->capacity = new_capacity;

    if (vec->data == NULL){
        printf("Memory allocation failure.\n");
        exit(0);
    }
}

void append_vec(struct vector *vec, void *value){
    if (vec->size == vec->capacity){
        resize_vec(vec);
    }

    uint8_t *dst = (uint8_t *)vec->data + vec->size * vec->ele_size;

    /* We use memcpy because its OP */
    memcpy(dst, value, vec->ele_size);

    vec->size++;
}

/* Consider realloc if the size is less than 1/4 capacity */
void pop_vec(struct vector *vec){
    if (vec->size > 0){
        vec->size--;
    }
}

void insert_vec(struct vector *vec, void *value, size_t index){
    /* Copy all values down one -- O(N) */
    if (vec->size == vec->capacity){
        resize_vec(vec);
    }

    if (index == vec->size){
        append_vec(vec, value);
        return;
    } else if (index > vec->size){
        printf("Attempted to insert at invalid index. Exiting...\n");
        exit(0);
    }

    size_t bound = vec->size * vec->ele_size;

    uint8_t *dst = (uint8_t *)vec->data + bound;

    for (size_t i = bound; i > index * vec->ele_size; i -= vec->ele_size){
        memcpy(dst, dst - vec->ele_size, vec->ele_size);
        dst -= vec->ele_size;
    }

    memcpy(dst, value, vec->ele_size);

    vec->size++;
}

void print_vec(struct vector *vec){
    /* We treat the vector data as chars */

    size_t bound = vec->size * vec->ele_size;

    char *data = vec->data;

    for (size_t i=0; i < bound; i++){
        printf("%c", data[i]);
    }

    printf("\n");
}