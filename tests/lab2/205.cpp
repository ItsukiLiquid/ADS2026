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

int main(){
    int n, val;
    cin >> n;
    int mid;
    if ((n & 1) == 0) mid = (n+1)/2;
    else mid = n/2;
    Node* newNode = new Node(0);
    Node* dummy = newNode;
    for (int i = 0; i < n; ++i){
        cin >> val;
        dummy->next = new Node(val);
        dummy = dummy->next;
    }
    Node* cur = newNode->next;
    int idx = 1;
    while (cur){
        if (idx == mid){
            Node* temp = cur->next;
            cur->next = temp->next;
            delete temp;
        }
        cout << cur->val << " ";
        cur = cur->next;
        idx++;
    }
    return 0;
}