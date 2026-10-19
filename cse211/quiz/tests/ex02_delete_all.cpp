#include "helpers.h"
#include "../rendu/ex02_delete_all.cpp"

static void expect(std::initializer_list<int> values, int value, int count, const std::string& after) {
    Node* list = t_build(values);
    std::string what = "deleteAll(" + t_str(list) + ", " + std::to_string(value) + ")";
    t_eq(deleteAll(list, value), count, what + " return value");
    t_eq(t_str(list), after, what + " list after");
    t_free(list);
}

int main() {
    expect({}, 1, 0, "[]");
    expect({1, 2, 1, 3, 1}, 1, 3, "[2 3]");
    expect({5, 5, 5}, 5, 3, "[]");
    expect({1, 2, 3}, 4, 0, "[1 2 3]");
    expect({1, 2, 2, 2, 3}, 2, 3, "[1 3]");
    expect({4, 1, 4}, 4, 2, "[1]");
    expect({7}, 7, 1, "[]");
    expect({1, 2, 3}, 3, 1, "[1 2]");
    return t_result("ex02_delete_all");
}
