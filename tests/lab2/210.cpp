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

Node* insert(Node* head, Node* node, int pos){
    if (pos == 0){
        node->next = head;
        return node;
    }
    Node* cur = head;
    for (int i = 0; i < pos - 1; ++i) cur = cur->next;
    node->next = cur->next;
    cur->next = node;
    return head;
}

Node* remove(Node* head, int pos){
    if (pos == 0){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node* cur = head;
    for (int i = 0; i < pos - 1; ++i) cur = cur->next;
    Node* temp = cur->next;
    cur->next = temp->next;
    delete temp;
    return head;
}

Node* replace(Node* head, int pos1, int pos2){
    Node* node;
    if (pos1 == 0){
        node = head;
        head = head->next;
    }
    else{
        Node* cur = head;
        for (int i = 0; i < pos1 - 1; ++i) cur = cur->next;
        node = cur->next;
        cur->next = node->next;
    }
    if (pos2 == 0){
        node->next = head;
        head = node;
    }
    else{
        Node* cur = head;
        for (int i = 0; i < pos2 - 1; ++i) cur = cur->next;
        node->next = cur->next;
        cur->next = node;
    }
    return head;
}
Node* reverse(Node* head){
    Node* prev = nullptr;
    Node* cur = head;
    while (cur){
        Node* next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

void print(Node* head){
    if (head == nullptr){
        cout << -1 << endl;
        return;
    }
    Node* cur = head;
    while (cur){
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
}

Node* cyclic_left(Node* head, int k){
    if (k == 0 || head == nullptr) return head;
    Node* tail = head;
    int len = 1;
    while (tail->next){
        tail = tail->next;
        len++;
    }
    k %= len;
    if (k == 0) return head;
    Node* newTail = head;
    for (int i = 0; i < k - 1; ++i) newTail = newTail->next;
    Node* newHead = newTail->next;
    tail->next = head;
    newTail->next = nullptr;
    return newHead;
}

Node* cyclic_right(Node* head, int k){
    if (k == 0 || head == nullptr) return head;
    Node* tail = head;
    int len = 1;
    while (tail->next){
        tail = tail->next;
        len++;
    }
    k %= len;
    if (k == 0) return head;
    int l = len - k; // initially use cyclic left, but as we need to move right, we can convert it to left by len - k
    Node* newTail = head;
    for (int i = 0; i < l - 1; ++i) newTail = newTail->next;
    Node* newHead = newTail->next;
    tail->next = head;
    newTail->next = nullptr;
    return newHead;
}


int main(){
    int command, x, p;
    return 0;
}