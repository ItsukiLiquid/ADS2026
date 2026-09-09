#include <iostream>
#include <deque>
#include <string>
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
    int n, k;
    string word;
    cin >> n >> k;
    Node<string>* poem = new Node<string>("");
    Node<string>* dummy = poem;
    for (int i = 0; i < n; ++i){
        cin >> word;
        dummy->next = new Node<string>(word);
        dummy = dummy->next;
    }
    poem = poem->next;
    deque<string> poem_list;
    Node<string>* cur = poem;
    while (cur){
        poem_list.push_back(cur->val);
        cur = cur->next;
    }
    for (int i = 0; i < k; ++i){
        poem_list.push_back(poem_list.front());
        poem_list.pop_front();
    }
    while (!poem_list.empty()){
        cout << poem_list.front() << " ";
        poem_list.pop_front();
    }
    return 0;
}