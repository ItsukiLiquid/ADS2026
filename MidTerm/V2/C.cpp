#include <bits/stdc++.h>
using namespace std;
bool binarySearch(vector<int>& arr, int target){
    int l = -1;
    int r = arr.size();
    while (l + 1 < r){
        int mid = l + (r-l)/2;
        if (arr[mid] > target) r = mid;
        else if (arr[mid] < target) l = mid + 1;
        else return true;
    }
    return false;
}
int main() {
    int n, q, target; cin >> n;
    vector<int> arr(n);
    for (int& x: arr) cin >> x;
    cin >> q;
    for (int i = 0; i < q; ++i){
        cin >> target;
        if (binarySearch(arr, target)) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}
