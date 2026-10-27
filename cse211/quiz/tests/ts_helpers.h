// Helpers for ex15 .. ex17: build and print a template Stack (top first).
#ifndef TS_HELPERS_H
#define TS_HELPERS_H

#include "helpers.h"
#include "../include/tstack.h"

template <class T>
std::string t_tstack(const Stack<T>& s) {
    Stack<T> copy(s);
    std::string out;
    T x;
    for (int guard = 0; copy.pop(x) && guard < 10000; guard++) {
        if (!out.empty()) out += " ";
        if constexpr (std::is_same_v<T, char>) out += x;
        else out += std::to_string(x);
    }
    return "[" + out + "]";
}

template <class T>
void t_tfill(Stack<T>& s, std::initializer_list<T> topFirst) {
    T items[64];
    int n = 0;
    for (const T& v : topFirst) items[n++] = v;
    while (n > 0) s.push(items[--n]);
}

#endif
