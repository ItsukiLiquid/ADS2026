#include <bits/stdc++.h>
using namespace std;
int binarySearch(vector<int>& arr, int target){
    int l = -1;
    int r = arr.size();
    while (l + 1 < r){
        int mid = l + (r-l)/2;
        if (arr[mid] < target) l = mid;
        else r = mid;
    }
    return r + 1;
}
int main() {
    int n, target, q; cin >> n;
    vector<int> arr(n);
    for (int& x: arr) cin >> x;
    cin >> q;
    for (int i = 0; i < q; ++i){
        cin >> target;
        if (target > arr[n-1]) cout << -1 << "\n";
        else{
            cout << binarySearch(arr, target) << '\n';
        }
    }

    return 0;
}
