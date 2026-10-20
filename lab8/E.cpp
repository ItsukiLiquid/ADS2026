#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    const long long p = 31;
    const long long M1 = 1000000009;
    const long long M2 = 1000000007;
    vector<long long> power1(n + 1, 1);
    vector<long long> power2(n + 1, 1);
    vector<long long> h1(n + 1, 0);
    vector<long long> h2(n + 1, 0);
    for (int i = 0; i < n; ++i){
        power1[i + 1] = power1[i] * p % M1;
        power2[i + 1] = power2[i] * p % M2;
    }
    for (int i = 0; i < n; ++i){
        h1[i + 1] = (h1[i] + (s[i] - 'a' + 1) * power1[i]) % M1;
        h2[i + 1] = (h2[i] + (s[i] - 'a' + 1) * power2[i]) % M2;
    }
    long long ans = 0;
    for (int len = 1; len <= n; ++len){
        set<pair<long long, long long>> hashes;
        for (int l = 0; l + len <= n; ++l){
            long long cur1 = (h1[l + len] - h1[l] + M1) % M1; // we add M to be nonnegative remainder
            long long cur2 = (h2[l + len] - h2[l] + M2) % M2;
            cur1 = cur1 * power1[n - l - 1] % M1;
            cur2 = cur2 * power2[n - l - 1] % M2;
            hashes.insert(make_pair(cur1, cur2));
        }
        ans += hashes.size();
    }
    cout << ans;
    return 0;
}
