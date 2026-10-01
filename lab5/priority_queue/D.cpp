#include <iostream>
#include <queue>
using namespace std;

int main(){
    long long n, m, val;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    cin >> n >> m;
    for (long long i = 0; i < n; ++i){
        cin >> val;
        pq.push(val);
    }
    long long counter = 0;
    while (pq.top() < m){
        if (pq.size() < 2){
            cout << -1;
            return 0;
        }
        long long a = pq.top();
        pq.pop();
        long long b = pq.top();
        pq.pop();
        long long c = a + b * 2;
        pq.push(c);
        counter++;
    }
    cout << counter;
    return 0;
}
