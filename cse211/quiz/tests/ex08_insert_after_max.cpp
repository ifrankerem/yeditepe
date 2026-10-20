#include "helpers.h"
#include "../include/linked_list.h"
#include "../rendu/ex08_insert_after_max.cpp"

static void expect(std::initializer_list<int> values, int value, const std::string& expected) {
    LinkedList list;
    for (int v : values) list.pushBack(v);
    std::string what = "insertAfterMax(" + std::to_string(value) + ") on " + t_str(list.getHead());
    list.insertAfterMax(value);
    t_eq(t_str(list.getHead()), expected, what);
}

int main() {
    expect({3, 9, 2, 7}, 5, "[3 9 5 2 7]");
    expect({1, 2, 3}, 0, "[1 2 3 0]");
    expect({9, 1, 2}, 4, "[9 4 1 2]");
    expect({8, 1, 8}, 4, "[8 1 8 4]");
    expect({5, 1, 5, 2}, 0, "[5 1 5 0 2]");
    expect({6}, 6, "[6 6]");
    expect({-5, -2, -9}, 0, "[-5 -2 0 -9]");
    expect({}, 5, "[]");
    return t_result("ex08_insert_after_max");
}
