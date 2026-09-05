#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<long long> sieve(long long n){
    vector<bool> isPrime(n + 1, true);
    vector<long long> primes;
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; ++i){
        if (isPrime[i]){
            for (int j = i * i; j <= n; j += i) isPrime[j] = false;
        }
    }
    for (int i = 0; i < isPrime.size(); ++i){
        if (isPrime[i]) primes.push_back(i);
    }
    return primes;
}

vector<long long> primeFactor(long long n, vector<long long>& primes){
    vector<long long> result;
    for (long long p: primes){
        while (n % p == 0){
            result.push_back(p);
            n /= p;
        }
    }
    if (n != 1) result.push_back(n);
    return result;
}
int main(){
    long long n;
    cin >> n;
    vector<long long> primes = sieve(sqrt(n));
    // for (int p: primes) cout << p << " ";
    vector<long long> factor = primeFactor(n, primes);
    for (long long p: factor) cout << p << " ";
    return 0;
}