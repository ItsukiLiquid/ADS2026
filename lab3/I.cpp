#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long countBlocks(const vector<long long>& arr, long long limit) {
    long long blocks = 1;
    long long current = 0;
    for (long long x : arr) {
        if (current + x <= limit) current += x;
        else{
            blocks++;
            current = x;
        }
    }
    return blocks;
}

long long minMaxSum(const vector<long long>& arr, long long k) {
    long long l = *max_element(arr.begin(), arr.end()) - 1;
    long long r = 0;
    for (long long x: arr) r += x;    
    while (l + 1 < r){
        long long mid = l + (r - l) / 2;
        if (countBlocks(arr, mid) <= k) r = mid;
        else l = mid;
    }   
    return r;
}

int main() {
    long long n, k;
    cin >> n >> k;
    vector<long long> arr(n);
    for (long long& x : arr) cin >> x;
    cout << minMaxSum(arr, k) << '\n';
    return 0;
}