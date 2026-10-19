// Chapter 7, slides 7-10 .. 7-22: pointer-based Queue (linked list, front and back pointers).
// enqueue adds at backPtr, dequeue removes at frontPtr.
// Special cases:
//   enqueue into an empty queue  -> frontPtr must point to the new node too
//   dequeue the only node        -> frontPtr and backPtr both become nullptr
#include <iostream>
using namespace std;

typedef int QueueItemType;

class Queue {
public:
    Queue();
    Queue(const Queue& Q);
    ~Queue();
    // Not on the slides: the compiler's assignment would share nodes (double delete).
    Queue& operator=(const Queue&) = delete;

    bool isEmpty() const;
    bool enqueue(QueueItemType newItem);
    bool dequeue();
    bool dequeue(QueueItemType& queueFront);
    bool getFront(QueueItemType& queueFront) const;

private:
    struct QueueNode {
        QueueItemType item;
        QueueNode* next;
    };
    QueueNode* backPtr;
    QueueNode* frontPtr;
};

Queue::Queue() : backPtr(nullptr), frontPtr(nullptr) {
}

// Slides leave this "as an exercise": start empty, enqueue every item of Q in order.
Queue::Queue(const Queue& Q) : backPtr(nullptr), frontPtr(nullptr) {
    for (QueueNode* cur = Q.frontPtr; cur != nullptr; cur = cur->next) {
        enqueue(cur->item);
    }
}

Queue::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}

bool Queue::isEmpty() const {
    return backPtr == nullptr;
}

bool Queue::enqueue(QueueItemType newItem) {
    QueueNode* newPtr = new QueueNode;
    newPtr->item = newItem;
    newPtr->next = nullptr;

    if (isEmpty()) {                   // insertion into empty queue
        frontPtr = newPtr;
    } else {                           // insertion into nonempty queue
        backPtr->next = newPtr;
    }
    backPtr = newPtr;                  // new node is at back
    return true;
}

bool Queue::dequeue() {
    if (isEmpty()) {
        return false;
    }
    QueueNode* tempPtr = frontPtr;
    if (frontPtr == backPtr) {         // special case: only one node
        frontPtr = nullptr;
        backPtr = nullptr;
    } else {
        frontPtr = frontPtr->next;
    }
    tempPtr->next = nullptr;           // defensive strategy
    delete tempPtr;
    return true;
}

bool Queue::dequeue(QueueItemType& queueFront) {
    if (isEmpty()) {
        return false;
    }
    queueFront = frontPtr->item;
    return dequeue();
}

bool Queue::getFront(QueueItemType& queueFront) const {
    if (isEmpty()) {
        return false;
    }
    queueFront = frontPtr->item;
    return true;
}

int main() {
    Queue q;
    for (int i = 1; i <= 3; i++) {
        q.enqueue(i);                  // front 1 2 3 back
    }

    Queue copy(q);                     // copy constructor
    q.dequeue();                       // only q loses 1

    QueueItemType front;
    q.getFront(front);
    cout << "q front:    " << front << endl;   // 2
    copy.getFront(front);
    cout << "copy front: " << front << endl;   // 1

    cout << "Dequeue copy: ";
    while (copy.dequeue(front)) {
        cout << front << " ";          // 1 2 3 (FIFO)
    }
    cout << endl;

    // Special case: empty the queue, then use it again.
    Queue one;
    one.enqueue(7);
    one.dequeue();                     // front == back -> both become nullptr
    cout << boolalpha << "Empty after removing only item? " << one.isEmpty() << endl;  // true
    one.enqueue(8);                    // enqueue into empty queue sets frontPtr again
    one.getFront(front);
    cout << "Front after re-enqueue: " << front << endl;  // 8
    return 0;
}
