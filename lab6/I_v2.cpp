#include <iostream>
#include <string>
using namespace std;

void merge(string arr, int l, int mid, int r){
    int n1 = mid - l + 1;
    int n2 = r - mid;
    string L(n1, ' ');
    string R(n2, ' ');
    for (int i = 0; i < n1; ++i) L[i] = arr[l + i];
    for (int j = 0; j < n2; ++j) R[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2){
        if (L[i] <= R[j]) {arr[k] = L[i]; i++;}
        else {arr[k] = R[j]; j++;}
        k++;
    }
    // remaining elements
    while (i < n1) {arr[k] = L[i]; i++; k++;}
    while (j < n2) {arr[k] = R[j]; j++; k++;}
}

void mergeSort(string& s, int l, int r){
    if (l >= r) return;
    int mid = l + (r - l)/2;
    mergeSort(s, l, mid);
    mergeSort(s, mid + 1, r);
    merge(s, l, mid, r);
}

int main(){
    string s; cin >> s;
    mergeSort(s, 0, s.size() - 1);
    cout << s;
    return 0;
}
