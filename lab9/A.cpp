#include <iostream>
#include <vector>
#include <cmath>
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


int countRepeat(string text, string pattern){
    int n = text.size();
    int m = pattern.size();
    int cnt = 0;
    string s = pattern + '#';
    string max_buffer = s;
    for (int i = 1; i <= ceil((double)m/n + 1); ++i) max_buffer += text;
    // cout << max_buffer << '\n';
    vector<int> pi = prefix_function(max_buffer);
    for (int i = 1; i <= ceil((double)m/n) + 1; ++i){
        s += text;
        cnt++;
        for (int j = m + 1; j < s.size(); ++j){
            if (pi[j] == m) return cnt;
        }
    }
    return -1;
}
int main() {
    string t, p; cin >> t >> p;
    cout << countRepeat(t, p);
    return 0;
}
