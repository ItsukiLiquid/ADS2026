#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int R, C; cin >> R >> C;
    vector<vector<int>> v(R, vector<int>(C));
    vector<vector<int>> v_t(C, vector<int>(R));
    for (int i = 0; i < R; ++i){
        for (int j = 0; j < C; ++j){
            cin >> v[i][j];
            v_t[j][i] = v[i][j]; // matrix transpose
        }
    }
    for (vector<int>& row: v_t){
        sort(row.begin(), row.end(), greater<int>());
        // for (int& cell: row) cout << cell << " ";
        // cout << '\n';
    }
    for (int i = 0; i < C; ++i){
        for (int j = 0; j < R; ++j){
            v[j][i] = v_t[i][j];
        }
    }
    for (vector<int>& row: v){
        for (int& cell: row) cout << cell << " ";
        cout << '\n';
    }
    
    return 0;
}
