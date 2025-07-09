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

void list_remove(node** head, node* n) {
    if (head == NULL || *head == NULL || n == NULL) {
        return;
    }

    if (*head == n) {
        if (n->next == n) {
            free(n);
            *head = NULL;
        } else {
            node* tail = n->prev;
            
            tail->next = n->next;
            n->next->prev = tail;
            *head = n->next;
            free(n);
        }
    } else {
        n->next->prev = n->prev;
        n->prev->next = n->next;
        free(n);
    }
}

void list_free(node** head) {
    if (head == NULL || *head == NULL) return;

    node* current = *head;
    node* next;
    do {
        next = current->next;
        free(current);
        current = next;
    } while (current != *head);
    *head = NULL;
}