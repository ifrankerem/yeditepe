// Chapter 4, slides 4-34 .. 4-36: circular linked list.
// The external pointer "list" points to the LAST node, so
// list->next is the first node. Both ends are reachable in one step.
#include <iostream>
using namespace std;

struct Node {
    int item;
    Node* next;
};

void insertBack(Node*& list, int value) {
    Node* newPtr = new Node;
    newPtr->item = value;
    if (list == nullptr) {             // only node points to itself
        newPtr->next = newPtr;
    } else {
        newPtr->next = list->next;     // new node -> first
        list->next = newPtr;           // old last -> new node
    }
    list = newPtr;                     // new node is the last one
}

void insertFront(Node*& list, int value) {
    if (list == nullptr) {
        insertBack(list, value);
        return;
    }
    Node* newPtr = new Node;
    newPtr->item = value;
    newPtr->next = list->next;         // new node -> old first
    list->next = newPtr;               // last -> new node (list does not move)
}

// Display (slide 4-36). do-while because cur starts at first,
// and the loop must stop when it comes back to first.
void display(Node* list) {
    if (list != nullptr) {
        Node* first = list->next;
        Node* cur = first;
        do {
            cout << cur->item << " ";
            cur = cur->next;
        } while (cur != first);
    }
    cout << endl;
}

void freeList(Node*& list) {
    if (list == nullptr) {
        return;
    }
    Node* cur = list->next;            // first node
    list->next = nullptr;              // break the circle, then free like a normal list
    while (cur != nullptr) {
        Node* temp = cur;
        cur = cur->next;
        delete temp;
    }
    list = nullptr;
}

int main() {
    Node* list = nullptr;

    insertBack(list, 1);
    insertBack(list, 2);
    insertBack(list, 3);
    insertFront(list, 0);

    cout << "List:  ";
    display(list);                                       // 0 1 2 3
    cout << "Last:  " << list->item << endl;             // 3
    cout << "First: " << list->next->item << endl;       // 0
    cout << "After last comes: " << list->next->item << endl;  // 0 (no nullptr anywhere)

    freeList(list);
    cout << "Empty: ";
    display(list);                                       // (empty line)
    return 0;
}
