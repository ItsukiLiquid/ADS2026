#include <iostream>
using namespace std;
struct Node{
    int val;
    Node* next;
    Node (int val){
        this->val = val;
        this->next = nullptr;
    }
};

int main(){
    int n, value;
    cin >> n;
    Node* newNode = new Node(0);
    Node* dummy = newNode;
    for (int i = 0; i < n; ++i){
        cin >> value;
        dummy -> next = new Node(value);
        dummy = dummy -> next;
    }
    newNode = newNode -> next;
    Node* tail = newNode;
    while (tail != nullptr && tail -> next != nullptr){
        tail -> next = tail -> next -> next;
        tail = tail -> next;
    }
    Node* cur = newNode;
    while (cur){ // or while (cur != nullptr)
        cout << cur -> val << " ";
        cur = cur -> next;
    }
    return 0;
}