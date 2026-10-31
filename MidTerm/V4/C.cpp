#include <bits/stdc++.h>
using namespace std;
vector<int> merge(vector<int>& L, vector<int>& R){
    int n1 = L.size(), n2 = R.size();
    vector<int> arr(n1+n2);
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1){
        arr[k] = L[i];
        i++; k++;
    }
    while (j < n2){
        arr[k] = R[j];
        j++; k++;
    }
    return arr;
}
int main() {
    int n1, n2; cin >> n1;
    vector<int> L(n1);
    for (int& x: L) cin >> x;
    cin >> n2;
    vector<int> R(n2);
    for (int& x: R) cin >> x;
    vector<int> arr = merge(L, R);
    for (int& x: arr) cout << x << " ";
    
    return 0;
}
