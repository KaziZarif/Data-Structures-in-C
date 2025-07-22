# Data Structures in C

This repository contains implementations of fundamental data structures in the C programming language. 

## Current Structures

- **Binary Search Tree (BST)**: Unbalanced BST supporting insert, search, and destroy operations.
- **AVL Tree**: Self-balancing binary search tree supporting insert, search, and destroy operations using height-based rotations.
- **Semaphore (Custom)**: User-space counting semaphore built using `pthread_mutex_t` and `pthread_cond_t`, with `sem_init`, `sem_wait`, and `sem_post` operations.
- **Min Priority Queue (Linked List)**: Priority queue implemented using a singly linked list, where the element with the smallest priority is always dequeued first. Supports enqueue (priority-based insertion), dequeue, peek (front), and destroy operations.

## Future Additions

- Stack
- Queue
- Hash Table