#include <iostream>
#include <vector>
using namespace std;

vector<int> mergeSquare(vector<int>& v){
    int i = 0;
    int j = v.size() - 1;
    int k = j;
    vector<int> result(j+1);
    while (i <= j){
        if (abs(v[i]) > abs(v[j])){
            result[k] = v[i] * v[i];
            i++;
        }
        else{
            result[k] = v[j] * v[j];
            j--;
        }
        k--;
    }
    return result;
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i){
        cin >> v[i];
    }
    vector<int> v2 = mergeSquare(v);
    for (int i: v2) cout << i << " ";
}
