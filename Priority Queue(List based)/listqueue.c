#include <stdio.h>
#include <stdlib.h>
#include "listqueue.h"

ListQueue* queue_init() {
    ListQueue* new_queue = malloc(sizeof(ListQueue));
    if (new_queue == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return NULL;
    }

    new_queue->front = NULL;
    new_queue->back = NULL;
    return new_queue;
}

bool queue_front(ListQueue* q, int* result) {
    if (q == NULL || q->front == NULL || result == NULL) {
        return false;
    } 
    *result = q->front->value;
    return true;
}

