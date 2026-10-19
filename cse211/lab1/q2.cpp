#include <iostream>

using namespace std;

void findMinMax(int const arr[], int *min, int *max, int size);

int main() {

    int arr[10];

    cout << "Enter 10 integers: " << endl;
    for(int i=0; i<10; i++){
        cin >> arr[i];
    }

    int min, max;
    findMinMax(arr, &min, &max, 10);

    cout << "Minimum value: " << min << endl;
    cout << "Maximum value: " << max << endl;

    return 0;
}

void findMinMax(int const arr[], int *min, int *max, int size) {
    if (size==0) return;

    int min1=arr[0];
    int max1=arr[0];

    for(int i=0; i<size; i++){
        if(min1 > arr[i]) min1=arr[i];
        if(max1 < arr[i]) max1=arr[i];
    }

    *min = min1;
    *max = max1;
    
}