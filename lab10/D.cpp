#include <bits/stdc++.h>
using namespace std;
int n, m, q, x, y;
vector<bool> isRed(5001, false);
vector<int> arr[5001];
int bfs(int source){
    if (isRed[source] == true) return 0;

    vector<bool> visited(n + 1, false);
    vector<int> dist(n + 1, -1);
    visited[source] = true;
    dist[source] = 0;
    queue<int> q; q.push(source);
    while (!q.empty()){
        int v = q.front(); q.pop();
        for (int i = 0; i < (int)arr[v].size(); ++i){
            int to = arr[v][i];
            if (!visited[to]){
                visited[to] = true;
                dist[to] = dist[v] + 1;
                q.push(to);
            }
        }
    }
    int result = n + 1;
    for (int i = 0; i < n; ++i){
        if (isRed[i] && dist[i] != -1) result = min(result, dist[i]);
    }
    return (result == n + 1) ? -1 : result;
}
int main() {
    cin >> n >> m >> q;
    for (int i = 0; i < m; ++i){
        cin >> x >> y;
        x--;
        y--;
        arr[x].push_back(y);
        arr[y].push_back(x);
    }
    for (int i = 0; i < q; ++i){
        cin >> x >> y; // x - cmd, y - argument
        if (x == 1) isRed[y-1] = true;
        if (x == 2) cout << bfs(y - 1) << '\n';
    }
    // for (int i = 0; i < n; ++i){
    //     cout << i << ": [";
    //     for (int j = 0; j < (int)arr[i].size(); ++j){
    //         cout << arr[i][j];
    //         if (j < (int)arr[i].size() - 1) cout << ", ";
    //     }
    //     cout << "]" << '\n';
    // }
    return 0;
}
