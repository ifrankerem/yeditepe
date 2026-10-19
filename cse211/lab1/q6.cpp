#include <iostream>
#include <vector>

using namespace std;

vector<int> removeDuplicates(const vector<int>& v);

int main(){

    vector<int> v = {4, 2, 4, 7, 2, 9};
    vector<int> unique = removeDuplicates(v);

    for (int i = 0; i < unique.size(); i++)
        cout << unique[i] << ", ";
    
    cout << endl;
    return 0;
}

vector<int> removeDuplicates(const vector<int>& v){
    if(v.empty()) return v;

    vector<int> newVector;
    for (int i = 0; i < v.size(); i++)
    {
        bool found = false;
        for (int j = 0; j < newVector.size(); j++)
        {
            if(v[i] == newVector[j]){
                found = true;
                break;
            }
        }
        if(!found)
            newVector.push_back(v[i]);
    }
    return newVector;
}