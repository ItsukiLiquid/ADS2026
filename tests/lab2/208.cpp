#include <iostream>
using namespace std;
struct Node{
    int val;
    Node* next;
    Node(int val){
        this->val = val;
        this->next = nullptr;
    }
};

int kadaneSum(Node* head){
    int maxSum = head->val;
    int curSum = head->val;
    Node* cur = head->next;
    while (cur){
        curSum = max(cur->val, curSum + cur->val);
        maxSum = max(maxSum, curSum);
        cur = cur->next;
    }
    return maxSum;
}

int main(){
    int n, val;
    cin >> n;
    Node* newNode = new Node(0);
    Node* dummy = newNode;
    for (int i = 0; i < n; ++i){
        cin >> val;
        dummy->next = new Node(val);
        dummy = dummy->next;
    }
    Node* head = newNode->next;
    cout << kadaneSum(head) << endl;
    return 0;
}