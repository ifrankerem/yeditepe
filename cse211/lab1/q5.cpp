#include <iostream>
#include <vector>

using namespace std;

double average(const vector<int>& v);

void printVector(const vector<int>& v, const double& average);

int main() {

    int x;
    vector<int> numbers;
    cout << "Enter values of an array:" << endl;
    while (true)
    {
        cin >> x;
        if(x == 0) break;
        numbers.push_back(x);
    }
    double average_numbers = average(numbers);
    cout << "Average" << average_numbers << endl;
    printVector(numbers, average_numbers);

}

double average(const vector<int>& v) {
    if(v.empty()) return 0;
    int sum=0;
    double average=0;
    for(int i=0; i<v.size(); i++)
        sum+=v[i];

    average = (double)sum / v.size();
    return average;
}

void printVector(const vector<int>& v, const double& average){
    for (int i = 0; i < v.size(); i++){
        if(v[i] > average)
            cout << v[i] << ", ";
    }
        
    cout << endl;
}