#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// bool binarySearch(vector<int>& arr, int target){
//     int l = 0;
//     int r = arr.size() - 1;
//     while (l <= r){
//         int mid = l + (r - l)/2;
//         if (arr[mid] > target) r = mid - 1;
//         else if (arr[mid] < target) l = mid + 1;
//         else return true;
//     }
//     return false;
// }
// vector<int> commonValues(vector<int>& v1, vector<int>& v2){
//     vector<int> ans = {};
//     if (v1.size() < v2.size()){
//         for (int a: v1){
//             if (binarySearch(v2, a)) ans.push_back(a);
//         }
//     }
//     else{
//         for (int a: v2){
//             if (binarySearch(v1, a)) ans.push_back(a);
//         }
//     }
//     return ans;
// }
int main(){
    int n1, n2, val;
    vector<int> v1, v2;
    cin >> n1 >> n2;
    for (int i = 0; i < n1; ++i){
        cin >> val;
        v1.push_back(val);
    }
    for (int i = 0; i < n2; ++i){
        cin >> val;
        v2.push_back(val);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    int i = 0;
    int j = 0;
    while (i < n1 && j < n2){
        if (v1[i] == v2[j]){
            cout << v1[i] << " ";
            i++;
            j++;
        }
        else if (v1[i] > v2[j]) j++;
        else i++;
    }
    return 0;
}
