#include <bits/stdc++.h>
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<vector<int>> area;
vector<vector<bool>> visited;
int ans = 0;
void DFS(int x, int y, int n, int m){
    visited[x][y] = true;
    for (int d = 0; d < 4; ++d){
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m){
            if (!visited[nx][ny] && area[nx][ny]) DFS(nx, ny, n, m);
        }
    }
}
int main() {
    int n, m; string row; cin >> n >> m;
    area.assign(n, vector<int>(m));
    visited.assign(n, vector<bool>(m, false));
    for (int i = 0; i < n; ++i){
        cin >> row;
        for (int j = 0; j < m; ++j) area[i][j] = int(row[j] - '0');
    }

    // for (vector<int>& row: area){
    //     for (int& cell: row) cout << cell << " ";
    //     cout << '\n';
    // }
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            if (!visited[i][j] && area[i][j]){
                ans++;
                DFS(i, j, n, m);
            }
        }
    }
    cout << ans;
    return 0;
}
