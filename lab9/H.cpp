#include <bits/stdc++.h>
using namespace std;
vector<int> z_function(string s){
    int n = s.size();
    vector<int> z(n, 0);
    int l = 0, r = 0;
    for (int i = 1; i < n; ++i){
        if (i <= r) z[i] = min(z[i-l], r - i + 1); // if inside a box, capture the minimum of the box size and allowed chars
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++; // expend and explore chars beyond the box, if equal, ++
        if (i + z[i] - 1 > r) {l = i; r = i + z[i] - 1;} // if the checking position is greater than r, update box pos
    }
    return z;
}
int count_splits(string s){
    vector<int> z = z_function(s);
    int ans = 0;
    for (int i = 1; 2*i < s.size(); ++i){ // 2i < n to guarantee len(s) > 0
        if (z[i] >= i) ans++; // if the maxmimum length greater than sufficient one, increment
    }
    return ans;
}
int main() {
    string s; cin >> s; cout << count_splits(s);
    return 0;
}
