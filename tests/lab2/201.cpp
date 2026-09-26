#include <iostream>
#include <queue>
using namespace std;

void first(int n){
    char c;
    queue<char> q;
    int count[26] = {};
    for (int i = 0; i < n; ++i){
        cin >> c;
        count[c - 'a']++;
        q.push(c);
        while (!q.empty() && count[q.front() - 'a'] > 1) q.pop();
        if (q.empty()) cout << -1 << " ";
        else cout << q.front() << " ";
    }
    cout << endl;
}

int main(){
    int n, k;
    char c;
    cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> k;
        first(k);
    }
    return 0;
}