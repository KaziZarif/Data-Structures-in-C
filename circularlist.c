#include <stdio.h>
#include <stdlib.h>

typedef struct node node;
struct node {
    int data;
    node* prev;
    node* next;
};

node* list_init(int value) {
    node* head = malloc(sizeof(node));
    if (head == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    head->data = value;
    head->next = head;
    head->prev = head;
    return head;
}

void list_add(node** head, int value) {
    if (head == NULL) {
        return;
    }
    node* new_node = malloc(sizeof(node));
    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    new_node->data = value;

    if (*head == NULL) {
        *head = new_node;
        new_node->next = new_node;
        new_node->prev = new_node;
    } else {
        node* tail = (*head)->prev;
        
        tail->next = new_node;
        new_node->prev = tail;
        new_node->next = *head;
        (*head)->prev = new_node;
    }
}