// Chapter 6, slides 6-9 .. 6-12: checking for balanced braces with a stack.
//   '{' -> push
//   '}' -> pop a matching '{'; if the stack is empty, there is no match
//   end -> balanced only if the stack is empty
#include <iostream>
#include <string>
using namespace std;

typedef char StackItemType;

// Pointer-based stack from 06_stack_pointer.cpp, trimmed to what this needs.
class Stack {
public:
    Stack() : topPtr(nullptr) {}
    ~Stack() { while (pop()) {} }
    Stack(const Stack&) = delete;
    Stack& operator=(const Stack&) = delete;

    bool isEmpty() const { return topPtr == nullptr; }

    bool push(StackItemType newItem) {
        topPtr = new StackNode{newItem, topPtr};
        return true;
    }

    bool pop() {
        if (isEmpty()) {
            return false;
        }
        StackNode* temp = topPtr;
        topPtr = topPtr->next;
        delete temp;
        return true;
    }

private:
    struct StackNode {
        StackItemType item;
        StackNode* next;
    };
    StackNode* topPtr;
};

bool isBalanced(const string& aString) {
    Stack aStack;
    bool balancedSoFar = true;
    size_t i = 0;

    while (balancedSoFar && i < aString.length()) {
        char ch = aString[i];
        ++i;

        if (ch == '{') {               // push an open brace
            aStack.push('{');
        } else if (ch == '}') {        // close brace
            if (!aStack.isEmpty()) {
                aStack.pop();          // pop a matching open brace
            } else {
                balancedSoFar = false; // no matching open brace
            }
        }
        // ignore all characters other than braces
    }
    return balancedSoFar && aStack.isEmpty();
}

int main() {
    string tests[] = {
        "abc{defg{ijk}{l{mn}}op}qr",   // balanced (slide example)
        "abc{def}}{ghij{kl}m",         // unbalanced: '}' with no '{' (slide example)
        "{{}",                         // unbalanced: a '{' is left on the stack
        "no braces",                   // balanced
    };

    for (const string& t : tests) {
        cout << (isBalanced(t) ? "balanced    " : "unbalanced  ") << t << endl;
    }
    return 0;
}
