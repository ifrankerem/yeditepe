#include "helpers.h"
#include "../rendu/ex07_dlist.cpp"

static std::string t_forward(DNode* head) {
    std::string s;
    int guard = 0;
    for (DNode* c = head->next; c != head && c != nullptr && ++guard < 10000; c = c->next) {
        if (!s.empty()) s += " ";
        s += std::to_string(c->data);
    }
    return "[" + s + "]";
}

static std::string t_backward(DNode* head) {
    std::string s;
    int guard = 0;
    for (DNode* c = head->prev; c != head && c != nullptr && ++guard < 10000; c = c->prev) {
        if (!s.empty()) s = " " + s;
        s = std::to_string(c->data) + s;
    }
    return "[" + s + "]";   // printed in forward order, so it should equal t_forward
}

static bool t_links_ok(DNode* head) {
    DNode* c = head;
    int guard = 0;
    do {
        if (c->next == nullptr || c->prev == nullptr) return false;
        if (c->next->prev != c) return false;
        c = c->next;
    } while (c != head && ++guard < 10000);
    return c == head;
}

static void expect_list(DNode* head, const std::string& expected, const std::string& what) {
    t_eq(t_forward(head), expected, what + " (walking next)");
    t_eq(t_backward(head), expected, what + " (walking prev)");
    t_check(t_links_ok(head), what + ": some node has n->next->prev != n");
}

int main() {
    DNode* head = new DNode{-999, nullptr, nullptr};
    head->prev = head;
    head->next = head;

    insertSortedD(head, 30);
    expect_list(head, "[30]", "insert 30 into empty list");
    insertSortedD(head, 20);
    insertSortedD(head, 40);
    insertSortedD(head, 10);
    insertSortedD(head, 20);
    expect_list(head, "[10 20 20 30 40]", "insert 30 20 40 10 20");

    t_eq(removeAllD(head, 20), 2, "removeAllD(20) return value");
    expect_list(head, "[10 30 40]", "after removeAllD(20)");

    t_eq(removeAllD(head, 99), 0, "removeAllD(99) return value");
    expect_list(head, "[10 30 40]", "after removeAllD(99)");

    t_eq(removeAllD(head, 10), 1, "removeAllD(10) (first node)");
    t_eq(removeAllD(head, 40), 1, "removeAllD(40) (last node)");
    expect_list(head, "[30]", "after removing first and last");

    t_eq(removeAllD(head, 30), 1, "removeAllD(30) (only node)");
    t_check(head->next == head && head->prev == head, "empty list: head->next and head->prev must be head");
    t_eq(removeAllD(head, 30), 0, "removeAllD on empty list");

    for (int v : {5, 5, 5, 1, 9}) insertSortedD(head, v);
    expect_list(head, "[1 5 5 5 9]", "insert 5 5 5 1 9");
    t_eq(removeAllD(head, 5), 3, "removeAllD(5)");
    expect_list(head, "[1 9]", "after removeAllD(5)");

    // Free what is left, then the dummy (only if the links are safe to follow).
    if (t_links_ok(head)) {
        DNode* c = head->next;
        while (c != head) {
            DNode* next = c->next;
            delete c;
            c = next;
        }
        delete head;
    }
    return t_result("ex07_dlist");
}
