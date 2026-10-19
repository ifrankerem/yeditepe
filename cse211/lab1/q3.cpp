#include <iostream>
using namespace std;

void reverseArray(int* arr, int size) {
    int* left = arr;
    int* right = arr + size - 1;
    while (left < right) {
        int temp = *left;
        *left = *right;
        *right = temp;
        left++;
        right--;
    }
}

void printArray(const int* arr, int size) {
    for (int i = 0; i < size; i++) cout << *(arr + i) << " ";
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Before: "; printArray(arr, size);
    reverseArray(arr, size);
    cout << "After:  "; printArray(arr, size);
    return 0;
}
