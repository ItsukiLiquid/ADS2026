#include <iostream>
#include <string>
#include <vector>
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
    int n;
    string name;
    cin >> n;
    Node<string>* newNode = new Node<string>("");
    Node<string>* dummy = newNode;
    for (int i = 0; i < n; ++i){
        cin >> name;
        dummy->next = new Node<string>(name);
        dummy = dummy->next;
        
    }
    newNode = newNode->next;
    Node<string>* tail = newNode;
    vector<string> notConsecutive;
    int counter = 0;
    string cur_let = "";
    while (tail != nullptr){
        if (tail->val != cur_let){
            cur_let = tail->val;
            counter++;
            notConsecutive.push_back(cur_let);
        }
        tail = tail->next;
    }
    cout << counter << endl;
    for (string let: notConsecutive) cout << let << endl;
    return 0;
}