// Chapter 7, slides 7-23 .. 7-29: array-based Queue (circular array).
// front and back move right with (index + 1) % MAX_QUEUE, so they wrap
// around to 0 instead of drifting off the end of the array.
// count tells "full" (count == MAX_QUEUE) apart from "empty" (count == 0),
// because front and back look the same in both cases.
#include <iostream>
using namespace std;

const int MAX_QUEUE = 5;               // small on purpose, to show wrap-around
typedef int QueueItemType;

class Queue {
public:
    Queue();
    bool isEmpty() const;
    bool enqueue(QueueItemType newItem);
    bool dequeue();
    bool dequeue(QueueItemType& queueFront);
    bool getFront(QueueItemType& queueFront) const;

private:
    QueueItemType items[MAX_QUEUE];
    int front;
    int back;
    int count;
};

// back starts at MAX_QUEUE-1 so the first enqueue puts the item at index 0.
Queue::Queue() : front(0), back(MAX_QUEUE - 1), count(0) {
}

bool Queue::isEmpty() const {
    return count == 0;
}

bool Queue::enqueue(QueueItemType newItem) {
    if (count == MAX_QUEUE) {          // queue is full
        return false;
    }
    back = (back + 1) % MAX_QUEUE;
    items[back] = newItem;
    ++count;
    return true;
}

bool Queue::dequeue() {
    if (isEmpty()) {
        return false;
    }
    front = (front + 1) % MAX_QUEUE;
    --count;
    return true;
}

bool Queue::dequeue(QueueItemType& queueFront) {
    if (isEmpty()) {
        return false;
    }
    queueFront = items[front];
    front = (front + 1) % MAX_QUEUE;
    --count;
    return true;
}

bool Queue::getFront(QueueItemType& queueFront) const {
    if (isEmpty()) {
        return false;
    }
    queueFront = items[front];
    return true;
}

int main() {
    Queue q;
    cout << boolalpha;

    for (int i = 1; i <= 5; i++) {
        q.enqueue(i);                  // items[0..4] = 1 2 3 4 5
    }
    cout << "enqueue 6 ok? " << q.enqueue(6) << endl;   // false: full

    QueueItemType x;
    q.dequeue(x);
    cout << "Dequeued: " << x << endl;                  // 1
    q.dequeue(x);
    cout << "Dequeued: " << x << endl;                  // 2

    q.enqueue(6);                      // back wraps around to index 0
    q.enqueue(7);                      // index 1

    cout << "Rest: ";
    while (q.dequeue(x)) {
        cout << x << " ";              // 3 4 5 6 7 (order kept across the wrap)
    }
    cout << endl;
    return 0;
}
