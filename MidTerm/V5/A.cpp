#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> sieve(ll n){
    vector<bool> isPrime(n+1, 1);
    isPrime[0] = isPrime[1] = false;
    for (ll i = 2; i <= n; ++i){
        if (isPrime[i]){
            for (ll j = i * i; j <= n; j += i) isPrime[j] = false;
        }
    }
    vector<ll> result = {};
    for (ll i = 0; i <= n; ++i){
        if (isPrime[i]) result.push_back(i);
    }
    return result;
}
int main() {
    ll n; cin >> n;
    vector<ll> primes = sieve(n);
    // for (ll& x: primes) cout << x << " ";
    cout << primes.size();
    return 0;
}
