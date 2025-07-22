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