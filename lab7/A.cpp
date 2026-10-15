#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

void merge(vector<string>& arr, int l, int mid, int r){
    int n1 = mid - l + 1;
    int n2 = r - mid;
    vector<string> L(n1), R(n2);
    for (int i = 0; i < n1; ++i) L[i] = arr[l + i];
    for (int i = 0; i < n2; ++i) R[i] = arr[mid + 1 + i];
    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2){
        if (L[i].size() <= R[j].size()){
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
}

void mergeSort(vector<string>& arr, int l, int r){
    if (l >= r) return;
    int mid = (l + r)/2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid, r);
}

int main(){
    int n;
    cin >> n;
    string line;
    for (int i = 0; i < n; ++i){
        // cin >> ws used to consume whitespace that is left after cin >> n;
        getline(cin >> ws, line);
        stringstream ss(line);
        vector<string> v;
        string word;
        while (ss >> word) v.push_back(word);
        mergeSort(v, 0, v.size() - 1);
        for (string s: v) cout << s << " ";
        cout << endl;
    }
    return 0;
}
