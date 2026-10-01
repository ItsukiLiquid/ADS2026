#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    long long q, k, val;
    string cmd;
    cin >> q >> k;
    long long sum = 0;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (int i = 0; i < q; ++i){
        cin >> cmd;
        if (cmd == "insert"){
            cin >> val;
            if (pq.size() < k){
                sum += val;
                pq.push(val);
            }
            else{
                if (val > pq.top()){
                    sum -= pq.top();
                    pq.pop();
                    sum += val;
                    pq.push(val);
                }
            }
        }
        if (cmd == "print"){
            cout << sum << endl;
        }
    }
    return 0;
}
