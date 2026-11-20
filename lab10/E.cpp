#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q, i, j, k; cin >> n >> q;
    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> arr[i][j];
    for (int x = 0; x < q; ++x){
        cin >> i >> j >> k;
        i--; j--; k--;
        if (arr[i][j] == 1 && arr[j][k] == 1 && arr[i][k] == 1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
