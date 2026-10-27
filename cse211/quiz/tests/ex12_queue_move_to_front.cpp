#include "sq_helpers.h"
#include "../rendu/ex12_queue_move_to_front.cpp"

static void expect(std::initializer_list<int> frontFirst, int value, bool found,
                   const std::string& after, const std::string& afterEnqueue) {
    Queue q;
    t_fill(q, frontFirst);
    std::string what = "moveToFront(" + std::to_string(value) + ") on " + t_queue(q);
    t_eq(q.moveToFront(value), found, what + " return value");
    t_eq(t_queue(q), after, what + " queue after");
    q.enqueue(99);                     // catches a wrong backPtr
    t_eq(t_queue(q), afterEnqueue, what + ", then enqueue(99)");
}

int main() {
    expect({1, 2, 3, 4}, 3, true, "[3 1 2 4]", "[3 1 2 4 99]");
    expect({1, 2, 3, 4}, 4, true, "[4 1 2 3]", "[4 1 2 3 99]");
    expect({1, 2}, 2, true, "[2 1]", "[2 1 99]");
    expect({5, 6, 5}, 5, true, "[5 6 5]", "[5 6 5 99]");
    expect({6, 5, 5}, 5, true, "[5 6 5]", "[5 6 5 99]");
    expect({7}, 7, true, "[7]", "[7 99]");
    expect({1, 2}, 9, false, "[1 2]", "[1 2 99]");
    expect({}, 1, false, "[]", "[99]");
    return t_result("ex12_queue_move_to_front");
}
