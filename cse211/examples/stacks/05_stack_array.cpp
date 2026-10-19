// Chapter 6, slides 6-15 .. 6-22: array-based Stack.
// top is the index of the top item; -1 means empty.
// No copy constructor or destructor needed: the array is not dynamic.
#include <iostream>
using namespace std;

const int MAX_STACK = 5;               // small on purpose, to show "stack full"
typedef int StackItemType;

class Stack {
public:
    Stack();
    bool isEmpty() const;
    bool push(StackItemType newItem);
    bool pop();
    bool pop(StackItemType& stackTop);
    bool getTop(StackItemType& stackTop) const;

private:
    StackItemType items[MAX_STACK];    // array of stack items
    int top;                           // index to top of stack
};

Stack::Stack() : top(-1) {
}

bool Stack::isEmpty() const {
    return top < 0;
}

bool Stack::push(StackItemType newItem) {
    if (top >= MAX_STACK - 1) {        // no room for another item
        return false;
    }
    ++top;
    items[top] = newItem;
    return true;
}

bool Stack::pop() {
    if (isEmpty()) {
        return false;
    }
    --top;
    return true;
}

bool Stack::pop(StackItemType& stackTop) {
    if (isEmpty()) {
        return false;
    }
    stackTop = items[top];
    --top;
    return true;
}

bool Stack::getTop(StackItemType& stackTop) const {
    if (isEmpty()) {
        return false;
    }
    stackTop = items[top];
    return true;
}

int main() {
    Stack s;
    cout << boolalpha;

    for (int i = 1; i <= 5; i++) {
        s.push(i * 10);                // 10 20 30 40 50 (50 on top)
    }
    cout << "push 60 ok? " << s.push(60) << endl;   // false: stack full

    StackItemType top;
    s.getTop(top);
    cout << "Top: " << top << endl;                 // 50

    s.pop();                                        // removes 50 without reading it
    cout << "Popping: ";
    while (s.pop(top)) {
        cout << top << " ";                         // 40 30 20 10 (LIFO)
    }
    cout << endl;

    cout << "Empty? " << s.isEmpty() << endl;       // true
    cout << "pop on empty ok? " << s.pop() << endl; // false
    return 0;
}
