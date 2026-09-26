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
    Node* newNode = new Node(0);
    Node* dummy = newNode;
    for (int i = 0; i < n; ++i){
        cin >> val;
        dummy->next = new Node(val);
        dummy = dummy->next;
    }
    newNode = newNode->next;
    Node* tail = newNode;
    while (tail != nullptr && tail->next != nullptr){
        Node* temp = tail->next;
        tail->next = temp->next;
        delete temp;
        tail = tail->next;
    }
    Node* cur = newNode;
    while (cur){
        cout << cur->val << " ";
        cur = cur->next;
    }
    return 0;
}