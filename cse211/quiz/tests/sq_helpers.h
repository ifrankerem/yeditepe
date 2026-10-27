// Helpers for ex11 .. ex14: print a Stack / Queue through a copy, so the original is untouched.
#ifndef SQ_HELPERS_H
#define SQ_HELPERS_H

#include "helpers.h"
#include "../include/stack_queue.h"

inline std::string t_stack(const Stack& s) {        // top first
    Stack copy(s);
    std::string out;
    int x;
    for (int guard = 0; copy.pop(x) && guard < 10000; guard++) out += (out.empty() ? "" : " ") + std::to_string(x);
    return "[" + out + "]";
}

inline std::string t_queue(const Queue& q) {        // front first
    Queue copy(q);
    std::string out;
    int x;
    for (int guard = 0; copy.dequeue(x) && guard < 10000; guard++) out += (out.empty() ? "" : " ") + std::to_string(x);
    return "[" + out + "]";
}

inline void t_fill(Stack& s, std::initializer_list<int> topFirst) {
    int items[64], n = 0;
    for (int v : topFirst) items[n++] = v;
    while (n > 0) s.push(items[--n]);
}

inline void t_fill(Queue& q, std::initializer_list<int> frontFirst) {
    for (int v : frontFirst) q.enqueue(v);
}

#endif
