#include <iostream>
#include <vector>
using namespace std;

int findRow(const vector<vector<int>>& arr, int target, int n, int m){ // n - row size, m - column size
    int l_c = 0;
    int r_c = n - 1;
    while (l_c <= r_c){
        int mid = l_c + (r_c - l_c)/2;
        if (arr[mid][0] > target && arr[mid][m-1] > target) l_c = mid + 1;
        else if (arr[mid][0] < target && arr[mid][m-1] < target) r_c = mid - 1;
        else return mid;
    }
    return -1;
}
pair<int, int> binarySearch(const vector<vector<int>>& arr, int target, int n, int m){
    int row = findRow(arr, target, n, m);
    if (row == -1) return make_pair(-1, -1);
    int l_r = 0;
    int r_r = m - 1;
    bool isIncrease = (row % 2 != 0); // every odd row: 1, 3 are increasing
    while (l_r <= r_r){
        int mid = l_r + (r_r - l_r)/2;
        if (arr[row][mid] < target){
            if (isIncrease) l_r = mid + 1;
            else r_r = mid - 1;
        }
        else if (arr[row][mid] > target){
            if (isIncrease) r_r = mid - 1;
            else l_r = mid + 1;
        }
        else return make_pair(row, mid);
    }
    return make_pair(-1, -1);
}

int main(){
    int n, m, val, k;
    vector<vector<int>> arr;
    cin >> k;
    vector<int> targets;
    for (int i = 0; i < k; ++i){
        cin >> val;
        targets.push_back(val);
    }
    cin >> n >> m;
    for (int i = 0; i < n; ++i){
        vector<int> one_row;
        for (int j = 0; j < m; ++j){
            cin >> val;
            one_row.push_back(val);
        }
        arr.push_back(one_row);
    }
    for (int target: targets){
        pair<int, int> target_info = binarySearch(arr, target, n, m);
        if (target_info.first == -1) cout << -1 << endl;
        else cout << target_info.first << " " << target_info.second << endl;
    }
    return 0;
}