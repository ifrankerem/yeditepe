#include "helpers.h"
#include "../rendu/ex05_circular_queue.cpp"

int main() {
    t_eq(MAX_QUEUE, 4, "MAX_QUEUE");
    int v = -1;

    Queue q;
    t_eq(q.isEmpty(), true, "new queue isEmpty()");
    t_eq(q.isFull(), false, "new queue isFull()");
    t_eq(q.size(), 0, "new queue size()");
    t_eq(q.dequeue(), false, "dequeue() on empty queue");
    t_eq(q.dequeue(v), false, "dequeue(v) on empty queue");
    t_eq(q.getFront(v), false, "getFront(v) on empty queue");
    t_eq(v, -1, "dequeue/getFront on empty queue must not change v");

    for (int i = 1; i <= 4; i++) {
        t_eq(q.enqueue(i), true, "enqueue(" + std::to_string(i) + ") into non-full queue");
    }
    t_eq(q.isFull(), true, "isFull() after 4 enqueues");
    t_eq(q.size(), 4, "size() after 4 enqueues");
    t_eq(q.enqueue(5), false, "enqueue(5) into full queue");

    q.getFront(v);
    t_eq(v, 1, "getFront after enqueue 1..4");
    q.dequeue(v);
    t_eq(v, 1, "first dequeue");
    q.dequeue(v);
    t_eq(v, 2, "second dequeue");
    t_eq(q.size(), 2, "size() after 2 dequeues");

    t_eq(q.enqueue(5), true, "enqueue(5) after 2 dequeues (wrap around)");
    t_eq(q.enqueue(6), true, "enqueue(6) after 2 dequeues (wrap around)");
    t_eq(q.isFull(), true, "isFull() after wrap around");

    std::string order;
    while (q.dequeue(v)) order += std::to_string(v) + " ";
    t_eq(order, std::string("3 4 5 6 "), "dequeue all after wrap around");
    t_eq(q.isEmpty(), true, "isEmpty() at the end");

    // Many rounds: front and back go around the array again and again.
    Queue r;
    int next = 0, expected = 0;
    bool inOrder = true;
    for (int round = 0; round < 50; round++) {
        while (r.enqueue(next)) next++;
        for (int k = 0; k < 3; k++) {
            r.dequeue(v);
            if (v != expected++) inOrder = false;
        }
    }
    t_eq(inOrder, true, "FIFO order kept over 50 wrap-around rounds");
    t_eq(r.size(), 1, "size() after the rounds");

    return t_result("ex05_circular_queue");
}
