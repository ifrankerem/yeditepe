#ifndef NODE_H
#define NODE_H

// Singly linked list node (same as lab2).
struct Node {
    int data;
    Node* next;
};

// Doubly linked list node (slides call prev "precede").
struct DNode {
    int data;
    DNode* prev;
    DNode* next;
};

#endif
