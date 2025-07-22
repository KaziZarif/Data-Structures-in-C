#ifndef LISTQUEUE_H
#define LISTQUEUE_H

#include <stdbool.h>

typedef struct node {
    int value;
    struct node* next;
} Node;

typedef struct queue {
    Node* front;
    Node* back;
} ListQueue;


ListQueue* queue_init();
int queue_front(ListQueue* q);
void queue_enqueue(ListQueue* q, int value);
bool queue_dequeue(ListQueue* q, int* result);
bool queue_is_empty(ListQueue* q);
void queue_destroy(ListQueue* q);


#endif