#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<vector<int>, int>& p1, pair<vector<int>, int>& p2){
    if (p1.second != p2.second) return p1.second > p2.second;
    // p1.first.size() == p2.first.size()
    int i = 0;
    int size = p1.first.size();
    while (i < size){
        if (p1.first[i] != p2.first[i]) return p1.first[i] < p2.first[i];
        i++;
    }
    return p1.first[size - 1] < p2.first[size - 1];
}

// vector<pair<vector<int>, int>> sumSort(vector<pair<vector<int>, int>>& v){

// }

int main(){
    int n, k, val;
    vector<pair<vector<int>, int>> v;
    cin >> n >> k;
    int sum = 0;
    for (int i = 0; i < n; ++i){
        pair<vector<int>, int> vec_sum;
        vector<int> cur_v(k);
        for (int j = 0; j < k; ++j){
            cin >> val;
            cur_v[j] = val;
            sum += val;
        }
        vec_sum.first = cur_v;
        vec_sum.second = sum;
        v.push_back(vec_sum);
        sum = 0;
    }
    sort(v.begin(), v.end(), cmp);
    for (pair<vector<int>, int> p: v){
        for (int val: p.first) cout << val << " ";
        cout << endl;
        // cout << "sum: " << p.second << endl;
    }
    return 0;
}
