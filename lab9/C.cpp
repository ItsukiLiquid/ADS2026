#include <bits/stdc++.h>
using namespace std;


vector<int> prefix_function(string s){
    int n = s.size();
    vector<int> pi(n, 0);
    for (int i = 1; i < n; ++i){
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j]) j = pi[j-1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}
int findPos(string text, string shifted_text){
    string s = shifted_text + '#' + text + text;
    int n = s.size();
    int m = shifted_text.size();
    vector<int> pi = prefix_function(s);
    for (int i = m + 1; i < n; ++i){
        if (pi[i] == m) return (i - 2*m);
    }
    return -1;
}

int main() {
    string s1, s2; cin >> s1 >> s2;
    cout << findPos(s2, s1);

    return 0;
}
