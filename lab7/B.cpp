#include <iostream>
#include <vector>
using namespace std;

vector<int> merge(vector<int>& v1, vector<int>& v2){
    int i = 0;
    int j = 0;
    int k = 0;
    vector<int> result(v1.size()+v2.size());
    while (i < v1.size() && j < v2.size()){
        if (v1[i] <= v2[j]){
            result[k] = v1[i];
            i++; k++;
        }
        else{
            result[k] = v2[j];
            j++; k++;
        }
    }
    while (i < v1.size()){
        result[k] = v1[i];
        i++; k++;
    }
    while (j < v2.size()){
        result[k] = v2[j];
        j++; k++;
    }
    return result;
}


int main(){
    int n1, n2;
    cin >> n1;
    vector<int> v1(n1);
    for (int i = 0; i < n1; ++i){
        cin >> v1[i];
    }
    cin >> n2;
    vector<int> v2(n2);
    for (int i = 0; i < n2; ++i){
        cin >> v2[i];
    }
    vector<int> result = merge(v1, v2);
    for (int i: result) cout << i << " ";
}
