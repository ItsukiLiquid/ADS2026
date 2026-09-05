#include <iostream>
using namespace std;


long long binpow(long long a, long long n, long long m) {
    if (n == 0)
        return 1 % m;

    long long half = binpow(a, n / 2, m);

    if (n % 2 == 0)
        return (half * half) % m;
    else
        return (((half * half) % m) * (a % m)) % m;
}

int main(){
    long long a, n, m;
    cin >> a >> n >> m;
    long long ans = binpow(a, n, m);
    cout << ans;
    return 0;
}