#include <iostream>
#include <vector>
#include <queue>
// #include <functional>
using namespace std;

// template <typename T>
// struct Node{
//     T val;
//     Node* next;
//     Node(T val){
//         this->val = val;
//         this->next = nullptr;
//     }
// };
// struct priority_queue{
//     T val;
//     Node* root;
//     Node* push(int val){
//         if (root == nullptr){
//             root = new Node(val);
//             return root;
//         }
//         else{
//             Node* dummy = root;
//             while (dummy && dummy->val <= val){
//                 if (dummy->next && (dummy->next->val >= val)){
//                     Node* temp = dummy;
//                     temp->next = new Node(val);
//                     temp->next->next = dummy->next;
//                     dummy->next = temp->next;
//                 }
//                 dummy = dummy->next;
//             }
//         }
//     }
// };
int main(){
    long long n, val;
    long long ans = 0;
    cin >> n;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (long long i = 0; i < n; ++i){
        cin >> val;
        pq.push(val);
    }
    while (pq.size() > 1){
        long long a = pq.top();
        pq.pop();
        long long b = pq.top();
        pq.pop();

        long long merged = a + b;
        ans += merged;
        pq.push(merged);
    }
    cout << ans;
    // vector<long long> v;
    // for (long long i = 0; i < n; ++i){
    //     cin >> val;
    //     v.push_back(val);
    // }
    // long long ans = 0;
    // for (long long i = 0; i < n - 1; ++i){
    //     sort(v.begin(), v.end());
    //     long long sum = v[i] + v[i+1];
    //     ans += sum;
    //     v[i+1] = sum;
    // }
    // cout << ans;
    return 0;
}
