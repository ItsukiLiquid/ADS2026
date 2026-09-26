#include <iostream>
#include <string>
#include <queue>
using namespace std;
template <typename T>
struct Node{
    T val;
    Node* next;
    int size;
    Node(T val){
        this->val = val;
        this->next = nullptr;
        this->size += 1;
    }
};

int main(){
    int n;
    string s;
    cin >> n;
    Node<string>* newNode = new Node<string>("");
    Node<string>* dummy = newNode;
    for (int i = 0; i < n; ++i){
        cin >> s;
        dummy->next = new Node<string>(s);
        dummy = dummy->next;
    }
    newNode = newNode->next;
    Node<string>* tail = newNode;
    int count = 0;
    while (tail && tail->next){
        if (tail->val == tail->next->val){
            tail->next = tail->next->next;
            count++; // removed nodes
        }
        else tail = tail->next;

    }
    Node<string>* cur = newNode;
    cout << n - count << endl;
    while (cur){
        cout << cur->val << endl;
        cur = cur->next;
    }
    return 0;
}