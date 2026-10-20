#include "helpers.h"
#include "../include/linked_list.h"
#include "../rendu/ex09_remove_not_in.cpp"

static void expect(std::initializer_list<int> values, std::initializer_list<int> keep,
                   int count, const std::string& after) {
    LinkedList list;
    for (int v : values) list.pushBack(v);

    int arr[16];
    int size = 0;
    std::string arrStr;
    for (int k : keep) {
        arr[size++] = k;
        arrStr += (arrStr.empty() ? "" : " ") + std::to_string(k);
    }

    std::string what = "removeNotIn({" + arrStr + "}) on " + t_str(list.getHead());
    t_eq(list.removeNotIn(arr, size), count, what + " return value");
    t_eq(t_str(list.getHead()), after, what + " list after");
}

int main() {
    expect({1, 2, 3, 4, 5}, {2, 4}, 3, "[2 4]");
    expect({7, 7, 1}, {7}, 1, "[7 7]");
    expect({1, 2}, {1, 2, 3}, 0, "[1 2]");
    expect({1, 2}, {}, 2, "[]");
    expect({}, {1}, 0, "[]");
    expect({9, 1, 9, 2, 9}, {1, 2}, 3, "[1 2]");
    expect({4, 5, 6}, {6}, 2, "[6]");
    expect({4, 5, 6}, {4}, 2, "[4]");
    return t_result("ex09_remove_not_in");
}
