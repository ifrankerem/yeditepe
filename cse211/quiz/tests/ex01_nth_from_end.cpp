#include "helpers.h"
#include "../rendu/ex01_nth_from_end.cpp"

static void expect(Node* list, int n, Node* expected) {
    Node* got = nthFromEnd(list, n);
    std::string what = "nthFromEnd(" + t_str(list) + ", " + std::to_string(n) + ")";
    t_eq(t_desc(got), t_desc(expected), what);
    if (t_desc(got) == t_desc(expected)) {
        t_check(got == expected, what + " must return the original node, not a copy");
    }
}

int main() {
    expect(nullptr, 1, nullptr);

    Node* one = t_build({7});
    expect(one, 1, one);
    expect(one, 2, nullptr);

    Node* five = t_build({10, 20, 30, 40, 50});
    expect(five, 1, t_at(five, 5));
    expect(five, 2, t_at(five, 4));
    expect(five, 3, t_at(five, 3));
    expect(five, 5, t_at(five, 1));
    expect(five, 6, nullptr);
    expect(five, 0, nullptr);
    expect(five, -1, nullptr);
    t_eq(t_str(five), std::string("[10 20 30 40 50]"), "the list must not change");

    t_free(one);
    t_free(five);
    return t_result("ex01_nth_from_end");
}
