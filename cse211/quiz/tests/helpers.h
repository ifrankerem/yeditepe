// Shared test helpers. Names start with t_ so they never clash with student code.
#ifndef TEST_HELPERS_H
#define TEST_HELPERS_H

#include <iostream>
#include <string>
#include <initializer_list>
#include "../include/node.h"

inline int t_fails = 0;

inline void t_check(bool ok, const std::string& what) {
    if (!ok) {
        std::cout << "  KO: " << what << std::endl;
        ++t_fails;
    }
}

template <typename T, typename U>
void t_eq(const T& got, const U& expected, const std::string& what) {
    if (!(got == expected)) {
        std::cout << std::boolalpha
                  << "  KO: " << what << "\n"
                  << "      expected: " << expected << "\n"
                  << "      got:      " << got << std::endl;
        ++t_fails;
    }
}

inline Node* t_build(std::initializer_list<int> values) {
    Node* head = nullptr;
    Node** tail = &head;
    for (int v : values) {
        *tail = new Node{v, nullptr};
        tail = &(*tail)->next;
    }
    return head;
}

// "[1 2 3]". Stops on very long lists so a cycle cannot hang the grader.
inline std::string t_str(Node* head) {
    std::string s;
    int guard = 0;
    for (Node* cur = head; cur != nullptr; cur = cur->next) {
        if (++guard > 10000) {
            return "[" + s + " ...] (cycle?)";
        }
        if (!s.empty()) s += " ";
        s += std::to_string(cur->data);
    }
    return "[" + s + "]";
}

inline std::string t_desc(Node* n) {
    return n == nullptr ? "nullptr" : "node(data=" + std::to_string(n->data) + ")";
}

inline Node* t_at(Node* head, int index) {   // index starts at 1
    for (int i = 1; head != nullptr && i < index; i++) head = head->next;
    return head;
}

inline void t_free(Node* head) {
    while (head != nullptr) {
        Node* next = head->next;
        delete head;
        head = next;
    }
}

// The grader prints the final OK / KO line (valgrind may still fail a passing test).
inline int t_result(const char*) {
    return t_fails == 0 ? 0 : 1;
}

#endif
