#include <bits/stdc++.h>
using namespace std;
vector<bool> visited;
vector<int> parent;
vector<int> childs;
vector<int> adj[100001];
int ans = 0;
void DFS(int v, int p){
    visited[v] = true;
    parent[v] = p;
    for (int u: adj[v]){
        if (!visited[u]){
            childs[v]++;
            DFS(u, v);
        }
    }
}
int main() {
    int n, m, x, y; cin >> n >> m;
    visited.assign(n, false);
    parent.assign(n, -1);
    childs.assign(n, 0);
    for (int i = 0; i < m; ++i){
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i = 0; i < n; ++i){
        if (!visited[i]) DFS(i, -1);
    }
    for (int v = 0; v < n; ++v){
        if (parent[v] == -1) {
            ans++; // root
            // cout << "Incremented, v: " << v << ", parent: " << parent[v] << ", childs: " << childs[v] << endl;
        }
        else if (childs[v] > childs[parent[v]]) {
            ans++;
            // cout << "Incremented, v: " << v << ", parent: " << parent[v] << ", childs: " << childs[v] << endl;
        }
    }
    cout << ans;
    // cout << endl;
    // for (int i = 0; i < n; ++i){
    //     cout << i << ": [";
    //     for (int j = 0; j < (int)adj[i].size(); ++j){
    //         cout << adj[i][j];
    //         if (j < (int)adj[i].size() - 1) cout << ", ";
    //     }
    //     cout << ']' << ", parent: " << parent[i] << ", childs: " << childs[i] << '\n';
    // }

    return 0;
}
