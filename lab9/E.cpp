#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
vector<ll> prefix_function(string s){
    ll n = s.size();
    vector<ll> pi(n+1, 0);
    for (ll i = 1; i < n; ++i){
        ll j = pi[i-1];
        while (j > 0 && s[i] != s[j]) j = pi[j-1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}
ll min_proper_size(string s, ll k){
    ll n = s.size();
    vector<ll> pi = prefix_function(s);
    return n + (k-1) * (n - pi[n-1]);
}
int main() {
    ll q, k; cin >> q;
    string s;
    for (ll i = 0; i < q; ++i){
        cin >> s >> k;
        cout << min_proper_size(s, k) << '\n';
    }
    return 0;
}
