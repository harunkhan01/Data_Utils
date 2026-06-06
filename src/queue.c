#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>

#include "queue.h"

struct Q *init_q(size_t ele_size){
    struct Q *q = malloc(sizeof(struct Q));

    q->size = 0;
    q->ele_size = ele_size;
    q->front = malloc(sizeof(struct Node));
    q->back = q->front;

    q->front->next = NULL;
    q->front->data = NULL;

    return q;
}

void append_queue(struct Q *q, void *val){
    if (q->size > MAX_QUEUE_SIZE){
        printf("Unreasonable amount of memory requested. Exiting...\n");
        exit(0);
    }

    struct Node *new_node = malloc(sizeof(struct Node));
    new_node->data = malloc(sizeof(q->ele_size));
    memcpy(new_node->data, val, q->ele_size);

    /* We add to the back */
    if (q->front->next == NULL){
        q->back = new_node;
        q->front->next = q->back;
    } else {
        q->back->next = new_node;
        q->back = new_node;
    }

    q->size++;
}

void print_queue(struct Q *q){
    if (q->size == 0){
        printf("Queue is all empty. Extiting!\n");
        exit(1);
    }

    /* Treat the data as chars */
    char *data;

    struct Node *tmp = q->front->next;
    while (tmp != NULL){
        data = tmp->data;
        for (int i=0; i < q->ele_size; i++){
            printf("%c", data[i]);
        }
        tmp = tmp->next;
    }

    printf("\n");
}