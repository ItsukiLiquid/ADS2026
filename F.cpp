#include <iostream>
#include <stack>
using namespace std;

string equal(string s1, string s2){
    stack<char> str1;
    stack<char> str2;
    for (char c: s1){
        if (c == '#'){
            if (!str1.empty()) str1.pop();
        }
        else str1.push(c);
    }
    for (char c: s2){
        if (c == '#'){
            if (!str2.empty()) str2.pop();
        }
        else str2.push(c);
    }
    if (str1 == str2) return "Yes";
    return "No";
}

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    cout << equal(s1, s2);
    return 0;
}