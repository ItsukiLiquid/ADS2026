#include <iostream>

using namespace std;

class Node {
    public:
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        next = NULL;
    }
};

Node* insert(Node* head, int val, int pos){
    Node* dummy = head;
    if (pos == 0){
        Node* newHead = new Node(val);
        newHead->next = head;
        return newHead;
    }
    for (int i = 0; i < pos - 1; ++i){
        dummy = dummy->next;
    }
    Node* temp = new Node(val);
    temp->next = dummy->next;
    dummy->next = temp;
    return head;
}

void print(Node* head){
    Node* dummy = head;
    while (dummy) {cout << dummy->data << " "; dummy = dummy->next;}
}
int main() {
    int n, pos, val; cin >> n;
    Node* head = new Node(0);
    Node* dummy = head;
    for (int i = 0; i < n; ++i){
        cin >> val;
        dummy->next = new Node(val);
        dummy = dummy->next;
    }
    cin >> pos >> val;
    Node* newHead = insert(head->next, val, pos);
    print(newHead);

    return 0;
}
