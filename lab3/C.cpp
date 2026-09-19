#include <iostream>
#include <vector>
using namespace std;

int firstGE(vector<int>& arr, int target){
    int l = -1;
    int r = arr.size();
    while (l + 1 < r){
        int mid = l + (r - l)/2;
        if (arr[mid] < target) l = mid;
        else r = mid;
    }
    return r + 1;
}

int main(){
    int n, m, val;
    cin >> n >> m;
    vector<int> cum_arr;
    int cum_val = 0;
    for (int i = 0; i < n; ++i){
        cin >> val;
        cum_val += val;
        cum_arr.push_back(cum_val);
    }
    for (int i = 0; i < m; ++i){
        cin >> val;
        cout << firstGE(cum_arr, val) << endl;

    }
    return 0;
}