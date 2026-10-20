#include "helpers.h"
#include "../include/linked_list.h"
#include "../rendu/ex10_new_minimums.cpp"

static std::string t_vec(const std::vector<int>& v) {
    std::string s;
    for (int x : v) s += (s.empty() ? "" : " ") + std::to_string(x);
    return "{" + s + "}";
}

static void expect(std::initializer_list<int> values, const std::string& expected) {
    LinkedList list;
    for (int v : values) list.pushBack(v);
    std::string before = t_str(list.getHead());
    t_eq(t_vec(list.newMinimums()), expected, "newMinimums() on " + before);
    t_eq(t_str(list.getHead()), before, "newMinimums() must not change the list");
}

int main() {
    expect({3, 1, 5, 2, 0, 7}, "{3 1 0}");
    expect({5, 4, 3, 2, 1}, "{5 4 3 2 1}");
    expect({1, 2, 3}, "{1}");
    expect({2, 2, 1, 1}, "{2 1}");
    expect({7}, "{7}");
    expect({-1, 5, -3, -3, -2, -10}, "{-1 -3 -10}");
    expect({}, "{}");
    return t_result("ex10_new_minimums");
}
