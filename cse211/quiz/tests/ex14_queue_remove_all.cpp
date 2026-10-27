#include "sq_helpers.h"
#include "../rendu/ex14_queue_remove_all.cpp"

static void expect(std::initializer_list<int> frontFirst, int value, int count,
                   const std::string& after, const std::string& afterEnqueue) {
    Queue q;
    t_fill(q, frontFirst);
    std::string what = "removeAll(" + std::to_string(value) + ") on " + t_queue(q);
    t_eq(q.removeAll(value), count, what + " return value");
    t_eq(t_queue(q), after, what + " queue after");
    t_eq(q.isEmpty(), after == "[]", what + " isEmpty()");
    q.enqueue(99);                     // catches a wrong frontPtr / backPtr
    t_eq(t_queue(q), afterEnqueue, what + ", then enqueue(99)");
}

int main() {
    expect({1, 2, 1, 3}, 1, 2, "[2 3]", "[2 3 99]");
    expect({1, 2, 3}, 3, 1, "[1 2]", "[1 2 99]");
    expect({1, 3, 3}, 3, 2, "[1]", "[1 99]");
    expect({4, 4, 4}, 4, 3, "[]", "[99]");
    expect({1, 2}, 9, 0, "[1 2]", "[1 2 99]");
    expect({}, 1, 0, "[]", "[99]");
    expect({5}, 5, 1, "[]", "[99]");
    return t_result("ex14_queue_remove_all");
}
