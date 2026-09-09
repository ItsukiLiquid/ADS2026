#include <iostream>
#include <stack>
using namespace std;

template<typename T>
struct Node{
    T val;
    Node* next;
    Node(T val){
        this->val = val;
        this->next = nullptr;
    }
};
int main(){
    int n, num;
    cin >> n;
    Node<int>* newNode = new Node<int>(0);
    Node<int>* dummy = newNode;
    for (int i = 0; i < n; ++i){
        cin >> num;
        dummy->next = new Node<int>(num);
        dummy = dummy->next;
    }
    stack<int> rev_num;
    newNode = newNode->next;
    Node<int>* tail = newNode;
    while (tail != nullptr){
        rev_num.push(tail->val);
        tail = tail->next;
    }
    Node<int>* rev_node = new Node<int>(0);
    Node<int>* tail2 = rev_node;
    while (!rev_num.empty()){
        tail2->next = new Node<int>(rev_num.top());
        rev_num.pop();
        tail2 = tail2->next;
    }
    rev_node = rev_node->next;
    Node<int>* cur = rev_node;
    while (cur != nullptr){
        cout << cur->val << " ";
        cur = cur->next;
    }
    return 0;
}