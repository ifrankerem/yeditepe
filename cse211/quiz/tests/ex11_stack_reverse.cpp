#include "sq_helpers.h"
#include "../rendu/ex11_stack_reverse.cpp"

static void expect(std::initializer_list<int> topFirst, const std::string& after) {
    Stack s;
    t_fill(s, topFirst);
    std::string what = "reverse() on top " + t_stack(s);
    s.reverse();
    t_eq(t_stack(s), after, what);
    s.push(100);                       // stack must still work after reverse
    s.pop();
    t_eq(t_stack(s), after, what + ", then push/pop");
}

int main() {
    expect({3, 2, 1}, "[1 2 3]");
    expect({1, 2}, "[2 1]");
    expect({7}, "[7]");
    expect({}, "[]");
    expect({5, 5, 1, 9, 0}, "[0 9 1 5 5]");
    return t_result("ex11_stack_reverse");
}
