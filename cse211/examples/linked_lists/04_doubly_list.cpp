// Chapter 4, slides 4-37 .. 4-41: circular doubly linked list with a dummy head node.
// The dummy head is always there, even when the list is empty, so
// insert and delete have no special cases for the first or last node.
#include <iostream>
using namespace std;

struct DNode {
    int item;
    DNode* precede;
    DNode* next;
};

// Empty list (figure 4.29 b): the dummy head points to itself both ways.
DNode* createList() {
    DNode* head = new DNode{0, nullptr, nullptr};
    head->precede = head;
    head->next = head;
    return head;
}

// Insert a new node before cur (slide 4-41).
void insertBefore(DNode* cur, int value) {
    DNode* newPtr = new DNode{value, nullptr, nullptr};
    newPtr->next = cur;
    newPtr->precede = cur->precede;
    cur->precede = newPtr;
    newPtr->precede->next = newPtr;
}

// Delete the node cur points to (slide 4-41). cur must not be the dummy head.
void deleteNode(DNode* cur) {
    cur->precede->next = cur->next;
    cur->next->precede = cur->precede;
    delete cur;
}

void pushBack(DNode* head, int value) {
    insertBefore(head, value);         // before the dummy = at the end
}

void pushFront(DNode* head, int value) {
    insertBefore(head->next, value);   // before the first real node
}

DNode* findValue(DNode* head, int value) {
    for (DNode* cur = head->next; cur != head; cur = cur->next) {
        if (cur->item == value) {
            return cur;
        }
    }
    return nullptr;
}

void displayForward(DNode* head) {
    for (DNode* cur = head->next; cur != head; cur = cur->next) {
        cout << cur->item << " ";
    }
    cout << endl;
}

void displayBackward(DNode* head) {
    for (DNode* cur = head->precede; cur != head; cur = cur->precede) {
        cout << cur->item << " ";
    }
    cout << endl;
}

void freeList(DNode* head) {
    while (head->next != head) {
        deleteNode(head->next);
    }
    delete head;                       // the dummy goes last
}

int main() {
    DNode* head = createList();

    pushBack(head, 20);
    pushBack(head, 30);
    pushFront(head, 10);
    pushBack(head, 40);
    cout << "Forward:  ";
    displayForward(head);              // 10 20 30 40
    cout << "Backward: ";
    displayBackward(head);             // 40 30 20 10

    deleteNode(findValue(head, 30));   // middle
    insertBefore(findValue(head, 40), 35);
    cout << "Delete 30, insert 35 before 40: ";
    displayForward(head);              // 10 20 35 40

    deleteNode(findValue(head, 10));   // first node: same code, no special case
    deleteNode(findValue(head, 40));   // last node: same code, no special case
    cout << "Delete first and last: ";
    displayForward(head);              // 20 35

    freeList(head);
    return 0;
}
