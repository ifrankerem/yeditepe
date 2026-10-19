// ADT List, pointer-based implementation (Chapter 4, slides 4-17 .. 4-28).
// Header-only, so every example still compiles with a single g++ command.
// Used by 02_list_adt.cpp, stacks/07_stack_list.cpp and queues/11_queue_list.cpp.
#ifndef LISTP_H
#define LISTP_H

typedef int ListItemType;

class List {
public:
    List();                      // default constructor
    List(const List& aList);     // copy constructor (deep copy)
    ~List();                     // destructor
    // Not on the slides: the compiler's assignment would copy only the head
    // pointer and both lists would delete the same nodes.
    List& operator=(const List&) = delete;

    bool isEmpty() const;
    int getLength() const;
    bool insert(int index, ListItemType newItem);
    bool remove(int index);
    bool retrieve(int index, ListItemType& dataItem) const;

private:
    struct ListNode {
        ListItemType item;
        ListNode* next;
    };

    int size;          // number of items in list
    ListNode* head;    // pointer to the first node

    ListNode* find(int index) const;   // pointer to the index-th node
};

inline List::List() : size(0), head(nullptr) {
}

inline List::List(const List& aList) : size(aList.size) {
    if (aList.head == nullptr) {
        head = nullptr;                // original list is empty
    } else {
        head = new ListNode;           // copy first node
        head->item = aList.head->item;

        ListNode* newPtr = head;       // copy rest of list
        for (ListNode* origPtr = aList.head->next; origPtr != nullptr; origPtr = origPtr->next) {
            newPtr->next = new ListNode;
            newPtr = newPtr->next;
            newPtr->item = origPtr->item;
        }
        newPtr->next = nullptr;
    }
}

inline List::~List() {
    while (!isEmpty()) {
        remove(1);
    }
}

inline bool List::isEmpty() const {
    return size == 0;
}

inline int List::getLength() const {
    return size;
}

// Positions start at 1. Returns nullptr if index is out of range.
inline List::ListNode* List::find(int index) const {
    if (index < 1 || index > getLength()) {
        return nullptr;
    }
    ListNode* cur = head;
    for (int skip = 1; skip < index; ++skip) {
        cur = cur->next;
    }
    return cur;
}

inline bool List::retrieve(int index, ListItemType& dataItem) const {
    if (index < 1 || index > getLength()) {
        return false;
    }
    dataItem = find(index)->item;
    return true;
}

// index can be 1 .. getLength()+1 (getLength()+1 means "at the end").
inline bool List::insert(int index, ListItemType newItem) {
    int newLength = getLength() + 1;
    if (index < 1 || index > newLength) {
        return false;
    }
    ListNode* newPtr = new ListNode;
    size = newLength;
    newPtr->item = newItem;
    if (index == 1) {                  // special case: new first node
        newPtr->next = head;
        head = newPtr;
    } else {
        ListNode* prev = find(index - 1);
        newPtr->next = prev->next;
        prev->next = newPtr;
    }
    return true;
}

inline bool List::remove(int index) {
    if (index < 1 || index > getLength()) {
        return false;
    }
    ListNode* cur;
    --size;
    if (index == 1) {                  // special case: delete first node
        cur = head;
        head = head->next;
    } else {
        ListNode* prev = find(index - 1);
        cur = prev->next;
        prev->next = cur->next;
    }
    cur->next = nullptr;
    delete cur;
    return true;
}

#endif
