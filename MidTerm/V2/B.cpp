#include <bits/stdc++.h>
using namespace std;
struct Node{
    public:
    int val;
    Node* next;
    Node(int val){
        this->val = val;
        this->next = nullptr;
    }
};
Node* reverse_node(Node* head){
    Node* cur = head;
    Node* prev = nullptr;
    while (cur){
        Node* next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

void print(Node* head){
    Node* dummy = head;
    while (dummy) {cout << dummy->val << " "; dummy = dummy->next;}
}
int main() {
    int n, val; cin >> n;
    Node* head = new Node(0);
    Node* dummy = head;
    for (int i = 0; i < n; ++i){
        cin >> val;
        dummy->next = new Node(val);
        dummy = dummy->next;
    }
    Node* new_head = reverse_node(head->next);
    print(new_head);
    
    return 0;
}
