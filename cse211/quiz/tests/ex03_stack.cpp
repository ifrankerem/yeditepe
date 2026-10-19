#include "helpers.h"
#include "../rendu/ex03_stack.cpp"

int main() {
    int v = -1;

    Stack s;
    t_eq(s.isEmpty(), true, "new stack isEmpty()");
    t_eq(s.size(), 0, "new stack size()");
    t_eq(s.pop(), false, "pop() on empty stack");
    t_eq(s.pop(v), false, "pop(v) on empty stack");
    t_eq(s.getTop(v), false, "getTop(v) on empty stack");
    t_eq(v, -1, "getTop/pop on empty stack must not change v");

    for (int i = 1; i <= 5; i++) s.push(i);
    t_eq(s.isEmpty(), false, "isEmpty() after 5 pushes");
    t_eq(s.size(), 5, "size() after 5 pushes");
    t_eq(s.getTop(v), true, "getTop(v) after pushes");
    t_eq(v, 5, "top after push 1..5");
    t_eq(s.size(), 5, "getTop must not remove the item");

    Stack c(s);
    s.pop();
    s.getTop(v);
    t_eq(v, 4, "original top after copy + pop");
    t_eq(c.size(), 5, "copy size must not change when the original pops");
    c.getTop(v);
    t_eq(v, 5, "copy top must not change when the original pops");

    std::string order;
    while (c.pop(v)) order += std::to_string(v) + " ";
    t_eq(order, std::string("5 4 3 2 1 "), "popping the copy (order kept)");
    t_eq(c.isEmpty(), true, "copy empty after popping all");

    Stack empty;
    Stack emptyCopy(empty);
    t_eq(emptyCopy.isEmpty(), true, "copy of an empty stack");

    Stack big;
    for (int i = 0; i < 10000; i++) big.push(i);
    t_eq(big.size(), 10000, "size() after 10000 pushes");
    big.getTop(v);
    t_eq(v, 9999, "top after 10000 pushes");

    return t_result("ex03_stack");   // s and big still hold items: the destructor must free them
}
