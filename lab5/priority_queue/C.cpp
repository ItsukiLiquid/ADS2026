#include <iostream>
#include <queue>
using namespace std;

int main(){
    long long n, m, val;
    cin >> n >> m;
    priority_queue<long long> pq;
    for (long long i = 0; i < n; ++i){
        cin >> val;
        pq.push(val);
    }

    long long answer = 0;
    for (long long i = 1; i <= m; ++i){
        long long max_val = pq.top();
        pq.pop();
        answer += max_val;
        pq.push(max_val - 1);
    }
    cout << answer;
    return 0;
}
