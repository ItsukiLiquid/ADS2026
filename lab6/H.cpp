#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    char c;
    vector<char> v(n);
    cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> c;
        v.push_back(c);
    }
    cin >> c;
    sort(v.begin(), v.end());
    // 3 cases, 1: v[0] is already > c, then output v[0]
    // 2: if v[n-1] < c, then no element greater than c exist, also output v[0]
    // for (char b: v) cout << b << " ";
    if (int(v[0]) > int(c) || int(v[n-1]) <= int(c)) cout << v[0];
    else{
        for (int i = 0; i < n; ++i){
            if (int(v[i]) > int(c)){
                cout << v[i];
                break;
            }
        }
    }
    return 0;
}
