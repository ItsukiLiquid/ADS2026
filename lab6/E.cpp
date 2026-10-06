// 1 2 3 4 5 6 6 7 8 9 8 7
// c r r c r r c r r c r r
// 0 1 2 3 4 5 6 7 8 9 10 11
// columns: 0, 3, 6, 9, so k | n in fact n = kx for some x

// RC format: 5R, 4C
// 1 2 3 4, c: 0
// 5 6 7 8, c: 4
// 9 0 1 2, c: 8
// 3 4 5 6, c: 12
// 7 8 9 0, c: 16


// vector<vector<int>>, each vector<int> inside vector is kx + n, n = 0: 0, 4, 8, 12, 16
// n = 1: 1, 5, 9, 13, 17.
// n = 2: 2, 6, 10, 14, 18, etc.

// let v be 4r 3c
// 0 1 2
// 3 4 5
// 6 7 8
// 9 0 1

// 0 -> 9
// 1 -> 10
// 2 -> 11, so j_init = i, j_final = (r-1)c + i;
// for i = 0; i < c; ++i; // 0 1 2
// for j = i; j < (r-1)*c + i; j += c // j is dependent from i, 

// n: 0 -> 11
// r: 0 -> 3, c: 0 -> 2
// 0 1 2 3 4 5 6 7 8 9 0 1
// 0 1 2 0 1 2 0 1 2 0 1 2
// v[pos], pos = i % c, where i: 0 -> n-1, or 0 -> r*c-1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int r, c, val;
    cin >> r >> c;
    vector<vector<int>> v(c);
    for (int i = 0; i < r * c; ++i){
        cin >> val;
        int cur_column = i % c;
        v[cur_column].push_back(val);
    }
    // for (int i = 0; i < r; ++i){
    //     for (int j = i; j <= (r-1)*c + i; j += c){ // 2 -> 11, c = 3, 2, 5, 8, 11
    //         v[i].push_back(all_vals[j]); //
    //     }
    // }
    vector<int> v2 = {};
    for (vector<int> row: v){
        sort(row.begin(), row.end(), greater<int>());
        for (int col: row){
            // cout << col << " ";
            v2.push_back(col);
        }
        // cout << endl;
    }
    // cout << endl << endl;
    // for (int a: v2) cout << a << " ";
    // cout << endl << endl;
    // 9 6 4 1 8 7 5 2 8 7 6 3
    // 0 1 2 3 4 5 6 7 8 9 0 1
    
    // cout (positions)
    // 0 4 8
    // 1 5 9
    // 2 6 10
    // 3 7 11
    // i, i + r, i + 2r, .. i + (c)*r assuming c starts from 0
    // (i+1), (i+1)+r, (i+1)+2r, i++ + (c)r;
    for (int i = 0; i < r; ++i){
        for (int j = i; j < r*c; j += r){
            cout << v2[j] << " ";
        }
        cout << endl;
    }

    // for (int i: all_vals) cout << i << " ";
    // for (int i = 0; i < r; ++i){
    //     for (int j = 0; j < c; ++j){
    //         cout << v[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}
