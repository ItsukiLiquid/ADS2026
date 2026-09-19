#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> prefix_sum (vector<int>& arr){
    vector<int> result = {0};
    int cum_val = 0;
    for (int val: arr){
        cum_val += val;
        result.push_back(cum_val);
    }
    return result;
}

int minSubArrays(vector<int>& arr, int k, int n){
    vector<int> prefix = prefix_sum(arr);
    int answer = n;
    for (int l = 0; l < n ; ++l){
        int lo = l + 1;
        int hi = n;
        while (lo < hi){
            int mid = lo + (hi - lo) / 2;
            if (prefix[mid] >= prefix[l] + k) hi = mid; // mid works, try smaller value
            else lo = mid + 1;
        }
        if (prefix[lo] >= prefix[l] + k) answer = min(answer, lo - l);
    }
    return answer;
}

int main(){
    int n, k, val;
    cin >> n >> k;
    vector<int> arr;
    for (int i = 0; i < n; ++i){
        cin >> val;
        arr.push_back(val);
    }
    cout << minSubArrays(arr, k, n);
    return 0;
}
