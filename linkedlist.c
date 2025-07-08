#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;

struct node {
    int data;
    Node* next;
};

Node* list_init(int value) {
    Node* head = malloc(sizeof(Node));
    if (head == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    head->data = value;
    head->next = NULL;
    
    return head;
}

void list_add(struct node** head, int value) {
    Node* new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    new_node->data = value;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
} 

void list_delete(struct node** head, struct node* n) {
    if (*head == NULL || n == NULL) {
        return;
    }

    if (*head == n) {
        *head = n->next;
        free(n);
        return;
    }
    Node* temp = *head;
    while (temp != NULL && temp->next != n) {
        temp = temp->next;
    }
    if (temp == NULL) {
        return;
    }
    temp->next = n->next;
    free(n);
}