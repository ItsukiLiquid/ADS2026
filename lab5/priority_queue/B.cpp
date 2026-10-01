#include <iostream>
#include <queue>

using namespace std;


int main(){
    int n, val;
    cin >> n;
    priority_queue<int, vector<int>> pq;
    for (int i = 0; i < n; ++i){
        cin >> val;
        pq.push(val);
    }
    while (pq.size() > 1){
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        if (a != b){
            int diff = a - b;
            pq.push(diff);
        }
    }
    if (pq.empty()) cout << 0;
    else cout << pq.top();
    return 0;
}
