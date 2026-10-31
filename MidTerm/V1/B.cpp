#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long; // typedef long long ll
ll binary_root(ll n){
    ll l = 0;
    ll r = 1e+9 + 1;
    while (l + 1 < r){
        ll mid = l + (r - l) / 2;
        if (mid * mid <= n) l = mid;
        else r = mid;
    }
    return l;
}

int main(){
    int n; cin >> n;
    ll val;
    for (int i = 0; i < n; ++i){
        cin >> val;
        cout << binary_root(val) << '\n';
    }

    return 0;
}
