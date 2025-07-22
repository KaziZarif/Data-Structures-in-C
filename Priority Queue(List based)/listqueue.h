#ifndef LISTQUEUE_h
#define LISTQUEUE_h

#include <stdbool.h>

typedef struct node {
    int value;
    struct node* next;
} Node;

typedef struct queue {
    Node* front;
    Node* back;
} ListQueue;


ListQueue* list_init();
void queue_enqueue(ListQueue* q, int value);
bool queue_dequeue(ListQueue* q, int* result);
bool queue_is_empty(ListQueue* q);
void queue_destroy(ListQueue* q);


#endif