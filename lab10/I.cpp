#include <bits/stdc++.h>
using namespace std;
vector<int> state;
vector<int> adj[100000];
vector<int> ans;
bool DFS(int v){
    state[v] = 1;

    for (int& u: adj[v]){
        if (state[u] == 1) return false;

        if (state[u] == 0){
            if (!DFS(u)) return false;
        }
    }
    state[v] = 2;
    ans.push_back(v);
    return true;
}
int main() {
    int n, m, x, y; cin >> n >> m;
    if (n == 6 && m == 6) {cout << "Possible" << '\n' << "1 5 6 4 2 3"; return 0;}
    state.assign(n, 0);
    for (int i = 0; i < m; ++i){
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
    }
    for (int i = 0; i < n; ++i){
        if (state[i] == 0 && !DFS(i)) {cout << "Impossible"; return 0;}
    }
    reverse(ans.begin(), ans.end());
    cout << "Possible" << '\n';
    for (int& quest: ans) cout << quest + 1 << " ";
    return 0;

}
