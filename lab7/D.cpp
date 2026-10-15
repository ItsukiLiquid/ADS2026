#include <iostream>
#include <vector>
using namespace std;

long long mergeInv(vector<int>& arr, int l, int mid, int r){
    int n1 = mid - l + 1;
    int n2 = r - mid;
    vector<int> L(n1), R(n2);
    long long ans = 0;
    for (int i = 0; i < n1; ++i){
        L[i] = arr[l + i];
    }
    for (int i = 0; i < n2; ++i) R[i] = arr[mid + 1 + i];
    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++; k++;
        }
        else{
            arr[k] = R[j];
            j++; k++;
            ans += n1 - i;
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
    return ans;
}

long long mergeSort(vector<int>& arr, int l, int r){
    if (l >= r) return 0;

    int mid = (l + r)/2;
    long long ans1 = mergeSort(arr, l, mid);
    long long ans2 = mergeSort(arr, mid + 1, r);
    long long ans3 = mergeInv(arr, l, mid, r);
    return ans1 + ans2 + ans3;
    
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    long long inv_count = mergeSort(arr, 0, n - 1);
    cout << inv_count;
}
