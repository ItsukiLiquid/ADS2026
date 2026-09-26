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
    int n1, n2, val;
    cin >> n1;
    Node* newNode1 = new Node(0);
    Node* dummy1 = newNode1;
    for (int i = 0; i < n1; ++i){
        cin >> val;
        dummy1->next = new Node(val);
        dummy1 = dummy1->next;
    }
    Node* newNode2 = new Node(0);
    Node* dummy2 = newNode2;
    cin >> n2;
    for (int i = 0; i < n2; ++i){
        cin >> val;
        dummy2->next = new Node(val);
        dummy2 = dummy2->next;
    }
    Node* cur1 = newNode1->next;
    Node* cur2 = newNode2->next;
    while (cur1 && cur2){
        if (cur1->val < cur2->val){
            cout << cur1->val << " ";
            cur1 = cur1->next;
        } else {
            cout << cur2->val << " ";
            cur2 = cur2->next;
        }
    }
    while (cur1){
        cout << cur1->val << " ";
        cur1 = cur1->next;
    }
    while (cur2){
        cout << cur2->val << " ";
        cur2 = cur2->next;
    }
    return 0;
}