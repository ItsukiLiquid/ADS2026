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
vector<int> KMP(string text, string pattern){
    string s = pattern + '#' + text;
    int n = s.size();
    int m = pattern.size();
    vector<int> pos = {};
    vector<int> pi = prefix_function(s);
    for (int i = m + 1; i < n; ++i){
        if (pi[i] == m) pos.push_back(i - 2*m + 1);
    }
    return pos;
}
int main() {
    string s, p; cin >> s >> p;
    vector<int> r = KMP(s, p);
    cout << r.size() << '\n';
    for (int& pos: r) cout << pos << " ";

    return 0;
}
