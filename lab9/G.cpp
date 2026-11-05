#include <iostream>
#include <vector>
using namespace std;

vector<int> prefix_function(string s){
    int n = s.size();
    vector<int> pi(n + 1, 0);
    for (int i = 1; i < n; ++i){
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j]) j = pi[j-1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}
int min_period(string s){
    int n = s.size();
    vector<int> pi = prefix_function(s);
    return n - pi[n-1];
}
int main() {
    string s; cin >> s; cout << min_period(s);
    return 0;
}
