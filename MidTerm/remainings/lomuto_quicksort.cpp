#include <bits/stdc++.h>
using namespace std;
void quickSort(vector<int>& a){
    int p = a[a.size()-1];
    int i = -1;
    for (int j = 0; j < a.size() - 1; ++j){
        if (a[j] < p) {i++; swap(a[i], a[j]);}
    }
    swap(a[i+1], a[a.size()-1]);
}
int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int& x: a) cin >> x;
    quickSort(a);
    for (int& x: a) cout << x << " ";
    return 0;
}
