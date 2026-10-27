#include "sq_helpers.h"
#include "../rendu/ex13_reverse_queue.cpp"

static void expect(std::initializer_list<int> frontFirst, const std::string& after) {
    Queue q;
    t_fill(q, frontFirst);
    std::string what = "reverseQueue(" + t_queue(q) + ")";
    reverseQueue(q);
    t_eq(t_queue(q), after, what);
    q.enqueue(99);
    t_eq(t_queue(q), after == "[]" ? "[99]" : after.substr(0, after.size() - 1) + " 99]", what + ", then enqueue(99)");
}

int main() {
    expect({1, 2, 3, 4}, "[4 3 2 1]");
    expect({9}, "[9]");
    expect({}, "[]");
    expect({2, 2, 5}, "[5 2 2]");
    return t_result("ex13_reverse_queue");
}
