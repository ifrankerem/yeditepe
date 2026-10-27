#include "ts_helpers.h"
#include "../rendu/ex16_count_unique.cpp"

static void expect(const std::string& str, int n) {
    t_eq(countUnique(str), n, "countUnique(\"" + str + "\")");
}

int main() {
    expect("aacxzax", 2);   // lab example: c and z
    expect("", 0);
    expect("a", 1);
    expect("aa", 0);
    expect("abc", 3);
    expect("abcabc", 0);
    expect("abca", 2);
    expect("zzzzy", 1);
    expect("hello world", 6);  // h e w r d and the space
    return t_result("ex16_count_unique");
}
