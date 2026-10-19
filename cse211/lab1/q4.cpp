#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(const string& s);

int main(){
    string text;
    cout << "Enter a string: ";
    getline(cin, text);

    if (isPalindrome(text))
        cout << "\"" << text << "\" is a palindrome." << endl;
    else
        cout << "\"" << text << "\" is not a palindrome." << endl;
    return 0;

}

bool isPalindrome(const string& s) {
    if(s.empty()) return false;

    int n = s.length();
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - 1 - i])
            return false;
    }
    return true;

}