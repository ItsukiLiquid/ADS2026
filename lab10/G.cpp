#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int, int>> adj[200001];
vector<int> state, parentEdge;
vector<pair<int, int>> edges;
vector<int> candidates;

bool foundCycle = false;

// Find one directed cycle using DFS
void DFS(int v) {
    state[v] = 1; // processing

    for (auto [u, id] : adj[v]) { // auto [u, id] <=> pair<int, int>& p, and u = p.first, id = p.second
        if (foundCycle) return; // if cycle exists, no need to recurse for other vertices

        if (state[u] == 0) {
            parentEdge[u] = id; // parent_id for current vertix is u
            DFS(u);
        }
        else if (state[u] == 1) {
            // Found a back edge (some vertex: adj[v]) -> u while u is still processing, a cycle
            candidates.push_back(id);

            int cur = v;
            // fallback untill cur exuals to initial_vertex of loop: source to parentEdge_cur
            while (cur != u) {
                candidates.push_back(parentEdge[cur]);
                cur = edges[parentEdge[cur]].first;
            }

            foundCycle = true;
            return;
        }
    }

    state[v] = 2;
}

// Check whether the graph is acyclic
// after removing edge skip
bool isAcyclic(int skip) {
    vector<int> indegree(n, 0);
    // skipping edge numbered "Skip"
    for (int i = 0; i < m; i++) {
        if (i == skip) continue;
        
        int v = edges[i].second; // for u -> v, indegree[v]++;
        indegree[v]++;
    }

    queue<int> q;

    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) // processed vertex
            q.push(i); 
    }

    int processed = 0;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        processed++;

        for (auto [u, id] : adj[v]) {
            if (id == skip) continue;

            indegree[u]--; // undo operations

            if (indegree[u] == 0)
                q.push(u);
        }
    }

    return processed == n; // if some vertices left - a cycle
}

int main() {
    cin >> n >> m;

    state.assign(n, 0);
    parentEdge.assign(n, -1);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        --x;
        --y;

        adj[x].push_back({y, i});
        edges.push_back({x, y});
    }

    // First check whether the graph is already acyclic
    if (isAcyclic(-1)) {
        cout << "YES";
        return 0;
    }

    // Find one cycle
    for (int i = 0; i < n && !foundCycle; i++) {
        if (state[i] == 0)
            DFS(i);
    }

    // Try removing each edge of that cycle
    for (int id : candidates) {
        if (isAcyclic(id)) {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
    return 0;
}
