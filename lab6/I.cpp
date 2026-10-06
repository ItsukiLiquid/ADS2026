#include <iostream>
#include <vector>
using namespace std;

void quickSort(vector<char>& a, int l, int r){
    int p = a[(l+r)/2];
    int i = l;
    int j = r;
    while (i < j){
        while (a[i] < p) i++;
        while (a[j] > p) j--;
        if (i <= j){
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if (l < j) quickSort(a, l, j);
    if (i < r) quickSort(a, i, r);
}


int main(){
    string s;
    cin >> s;
    vector<char> a = {};
    for (char c: s) a.push_back(c);
    quickSort(a, 0, a.size()-1);
    
    for (char c: a) cout << c;
    return 0;
}
