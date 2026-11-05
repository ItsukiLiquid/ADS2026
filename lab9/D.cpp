#include <iostream>
#include <vector>
#include <map>
#include <cctype>
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

void KMP(string text, vector<string>& candidates){
    map<int, vector<string>> lengthes = {};
    int max_len = 0;
    for (string& candidate: candidates){
        string s = candidate + '#' + text;
        for (char& c: s) c = tolower(c);
        int n = s.size();
        vector<int> pi = prefix_function(s);
        lengthes[pi[n-1]].push_back(candidate);
        max_len = max(pi[n-1], max_len);
    }
    if (max_len == 0) {cout << 0; return;}
    cout << lengthes[max_len].size() << '\n' ;
    for (string& city: lengthes[max_len]) cout << city << '\n';
}


int main() {
    int n;
    string city, candidate; cin >> city >> n;
    vector<string> c(n);
    for (string& x: c) cin >> x;
    KMP(city, c);
    return 0;
}
