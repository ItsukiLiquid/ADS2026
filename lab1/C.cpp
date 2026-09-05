#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(long long n){
    if (n == 0 || n == 1){
        cout << "NO";
        return false;
    }
    for (long long i = 2; i <= sqrt(n); ++i){
        if (n % i == 0){
            cout << "NO";
            return false;
        }
    }
    cout << "YES";
    return true;
}

int main(){
    long long n;
    cin >> n;
    isPrime(n);
    return 0;
}