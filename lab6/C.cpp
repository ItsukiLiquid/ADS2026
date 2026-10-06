#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int n, val;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; ++i){
        cin >> val;
        v.push_back(val);
    }
    sort(v.begin(), v.end());
    // for (int i: v) cout << i << " ";
    // cout << endl;
    int min_abs = abs(v[n-1] - v[0]);
    for (int i = 0; i < n - 1; ++i){
        min_abs = min(min_abs, abs(v[i] - v[i+1]));
    }
    // cout << min_abs;
    for (int i = 0; i < n - 1; ++i){
        // cout << v[i] << " " << v[i+1] << endl;
        if (abs(v[i] - v[i+1]) == min_abs) cout << v[i] << " " << v[i+1] << " ";
    }
    return 0;
}
