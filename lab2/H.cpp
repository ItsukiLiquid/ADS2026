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

int kadaneSum(Node<int>* head){
    int currSum = head->val;
    int maxSum = head->val;

    Node<int>* cur = head->next;
    while (cur){
        currSum = max(cur->val, currSum + cur->val);
        maxSum = max(maxSum, currSum);
        cur = cur->next;
    }
    return maxSum;
}

int main(){
    int n, num;
    cin >> n;
    Node<int>* newNode = new Node<int> (0);
    Node<int>* dummy = newNode;
    for (int i = 0; i < n; ++i){
        cin >> num;
        dummy->next = new Node<int> (num);
        dummy = dummy->next;
    }
    cout << kadaneSum(newNode->next);
    return 0;
}