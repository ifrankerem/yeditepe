// Chapter 4, slides 4-4 .. 4-14: node, traverse, insert, delete.
#include <iostream>
using namespace std;

struct Node {
    int item;
    Node* next;
};

// Traverse: cur visits every node (slide 4-7).
void displayList(Node* head) {
    for (Node* cur = head; cur != nullptr; cur = cur->next) {
        cout << cur->item << " ";
    }
    cout << endl;
}

// Insert at the beginning (slide 4-12).
void insertFront(Node*& head, int value) {
    Node* newPtr = new Node;
    newPtr->item = value;
    newPtr->next = head;
    head = newPtr;
}

// Insert into a sorted list (slides 4-11 .. 4-14).
// The for loop finds the insertion point; prev stays nullptr if the
// new node goes first. Inserting at the end works because cur is nullptr.
void insertSorted(Node*& head, int value) {
    Node* prev;
    Node* cur;
    for (prev = nullptr, cur = head; cur != nullptr && value > cur->item; prev = cur, cur = cur->next)
        ;

    Node* newPtr = new Node;
    newPtr->item = value;
    if (prev == nullptr) {             // new first node
        newPtr->next = head;
        head = newPtr;
    } else {                           // middle or end
        newPtr->next = cur;
        prev->next = newPtr;
    }
}

// Delete the first node that holds value (slides 4-9, 4-10).
bool deleteValue(Node*& head, int value) {
    Node* prev = nullptr;
    Node* cur = head;
    while (cur != nullptr && cur->item != value) {
        prev = cur;
        cur = cur->next;
    }
    if (cur == nullptr) {              // value not in list
        return false;
    }
    if (prev == nullptr) {             // deleting the first node
        head = head->next;
    } else {                           // deleting an interior or last node
        prev->next = cur->next;
    }
    cur->next = nullptr;               // return deleted node to system
    delete cur;
    return true;
}

void freeList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* head = nullptr;              // empty list: head is nullptr

    insertSorted(head, 30);            // into an empty list
    insertSorted(head, 10);            // at the beginning
    insertSorted(head, 50);            // at the end
    insertSorted(head, 20);            // in the middle
    insertSorted(head, 40);
    cout << "Sorted:          ";
    displayList(head);                 // 10 20 30 40 50

    insertFront(head, 5);
    cout << "Insert front 5:  ";
    displayList(head);                 // 5 10 20 30 40 50

    deleteValue(head, 5);              // first node
    deleteValue(head, 30);             // middle node
    deleteValue(head, 50);             // last node
    cout << "Delete 5 30 50:  ";
    displayList(head);                 // 10 20 40

    cout << boolalpha << "Delete 99 found? " << deleteValue(head, 99) << endl;  // false

    freeList(head);
    return 0;
}
