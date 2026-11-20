#include <bits/stdc++.h>
using namespace std;

pair<int, vector<int>> min_distance(int a, int b){
    if (a == b) return {0, {}};
    if (a > b){
        vector<int> result = {};
        for (int i = a - 1; i >= b; --i) result.push_back(i);
        return make_pair(a - b, result);
    }
    vector<int> dist(2*b+1, -1);
    vector<int> parent(2*b+1, -1);
    dist[a] = 0;
    queue<int> q; q.push(a);
    while (!q.empty()){
        int v = q.front(); q.pop();
        if (v == b) break;
        int mv = 2*v, sv = v - 1;
        if (mv <= 2 * b && dist[mv] == -1){
            dist[mv] = dist[v] + 1;
            q.push(mv);
            parent[mv] = v;
        }
        if (sv >= 0 && dist[sv] == -1){
            dist[sv] = dist[v] + 1;
            q.push(sv);
            parent[sv] = v;
        }
    }
    vector<int> path = {};
    int cur = b;
    while (cur != a){
        path.push_back(cur);
        cur = parent[cur];
    }
    reverse(path.begin(), path.end());
    return make_pair(dist[b], path);
}
int main() {
    int a, b; cin >> a >> b;
    pair<int, vector<int>> info = min_distance(a, b);
    cout << info.first << "\n";
    for (int& chain: info.second) cout << chain << " ";
    return 0;
}
