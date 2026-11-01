#include <bits/stdc++.h>
using namespace std;
int lowerBound(vector<int>& arr, int target){
    int l = -1;
    int r = arr.size();
    while (l + 1 < r){
        int mid = l + (r-l)/2;
        if (arr[mid] < target) l = mid;
        else r = mid;
    }
    return r;
}
int upperBound(vector<int>& arr, int target){
    int l = -1;
    int r = arr.size();
    while (l + 1 < r){
        int mid = l + (r-l)/2;
        if (arr[mid] <= target) l = mid;
        else r = mid;
    }
    return r;
}
int main() {
    int n, target, q; cin >> n;
    vector<int> arr(n);
    for (int& x: arr) cin >> x;
    cin >> q;
    // cout << lowerBound(arr, target) << " " << upperBound(arr, target);
    for (int i = 0; i < q; ++i){
        cin >> target; cout << upperBound(arr, target) - lowerBound(arr, target) << '\n';
    }
    
    return 0;
}
