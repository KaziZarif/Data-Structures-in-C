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

void queue_enqueue(ListQueue* q, int value) {
    if (q == NULL) return;

    Node* new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return;
    }
    new_node->value = value;
    new_node->next = NULL;

    if (q->front == NULL) {
        q->front = new_node;
        q->back = new_node;
    } else {
        q->back->next = new_node;
        q->back = new_node;
    }
}

bool queue_dequeue(ListQueue* q, int* result) {
    if (q == NULL || q->front == NULL || result == NULL) return false;

    *result = q->front->value;
    
    Node* temp = q->front;
    if (q->front == q->back) {
        q->front = NULL;
        q->back = NULL;
    } else {
        q->front = q->front->next;
    }
    free(temp);
    return true;
}


bool queue_is_empty(ListQueue* q) {
    if (q == NULL || q->front == NULL) return true;
    return false;
}

// After calling queue_destroy(q), the caller must also call free(q)
void queue_destroy(ListQueue* q) {
    if (q == NULL) return;
    Node* current = q->front;
    while (current != NULL) {
        Node* temp = current->next;
        free(current);
        current = temp;
    }
    q->front = NULL;
    q->back = NULL;
}