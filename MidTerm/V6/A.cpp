#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, val; cin >> n;
    string cmd;
    queue<int> q;
    for (int i = 0; i < n; ++i){
        cin >> cmd;
        if (cmd == "push"){
            cin >> val;
            q.push(val);
        }
        if (cmd == "pop") {cout << q.front() << '\n'; q.pop();}
    }

    return 0;
}
