#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool areAnagrams(const string& s1, const string& s2);

int main(){

    cout << "Listen / Silent: " << areAnagrams("Listen", "Silent") << endl;
    cout << "Anime / Manga:   " << areAnagrams("Anime", "Manga") << endl;

    return 0;
}

bool areAnagrams(const string& s1, const string& s2){
    if(s1.empty() || s2.empty() || (s1.size() != s2.size())) return false;

    vector<int> count(26, 0);
    for (char c : s1)
        count[tolower(c) - 'a']++;
    for (char c : s2)
        count[tolower(c) - 'a']--;
    for (int x : count)
        if (x != 0) return false;
    return true;

}