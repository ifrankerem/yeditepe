// Chapter 6, slides 6-23 .. 6-32: pointer-based Stack.
// topPtr is the head of a linked list. push = insert at front, pop = delete front.
// Nodes are dynamic, so a copy constructor and a destructor are required.
#include <iostream>
using namespace std;

typedef int StackItemType;

class Stack {
public:
    Stack();
    Stack(const Stack& aStack);
    ~Stack();
    // Not on the slides: the compiler's assignment would share nodes (double delete).
    Stack& operator=(const Stack&) = delete;

    bool isEmpty() const;
    bool push(StackItemType newItem);
    bool pop();
    bool pop(StackItemType& stackTop);
    bool getTop(StackItemType& stackTop) const;

private:
    struct StackNode {
        StackItemType item;
        StackNode* next;
    };
    StackNode* topPtr;                 // pointer to first node in the stack
};

Stack::Stack() : topPtr(nullptr) {
}

// Deep copy: same order, new nodes (slide 6-26).
Stack::Stack(const Stack& aStack) {
    if (aStack.topPtr == nullptr) {
        topPtr = nullptr;
    } else {
        topPtr = new StackNode;        // copy first node
        topPtr->item = aStack.topPtr->item;

        StackNode* newPtr = topPtr;    // copy rest of stack
        for (StackNode* origPtr = aStack.topPtr->next; origPtr != nullptr; origPtr = origPtr->next) {
            newPtr->next = new StackNode;
            newPtr = newPtr->next;
            newPtr->item = origPtr->item;
        }
        newPtr->next = nullptr;
    }
}

Stack::~Stack() {
    while (!isEmpty()) {
        pop();
    }
}

bool Stack::isEmpty() const {
    return topPtr == nullptr;
}

bool Stack::push(StackItemType newItem) {
    StackNode* newPtr = new StackNode;
    newPtr->item = newItem;
    newPtr->next = topPtr;
    topPtr = newPtr;
    return true;                       // never full
}

bool Stack::pop() {
    if (isEmpty()) {
        return false;
    }
    StackNode* temp = topPtr;
    topPtr = topPtr->next;
    temp->next = nullptr;              // safeguard
    delete temp;
    return true;
}

bool Stack::pop(StackItemType& stackTop) {
    if (isEmpty()) {
        return false;
    }
    stackTop = topPtr->item;
    return pop();
}

bool Stack::getTop(StackItemType& stackTop) const {
    if (isEmpty()) {
        return false;
    }
    stackTop = topPtr->item;
    return true;
}

int main() {
    Stack s;
    for (int i = 1; i <= 3; i++) {
        s.push(i);                     // 1 2 3 (3 on top)
    }

    Stack copy(s);                     // copy constructor
    s.pop();                           // only s loses 3

    StackItemType top;
    s.getTop(top);
    cout << "s top:    " << top << endl;   // 2
    copy.getTop(top);
    cout << "copy top: " << top << endl;   // 3

    cout << "Popping copy: ";
    while (copy.pop(top)) {
        cout << top << " ";            // 3 2 1
    }
    cout << endl;
    return 0;                          // destructor frees what is left in s
}
