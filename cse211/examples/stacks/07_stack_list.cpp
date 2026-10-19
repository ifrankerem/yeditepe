// Chapter 6, slides 6-33 .. 6-43: Stack built on the ADT List.
// Position 1 of the list is the top of the stack:
//   push   -> insert(1, item)
//   pop    -> remove(1)
//   getTop -> retrieve(1, item)
// List already has a copy constructor and destructor, so Stack's are empty.
#include <iostream>
#include "../linked_lists/ListP.h"
using namespace std;

typedef ListItemType StackItemType;

class Stack {
public:
    Stack();
    Stack(const Stack& aStack);
    ~Stack();

    bool isEmpty() const;
    bool push(StackItemType newItem);
    bool pop();
    bool pop(StackItemType& stackTop);
    bool getTop(StackItemType& stackTop) const;

private:
    List aList;                        // list of stack items
};

Stack::Stack() {
}

Stack::Stack(const Stack& aStack) : aList(aStack.aList) {
}

Stack::~Stack() {
}

bool Stack::isEmpty() const {
    return aList.isEmpty();
}

bool Stack::push(StackItemType newItem) {
    return aList.insert(1, newItem);
}

bool Stack::pop() {
    return aList.remove(1);
}

bool Stack::pop(StackItemType& stackTop) {
    if (aList.retrieve(1, stackTop)) {
        return aList.remove(1);
    }
    return false;
}

bool Stack::getTop(StackItemType& stackTop) const {
    return aList.retrieve(1, stackTop);
}

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);                        // 30 on top

    Stack copy(s);
    s.pop();

    StackItemType top;
    s.getTop(top);
    cout << "s top:    " << top << endl;   // 20
    copy.getTop(top);
    cout << "copy top: " << top << endl;   // 30

    cout << "Popping copy: ";
    while (copy.pop(top)) {
        cout << top << " ";            // 30 20 10
    }
    cout << endl;
    return 0;
}
