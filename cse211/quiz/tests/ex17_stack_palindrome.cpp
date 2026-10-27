#include "ts_helpers.h"
#include "../rendu/ex17_stack_palindrome.cpp"

template <class T>
static void expect(std::initializer_list<T> topFirst, bool result) {
    Stack<T> s;
    t_tfill(s, topFirst);
    std::string before = t_tstack(s);
    std::string what = "top " + before + ", isPalindrome()";
    t_eq(s.isPalindrome(), result, what);
    t_eq(t_tstack(s), before, what + " must leave the stack unchanged");
}

int main() {
    expect<int>({1, 2, 3, 2, 1}, true);
    expect<int>({1, 2, 2, 1}, true);
    expect<int>({1, 2, 3}, false);
    expect<int>({1, 2}, false);
    expect<int>({7}, true);
    expect<int>({}, true);
    expect<int>({1, 2, 3, 1}, false);
    expect<char>({'r', 'a', 'd', 'a', 'r'}, true);
    expect<char>({'a', 'b', 'c', 'a'}, false);
    return t_result("ex17_stack_palindrome");
}
