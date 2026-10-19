// Chapter 7, slides 7-30 .. 7-39: Queue built on the ADT List.
// Position 1 is the front, position getLength() is the back:
//   enqueue  -> insert(getLength()+1, item)
//   dequeue  -> remove(1)
//   getFront -> retrieve(1, item)
#include <iostream>
#include "../linked_lists/ListP.h"
using namespace std;

typedef ListItemType QueueItemType;

class Queue {
public:
    Queue();
    Queue(const Queue& Q);
    ~Queue();

    bool isEmpty() const;
    bool enqueue(QueueItemType newItem);
    bool dequeue();
    bool dequeue(QueueItemType& queueFront);
    bool getFront(QueueItemType& queueFront) const;

private:
    List aList;
};

Queue::Queue() {
}

Queue::Queue(const Queue& Q) : aList(Q.aList) {
}

Queue::~Queue() {
}

bool Queue::isEmpty() const {
    return aList.getLength() == 0;
}

bool Queue::enqueue(QueueItemType newItem) {
    return aList.insert(aList.getLength() + 1, newItem);
}

bool Queue::dequeue() {
    return aList.remove(1);
}

bool Queue::dequeue(QueueItemType& queueFront) {
    if (aList.retrieve(1, queueFront)) {
        return aList.remove(1);
    }
    return false;
}

bool Queue::getFront(QueueItemType& queueFront) const {
    return aList.retrieve(1, queueFront);
}

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);                     // front 10 20 30 back

    Queue copy(q);
    q.dequeue();

    QueueItemType front;
    q.getFront(front);
    cout << "q front:    " << front << endl;   // 20
    copy.getFront(front);
    cout << "copy front: " << front << endl;   // 10

    cout << "Dequeue copy: ";
    while (copy.dequeue(front)) {
        cout << front << " ";          // 10 20 30
    }
    cout << endl;
    return 0;
}
