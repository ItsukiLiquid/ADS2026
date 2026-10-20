#include <iostream>
using namespace std;


int main(){
    int n;
    cin >> n;
    string s;
    long long power = 1; // 2^0 = 1
    long long prev = 0; // for first value
    for (int i = 0; i < n; ++i){
        long long h;
        cin >> h;
        long long val = (h - prev) / power;
        power *= 2;
        prev = h;
        s += char(val + 'a');
    }
    cout << s;
    return 0;
}
