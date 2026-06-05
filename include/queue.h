#ifndef QUEUE_H
#define QUEUE_H

#include <stddef.h>

struct Node {
    void *data;
    struct Node *next;
};

struct Q {
    size_t size;
    size_t ele_size;
    struct Node *front;
    struct Node *back;
}

/* Allow up 8 MB of usage */
#define MAX_QUEUE_SIZE 1 << 23

#endif