#include <bits/stdc++.h>
using namespace std;
void quickSort(vector<pair<string, int>>& arr, int l, int r){
    pair<string, int> p = arr[(l+r)/2];
    int i = l;
    int j = r;
    while (i < j){
        while (arr[i].second > p.second || arr[i].second == p.second && arr[i].first < p.first) i++;
        while (arr[j].second < p.second || arr[j].second == p.second && arr[j].first > p.first) j--;
        if (i <= j){
            swap(arr[i], arr[j]);
            i++; j--;
        }
    }
    if (l < j) quickSort(arr, l, j);
    if (i < r) quickSort(arr, i, r);
}
int main() {
    int n; cin >> n;
    vector<pair<string, int>> arr(n);
    for (pair<string, int>& x: arr) cin >> x.first >> x.second;
    quickSort(arr, 0, n-1);
    for (pair<string, int>& x: arr) cout << x.first << " " << x.second << "\n";
    return 0;
}
