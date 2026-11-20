#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > a(n, vector<int>(m));
    int cnt_mushrooms = 0;
    vector<vector<bool> > visited(n, vector<bool> (m, false));
    int count = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            cin >> a[i][j];
            if (a[i][j] == 1) cnt_mushrooms++;
            if (a[i][j] == 2) {q.push(make_pair(i, j)); visited[i][j] = true;}
        };
    }
    if (cnt_mushrooms == 0) {cout << 0; return 0;}
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    while (!q.empty()){
        int sz = q.size();
        bool infected = false;
        for (int i = 0; i < sz; ++i){
            pair<int, int> v = q.front(); q.pop();
            int x = v.first, y = v.second;
            for (int d = 0; d < 4; ++d){
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (nx < n && nx >= 0 && ny < m && ny >= 0){
                    if (!visited[nx][ny]){
                        if (a[nx][ny] == 1){
                            cnt_mushrooms--;
                            visited[nx][ny] = true;
                            q.push(make_pair(nx, ny));
                            infected = true;
                        }
                    }
                }
            }
        }
        if (infected) count++;
    }
    if (cnt_mushrooms > 0) cout << -1;
    else cout << count;
    // for (int i = 0; i < n; ++i){
    //     for (int j = 0; j < m; ++j) cout << a[i][j] << " ";
    //     cout << '\n'; 
    // }
    return 0;
}
