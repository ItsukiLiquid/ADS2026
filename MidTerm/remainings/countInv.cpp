#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll mergeAndCount(vector<int>& arr, int l, int mid, int r){
    vector<int> L(arr.begin() + l, arr.begin() + mid + 1);
    vector<int> R(arr.begin() + mid + 1, arr.begin() + r + 1);
    int i = 0, j = 0, k = l;
    ll cnt = 0;
    while (i < L.size() && j < R.size()){
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else{
            arr[k++] = R[j++];
            cnt += (L.size() - i);
        }
    }
    while (i < L.size()) arr[k++] = L[i++];
    while (j < R.size()) arr[k++] = R[j++];
    return cnt;
}

ll countInv(vector<int>& arr, int l, int r){
    if (l >= r) return 0;
    int mid = l + (r-l)/2;
    ll count = 0;
    count += countInv(arr, l, mid);
    count += countInv(arr, mid + 1, r);
    count += mergeAndCount(arr, l, mid, r);
    return count;
}
int main() {
    int n; cin >> n;
    vector<int> arr(n);
    for (int& x: arr) cin >> x;
    cout << countInv(arr, 0, n-1);
    return 0;
}
