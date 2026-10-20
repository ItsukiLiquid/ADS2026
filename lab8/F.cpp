#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
using namespace std;

unsigned long long get_hash(string s){
    const int p = 29;
    unsigned long long p_pow = 1; // p^0
    const long long M = 1e+9;
    unsigned long long h = 0;
    for (int i = 0; i < s.size(); ++i){
        h += s[i] * p_pow;
        p_pow *= p;
    }
    return h;
}


vector<unsigned long long> get_h(string s){
    int n = s.size();
    vector<unsigned long long> h(n);
    h[0] = s[0]; // ?
    const int p = 29;
    unsigned long long p_pow = 29; // p^1
    for (int i = 1; i < n; ++i){
        h[i] = h[i-1] + s[i] * p_pow;
        p_pow *= p;
    }
    return h;
}


int main(){
    string s, s2;
    cin >> s;
    // if (s == "abracadabra"){
    //     cout << 5 << endl << 2 << endl << 2 << endl << 1 << endl << 2;
    //     return 0;
    // }
    unsigned long long ans;
    vector<unsigned long long> p(s.size());
    p[0] = 1;
    for (int i = 1; i < s.size(); ++i){
        p[i] = p[i-1] * 29;
    }
    vector<unsigned long long> h = get_h(s);
    int q, l, r;
    cin >> q;
    for (int i = 0; i < q; ++i){
        ans = 0;
        cin >> l >> r;
        s2 = s.substr(l - 1, r-l + 1); // from l to r there are r - l + 1 values
        unsigned long long h2 = get_hash(s2);
        int n = s.size();
        int m = s2.size();
        for (int i = 0; i < n - m + 1; ++i){
            int j = i + m - 1; // end of substr
            unsigned long long hash = h[j];
            if (i > 0) hash = hash - h[i - 1]; // shifting
            if (hash == h2 * p[i]) ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
