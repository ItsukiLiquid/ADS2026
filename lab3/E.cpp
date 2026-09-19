#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int mostNear(vector<int>& arr, int target, bool isInclude){
    int l = -1;
    int r = arr.size();
    while (l + 1 < r){
        int mid = l + (r - l)/2;
        if (isInclude){
            if (arr[mid] <= target) l = mid;
            else r = mid;
        }
        else{
            if (arr[mid] < target) l = mid;
            else r = mid;
        }
    }
    return r;
}

int nums(vector<int>& arr, int l1, int r1, int l2, int r2){
    int i1 = mostNear(arr, l1, false);
    int i2 = mostNear(arr, r1, true);
    int i3 = mostNear(arr, l2, false);
    int i4 = mostNear(arr, r2, true);
    int count = (i2 - i1) + (i4 - i3);
    int intersected = max(0, min(i2, i4) - max(i1, i3)); 
    return count - intersected;
}

// 1 3
// 2 4
int main(){
    int n, q, l1, r1, l2, r2, val;
    cin >> n >> q;
    vector<int> arr;
    for (int i = 0; i < n; ++i){
        cin >> val;
        arr.push_back(val);
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < q; ++i){
        cin >> l1 >> r1 >> l2 >> r2;
        cout << nums(arr, l1, r1, l2, r2) << endl;
    }
    return 0;
}