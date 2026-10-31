#include <bits/stdc++.h>
using namespace std;
void merge(vector<pair<string, int>>& arr, int l, int mid, int r){
    int n1 = mid - l + 1;
    int n2 = r - mid;
    vector<pair<string, int>> L(n1), R(n2);
    for (int i = 0; i < n1; ++i) L[i] = arr[l+i];
    for (int j = 0; j < n2; ++j) R[j] = arr[mid+1+j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2){
        if (L[i].second <= R[j].second){
            arr[k] = L[i];
            i++; k++;
        }
        else{
            arr[k] = R[j];
            j++; k++;
        }
    }
    while (i < n1){
        arr[k] = L[i];
        i++; k++;
    }
    while (j < n2){
        arr[k] = R[j];
        j++; k++;
    }
}
void mergeSort(vector<pair<string, int>>& arr, int l, int r){
    if (l >= r) return;
    int mid = l + (r - l)/2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid, r);
}
int main() {
    int n; cin >> n;
    vector<pair<string, int>> arr(n);
    for (pair<string, int>& x: arr) cin >> x.first >> x.second;
    mergeSort(arr, 0, n-1);
    for (pair<string, int>& x: arr) cout << x.first << '\n';

    return 0;
}
