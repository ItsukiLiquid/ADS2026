#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100000];
int v;
bool isComponent(int source, int target){
    vector<bool> visited(v + 1, false);
    vector<int> dist(v + 1, -1);
    dist[source] = 0;
    visited[source] = true;
    queue<int> q; q.push(source);

    while (!q.empty()){
        int vertex = q.front(); q.pop();

        for (int& to: adj[vertex]){
            if (!visited[to]){
                visited[to] = true;
                dist[to] = dist[vertex] + 1;
                q.push(to);
            }
        }
    }
    return (dist[target] != -1) ? true : false;

}
int main() {
    int e, x, y, s, f;
    cin >> v >> e;
    for (int i = 0; i < e; ++i){
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cin >> s >> f;
    if (isComponent(s - 1, f - 1)) cout << "YES";
    else cout << "NO";
    // for (int i = 0; i < v; ++i){
    //     cout << i << ": [";
    //     for (int j = 0; j < (int)adj[i].size(); ++j){
    //         cout << adj[i][j];
    //         if (j < (int)adj[i].size() - 1) cout << ", ";
    //     }
    //     cout << "]" << '\n';
    // }
    return 0;
}
