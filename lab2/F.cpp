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
    int n1, n2, num;
    Node<int>* Node1 = new Node<int>(0);
    Node<int>* Node2 = new Node<int>(0);
    Node<int>* d1 = Node1;
    Node<int>* d2 = Node2;
    cin >> n1;
    for (int i = 0; i < n1; ++i){
        cin >> num;
        d1->next = new Node<int>(num);
        d1 = d1->next;
    }
    cin >> n2;
    for (int i = 0; i < n2; ++i){
        cin >> num;
        d2->next = new Node<int>(num);
        d2 = d2->next;
    }
    Node1 = Node1->next;
    Node2 = Node2->next;
    Node<int>* cur1 = Node1;
    Node<int>* cur2 = Node2;
    if (n1 == 0 && n2 > 0){
        while (cur2){
            cout << cur2->val << " ";
            cur2 = cur2->next;
        }
    }
    if (n1 > 0 && n2 == 0){
        while (cur1){
            cout << cur1->val << " ";
            cur1 = cur1->next;
        }
    }
    if (n1 > 0 && n2 > 0){
        while (cur1 || cur2){
            if (cur1 && cur2 == nullptr){
                while (cur1){
                    cout << cur1->val << " ";
                    cur1 = cur1->next;
                }
            }
            else if (cur1 == 0 && cur2){
                while (cur2){
                    cout << cur2->val << " ";
                    cur2 = cur2->next;
                }
            }
            else{
                if (cur1->val <= cur2->val){
                    cout << cur1->val << " ";
                    cur1 = cur1->next;
                }
                else{
                    cout << cur2->val << " ";
                    cur2 = cur2->next;
                }
            }
        }
    }
    return 0;
}