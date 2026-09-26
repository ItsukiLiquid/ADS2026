#include <iostream>
#include <string>
using namespace std;
struct Node{
    string val;
    Node* next;
    Node(string val){
        this->val = val;
        this->next = nullptr;
    }
};

Node* cyclic_shift(Node* head, int k){ // assuming k is already k mod n
    if (!head || k == 0) return head;
    Node* tail = head;
    while (tail->next) tail = tail->next;
    Node* cur = head;
    for (int i = 0; i < k - 1; ++i) cur = cur->next;
    Node* newTail = cur;
    Node* newHead = cur->next;
    tail->next = head;
    newTail->next = nullptr;
    return newHead;
}

int main(){
    int n, x;
    string piece;
    cin >> n >> x;
    Node* newNode = new Node("");
    Node* dummy = newNode;
    for (int i = 0; i < n; ++i){
        cin >> piece;
        dummy->next = new Node(piece);
        dummy = dummy->next;
    }
    Node* head = newNode->next;
    Node* newHead = cyclic_shift(head, x % n);
    Node* cur = newHead;
    while (cur){
        cout << cur->val << " ";
        cur = cur->next;
    }
    return 0;
}