#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> lists[101];
int bfs(int source, int target){
    vector<bool> visited(n + 1, false);
    vector<int> dist(n + 1, -1);
    dist[source] = 0;
    visited[source] = true;
    queue<int> q; q.push(source);
    while (!q.empty()){
        int vertex = q.front(); q.pop();
        if (vertex == target) return dist[vertex];
        for (int& neighbour: lists[vertex]){
            if (!visited[neighbour]){
                visited[neighbour] = true;
                dist[neighbour] = dist[vertex] + 1;
                q.push(neighbour);
            }
        }
    }
    return -1;
}
int main() {
    cin >> n;
    vector<vector<int> > v(n, vector<int> (n));
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            cin >> v[i][j];
            if (v[i][j] == 1){
                lists[i].push_back(j);
                // lists[j].push_back(i);
            }
        }
    }
    int s, t; cin >> s >> t;
    cout << bfs(s - 1, t - 1);
    // for (int i = 0; i < n; ++i){
    //     cout << i << ": [";
    //     for (int j = 0; j < lists[i].size(); ++j){
    //         cout << lists[i][j];
    //         if (j < (int)lists[i].size() - 1) cout << ", ";
    //     }
    //     cout << "]" << '\n';
    // }
    return 0;
}
