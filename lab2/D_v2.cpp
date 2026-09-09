#include <iostream>
using namespace std;


template<typename T>
struct Node{
    T val;
    Node<T>* next;
    Node (T val){
        this->val = val;
        this->next = nullptr;
    }
};

Node<int>* reversed_node(Node<int>* head){
    Node<int>* prev = nullptr;
    Node<int>* cur = head;
    while (cur != nullptr){
        Node<int>* next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}


int main(){
    int n, num;
    cin >> n;
    Node<int>* newNode = new Node<int>(0);
    Node<int>* dummy = newNode;
    for (int i = 0; i < n; ++i){
        cin >> num;
        dummy->next = new Node<int> (num);
        dummy = dummy->next;
    }
    Node<int>* rev_head = reversed_node(newNode->next);
    Node<int>* cur = rev_head;
    while (cur != nullptr){
        cout << cur->val << " ";
        cur = cur->next;
    }
    return 0;
}