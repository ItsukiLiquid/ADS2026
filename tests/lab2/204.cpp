#include <iostream>
using namespace std;
struct Node{
    int val;
    Node* next;
    Node* prev;
    Node(int val){
        this->val = val;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

Node* reverse_node(Node* head){
    Node* cur = head;
    Node* prev = nullptr;
    while (cur){ // if cur is endpoint, next and prev are nullptr, and nullptr->next DNE
        Node* next_pt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next_pt;
        
    }
    return prev;
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
    Node* rev_node = reverse_node(newNode->next);
    while (rev_node){
        cout << rev_node->val << " ";
        rev_node = rev_node->next;
    }
    return 0;
}