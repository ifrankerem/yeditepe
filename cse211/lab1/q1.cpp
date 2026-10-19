#include <iostream>
#include <stdio.h>

using namespace std;

void swapTwoIntegers(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {

    int a, b;
    cout << "Enter the value of a: ";
    cin >> a;
    cout << "Enter the value of b: ";
    cin >> b;

    cout << "The value of a is: " << a << endl;
    cout << "The value of b is: " << b << endl;

    swapTwoIntegers(&a, &b);

    cout << "After swapping again:" << endl;
    cout << "The value of a is: " << a << endl;
    cout << "The value of b is: " << b << endl;

    return 0;
}