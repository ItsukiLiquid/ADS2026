#include <iostream>
#include <vector>
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


vector<int> occurences(string pattern, string text){
    string s = pattern + '#' + text;
    vector<int> pi = prefix_function(s);
    int n = s.size();
    int m = pattern.size();
    vector<int> positions = {};
    for (int i = m + 1; i < n; ++i){
        if (pi[i] == m) positions.push_back(i - 2*m);
    }
    return positions;
}
int main() {
    string p, t;
    int k;
    cin >> p >> k >> t;
    vector<int> pos = occurences(p, t);
    if (pos.size() >= k) cout << "YES";
    else cout << "NO";
    return 0;
}
