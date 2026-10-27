#include "ts_helpers.h"
#include "../rendu/ex15_sorted_insert.cpp"

static void expect(std::initializer_list<int> topFirst, int x, const std::string& after) {
    Stack<int> s;
    t_tfill(s, topFirst);
    std::string what = "top " + t_tstack(s) + ", insertSorted(" + std::to_string(x) + ")";
    s.insertSorted(x);
    t_eq(t_tstack(s), after, what);
}

int main() {
    expect({9, 8, 7, 4, 3}, 5, "[9 8 7 5 4 3]");   // lab example
    expect({9, 8, 7, 4, 3}, 10, "[10 9 8 7 4 3]");  // new top
    expect({9, 8, 7, 4, 3}, 1, "[9 8 7 4 3 1]");    // new bottom
    expect({9, 8, 7}, 8, "[9 8 8 7]");              // duplicate
    expect({}, 4, "[4]");
    expect({6}, 2, "[6 2]");
    expect({-1, -5}, -3, "[-1 -3 -5]");

    Stack<double> d;                                // must be a template, not only int
    d.push(1.5); d.push(3.5);
    d.insertSorted(2.5);
    double a = 0, b = 0, c = 0;
    d.pop(a); d.pop(b); d.pop(c);
    t_check(a == 3.5 && b == 2.5 && c == 1.5, "Stack<double> top [3.5 1.5], insertSorted(2.5)");
    return t_result("ex15_sorted_insert");
}
