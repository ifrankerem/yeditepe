#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void fillRandom(int arr[], int size);
void bubbleSortDesc(int arr[], int size);
void printArray(const int arr[], int size);

int main() {
    const int SIZE = 10;
    int numbers[SIZE];

    srand(time(0));

    fillRandom(numbers, SIZE);
    cout << "Before: ";
    printArray(numbers, SIZE);

    bubbleSortDesc(numbers, SIZE);
    cout << "After:  ";
    printArray(numbers, SIZE);

    return 0;
}

void fillRandom(int arr[], int size) {
    for (int i = 0; i < size; i++)
        arr[i] = rand() % 100 + 1;
}

void bubbleSortDesc(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

void printArray(const int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}