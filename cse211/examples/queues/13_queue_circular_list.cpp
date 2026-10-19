// Chapter 7, slides 7-10, 7-11 (figure 7.4 b): Queue as a circular linked list with
// ONE external pointer, backPtr. The front is always backPtr->next.
// Described on the slides but not coded there.
#include <iostream>
using namespace std;

typedef int QueueItemType;

class Queue {
public:
    Queue();
    Queue(const Queue& Q);
    ~Queue();
    Queue& operator=(const Queue&) = delete;   // the default would share nodes

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
    QueueNode* backPtr;                // backPtr->next is the front
};

Queue::Queue() : backPtr(nullptr) {
}

Queue::Queue(const Queue& Q) : backPtr(nullptr) {
    if (Q.backPtr == nullptr) {
        return;
    }
    QueueNode* first = Q.backPtr->next;
    QueueNode* cur = first;
    do {                               // walk once around the circle
        enqueue(cur->item);
        cur = cur->next;
    } while (cur != first);
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
    if (isEmpty()) {                   // only node points to itself
        newPtr->next = newPtr;
    } else {
        newPtr->next = backPtr->next;  // new node -> front
        backPtr->next = newPtr;        // old back -> new node
    }
    backPtr = newPtr;                  // new node is the back
    return true;
}

bool Queue::dequeue() {
    if (isEmpty()) {
        return false;
    }
    QueueNode* frontPtr = backPtr->next;
    if (frontPtr == backPtr) {         // special case: only one node
        backPtr = nullptr;
    } else {
        backPtr->next = frontPtr->next;   // back skips over the old front
    }
    frontPtr->next = nullptr;
    delete frontPtr;
    return true;
}

bool Queue::dequeue(QueueItemType& queueFront) {
    if (isEmpty()) {
        return false;
    }
    queueFront = backPtr->next->item;
    return dequeue();
}

bool Queue::getFront(QueueItemType& queueFront) const {
    if (isEmpty()) {
        return false;
    }
    queueFront = backPtr->next->item;
    return true;
}

int main() {
    Queue q;
    for (int i = 1; i <= 4; i++) {
        q.enqueue(i * 10);             // front 10 20 30 40 back
    }

    Queue copy(q);
    q.dequeue();

    QueueItemType front;
    q.getFront(front);
    cout << "q front:    " << front << endl;   // 20
    copy.getFront(front);
    cout << "copy front: " << front << endl;   // 10

    cout << "Dequeue copy: ";
    while (copy.dequeue(front)) {
        cout << front << " ";          // 10 20 30 40
    }
    cout << endl;
    cout << boolalpha << "copy empty? " << copy.isEmpty() << endl;   // true
    return 0;
}
