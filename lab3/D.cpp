#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> cumulative_power(vector<int>& sorted_arr){
    vector<int> result;
    int cum_val = 0;
    for (int val: sorted_arr){
        cum_val += val;
        result.push_back(cum_val);
    }
    return result;
}

int firstGE(vector<int>& arr, int target){
    int l = -1;
    int r = arr.size();
    while (l + 1 < r){
        int mid = l + (r - l)/2;
        if (arr[mid] > target) r = mid;
        else l = mid;
    }
    return r;
}
int main(){
    int n, val, p;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; ++i){
        cin >> val;
        arr.push_back(val);
    }
    sort(arr.begin(), arr.end());
    vector<int> cum_arr = cumulative_power(arr);
    cin >> p;
    for (int i = 0; i < p; ++i){
        cin >> val;
        int idx = firstGE(arr, val);
        cout << idx << " " << cum_arr[idx - 1] << endl;
    }
    return 0;
}