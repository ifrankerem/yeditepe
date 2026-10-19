// Chapter 4, slides 4-15 .. 4-28: using the pointer-based ADT List class.
// The class itself is in ListP.h.
#include <iostream>
#include "ListP.h"
using namespace std;

// The user of the ADT only sees positions 1 .. getLength(), never nodes.
void printList(const List& aList) {
    for (int i = 1; i <= aList.getLength(); i++) {
        ListItemType item;
        aList.retrieve(i, item);
        cout << item << " ";
    }
    cout << endl;
}

int main() {
    List a;
    cout << boolalpha;
    cout << "New list empty? " << a.isEmpty() << endl;      // true

    a.insert(1, 20);                   // 20
    a.insert(1, 10);                   // 10 20        (front)
    a.insert(3, 40);                   // 10 20 40     (end: getLength()+1)
    a.insert(3, 30);                   // 10 20 30 40  (middle)
    cout << "a: ";
    printList(a);                      // 10 20 30 40

    cout << "insert(9, 99) ok? " << a.insert(9, 99) << endl;  // false: no position 9

    ListItemType x;
    a.retrieve(2, x);
    cout << "Item at position 2: " << x << endl;            // 20

    List b(a);                         // copy constructor: b gets its own nodes
    b.remove(1);                       // changes only b
    b.insert(1, 99);
    cout << "a: ";
    printList(a);                      // 10 20 30 40
    cout << "b: ";
    printList(b);                      // 99 20 30 40

    a.remove(a.getLength());           // remove last
    cout << "a after removing last: ";
    printList(a);                      // 10 20 30
    cout << "Lengths: a=" << a.getLength() << " b=" << b.getLength() << endl;  // 3 4

    return 0;                          // destructors free both lists
}
