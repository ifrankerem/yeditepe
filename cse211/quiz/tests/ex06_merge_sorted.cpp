#include "helpers.h"
#include "../rendu/ex06_merge_sorted.cpp"

static bool t_contains(Node* const* nodes, int count, Node* n) {
    for (int i = 0; i < count; i++) {
        if (nodes[i] == n) return true;
    }
    return false;
}

static void expect(std::initializer_list<int> av, std::initializer_list<int> bv, const std::string& expected) {
    Node* a = t_build(av);
    Node* b = t_build(bv);
    std::string what = "mergeSorted(" + t_str(a) + ", " + t_str(b) + ")";

    Node* originals[64];
    int count = 0;
    for (Node* c = a; c != nullptr; c = c->next) originals[count++] = c;
    for (Node* c = b; c != nullptr; c = c->next) originals[count++] = c;

    Node* merged = mergeSorted(a, b);
    t_eq(t_str(merged), expected, what);

    bool reused = true;
    int length = 0;
    for (Node* c = merged; c != nullptr && length <= count; c = c->next, length++) {
        if (!t_contains(originals, count, c)) reused = false;
    }
    t_check(reused, what + " must reuse the original nodes (no new)");
    if (reused) {
        t_free(merged);
    }
    // If nodes were not reused we cannot free safely; valgrind will then report leaks too.
}

int main() {
    expect({}, {}, "[]");
    expect({}, {1, 2}, "[1 2]");
    expect({1, 2}, {}, "[1 2]");
    expect({1, 3, 5}, {2, 4, 6}, "[1 2 3 4 5 6]");
    expect({1, 2, 3}, {4, 5}, "[1 2 3 4 5]");
    expect({5}, {1, 2, 3}, "[1 2 3 5]");
    expect({1, 3, 3}, {3, 4}, "[1 3 3 3 4]");
    expect({-5, 0, 10}, {-7, 20}, "[-7 -5 0 10 20]");
    return t_result("ex06_merge_sorted");
}
