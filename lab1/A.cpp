#include <iostream>
using namespace std;

long long min(long long a, long long b) {
    return (a > b) ? b : a;
}
long long max(long long a, long long b) {
    return (a < b) ? b : a;
}

long long gcd(long long a, long long b) { // assuming a > b
    if (b == 0) return a;
    return gcd(b, a % b);
}
int main(){
    long long a, b;
    cin >> a >> b;
    cout << gcd(max(a, b), min(a, b));
    return 0;
}