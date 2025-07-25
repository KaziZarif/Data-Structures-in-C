#ifndef LISTQUEUE_H
#define LISTQUEUE_H

#include <stdbool.h>

typedef struct node {
    int value;
    int priority;
    struct node* next;
} Node;

typedef struct queue {
    Node* front;
    Node* back;
} ListQueue;


ListQueue* queue_init();
bool queue_front(ListQueue* q, int* result);
void queue_enqueue(ListQueue* q, int value, int priority);
bool queue_dequeue(ListQueue* q, int* result);
bool queue_is_empty(ListQueue* q);
void queue_destroy(ListQueue* q);


#endif