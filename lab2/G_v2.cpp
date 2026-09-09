#include <iostream>
using namespace std;
template<typename T>
struct Node{
    T val;
    Node<T>* next;
    Node (T val){
        this->val = val;
        this->next = next;
    }
};

Node<string>* cyclic_shift (Node<string>* head, int x, int n){
    Node<string>* tail = head;
    Node<string>* cur = head;
    while (tail->next != nullptr) tail = tail->next;
    x %= n;
    for (int i = 1; i < x; ++i) cur = cur->next;
    Node<string>* newTail = cur;
    Node<string>* newHead = newTail->next;
    tail->next = head;
    newTail->next = nullptr;
    return newHead;
}

int main(){
    int n, k;
    string word;
    cin >> n >> k;
    Node<string>* head = new Node<string>("");
    Node<string>* dummy = head;
    for (int i = 0; i < n; ++i){
        cin >> word;
        dummy->next = new Node<string>(word);
        dummy = dummy->next;
    }
    Node<string>* temp = head;
    head = head->next;
    delete temp;
    Node<string>* shifted_node = cyclic_shift(head, k, n);
    Node<string>* cur = shifted_node;
    while (cur != nullptr){
        cout << cur->val << " ";
        cur = cur->next;
    }
    
    return 0;
}