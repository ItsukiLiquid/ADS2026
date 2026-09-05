#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


vector<int> sieve(long long limit){
    vector<bool> isPrime(limit + 1, true);
    vector<int> primes;

    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= limit; ++i){
        if (isPrime[i]){
            for (int j = i * i; j <= limit; j += i) isPrime[j] = false;
        }
    }
    for (int i = 2; i <= limit; ++i){
        if (isPrime[i]) primes.push_back(i);
    }
    return primes;
}

int main(){
    vector<int> primes = sieve(7919);
    int n;
    cin >> n;
    cout << primes[n - 1];
    return 0;
}