// Chapter 7, slides 7-40 .. 7-42: recognizing palindromes with a stack and a queue.
// Put every character into both. The stack gives them back reversed,
// the queue gives them back in order. If every pair matches, it is a palindrome.
#include <iostream>
#include <string>
using namespace std;

typedef char ItemType;

// Pointer-based stack and queue from 06 and 09, trimmed to what this needs.
class Stack {
public:
    Stack() : topPtr(nullptr) {}
    ~Stack() { ItemType x; while (pop(x)) {} }
    Stack(const Stack&) = delete;
    Stack& operator=(const Stack&) = delete;

    void push(ItemType newItem) { topPtr = new Node{newItem, topPtr}; }

    bool pop(ItemType& stackTop) {
        if (topPtr == nullptr) {
            return false;
        }
        Node* temp = topPtr;
        stackTop = temp->item;
        topPtr = temp->next;
        delete temp;
        return true;
    }

private:
    struct Node {
        ItemType item;
        Node* next;
    };
    Node* topPtr;
};

class Queue {
public:
    Queue() : backPtr(nullptr), frontPtr(nullptr) {}
    ~Queue() { ItemType x; while (dequeue(x)) {} }
    Queue(const Queue&) = delete;
    Queue& operator=(const Queue&) = delete;

    bool isEmpty() const { return backPtr == nullptr; }

    void enqueue(ItemType newItem) {
        Node* newPtr = new Node{newItem, nullptr};
        if (isEmpty()) {
            frontPtr = newPtr;
        } else {
            backPtr->next = newPtr;
        }
        backPtr = newPtr;
    }

    bool dequeue(ItemType& queueFront) {
        if (isEmpty()) {
            return false;
        }
        Node* temp = frontPtr;
        queueFront = temp->item;
        frontPtr = temp->next;
        if (frontPtr == nullptr) {     // removed the only node
            backPtr = nullptr;
        }
        delete temp;
        return true;
    }

private:
    struct Node {
        ItemType item;
        Node* next;
    };
    Node* backPtr;
    Node* frontPtr;
};

bool isPalindrome(const string& str) {
    Stack aStack;
    Queue aQueue;
    for (char ch : str) {              // insert each character into both
        aStack.push(ch);
        aQueue.enqueue(ch);
    }

    ItemType queueFront, stackTop;
    while (aQueue.dequeue(queueFront)) {
        aStack.pop(stackTop);
        if (queueFront != stackTop) {
            return false;              // destructors free what is left
        }
    }
    return true;
}

int main() {
    string tests[] = {"abcbd", "abcba", "radar", "hello", "abba", "a", ""};
    for (const string& t : tests) {
        cout << "\"" << t << "\" -> " << (isPalindrome(t) ? "palindrome" : "not palindrome") << endl;
    }
    // abcbd not, abcba yes, radar yes, hello not, abba yes, a yes, "" yes
    return 0;
}
