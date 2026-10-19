#include "helpers.h"
#include <string>
#include "../rendu/ex04_balanced.cpp"

static void expect(const std::string& s, bool expected) {
    t_eq(isBalanced(s), expected, "isBalanced(\"" + s + "\")");
}

int main() {
    expect("", true);
    expect("()", true);
    expect("[]", true);
    expect("{}", true);
    expect("([]{})", true);
    expect("{[()()]}", true);
    expect("a(b[c]d)e", true);
    expect("int main() { return v[0]; }", true);
    expect("no brackets at all", true);
    expect("([)]", false);
    expect("((", false);
    expect("))", false);
    expect("}{", false);
    expect("(]", false);
    expect("{[}", false);
    expect("abc{def}}{ghij{kl}m", false);
    expect("abc{defg{ijk}{l{mn}}op}qr", true);
    return t_result("ex04_balanced");
}
