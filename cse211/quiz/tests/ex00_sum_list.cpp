#include "helpers.h"
#include "../rendu/ex00_sum_list.cpp"

int main() {
    t_eq(sumList(nullptr), 0, "sumList([])");

    Node* one = t_build({5});
    t_eq(sumList(one), 5, "sumList([5])");

    Node* four = t_build({1, 2, 3, 4});
    t_eq(sumList(four), 10, "sumList([1 2 3 4])");
    t_eq(t_str(four), std::string("[1 2 3 4]"), "the list must not change");

    Node* neg = t_build({-3, 7, -4});
    t_eq(sumList(neg), 0, "sumList([-3 7 -4])");

    t_free(one);
    t_free(four);
    t_free(neg);
    return t_result("ex00_sum_list");
}
