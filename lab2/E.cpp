#include <iostream>
using namespace std;

template<typename T>
struct Node{
    T val;
    Node* next;
    Node (T val){
        this->val = val;
        this->next = nullptr;
    }
};


int main(){
    int n, num, removal_pos;
    cin >> n;
    if (n % 2 == 0) removal_pos = n/2 + 1;
    else removal_pos = (n + 1) / 2;
    Node<int>* newNode = new Node<int>(0);
    Node<int>* dummy = newNode;
    for (int i = 0; i < n; ++i){
        cin >> num;
        dummy->next = new Node<int>(num);
        dummy = dummy->next;
    }
    newNode = newNode->next;
    Node<int>* cur = newNode;
    int counter = 1;
    while (cur != nullptr){
        if (counter != removal_pos) cout << cur->val << " ";
        cur = cur->next;
        counter++;
    }
    return 0;
}