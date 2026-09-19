#include <iostream>
#include <vector>
using namespace std;

bool binSearch(vector<int>& arr, int target, int n){
    int left = 0;
    int right = n;
    int mid = left + (right - left) / 2;
    while (left < right){
        int mid = left + (right - left) / 2;
        if (arr[mid] < target) left = mid + 1;
        else if (arr[mid] > target) right = mid;
        else return true;
    }
    return false;
}

int main(){
    int n, val, target;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; ++i){
        cin >> val;
        arr.push_back(val);
    }
    cin >> target;
    if (binSearch(arr, target, n)) cout << "Yes";
    else cout << "No";
    return 0;
}