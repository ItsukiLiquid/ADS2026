#include <iostream>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node(): val(0), next(nullptr){}
    Node(int x): val(x), next(nullptr) {}
    Node(Node* next): val(0), next(next) {}
    Node(int x, Node* next): val(x), next(next) {}
};


Node* insert(Node* head, Node* node, int p){
    if (p == 0){
        node->next = head;
        return node;
    }
    Node* cur = head;
    // find the pos before node: p - 1
    for (int i = 0; i < p - 1; ++i) cur = cur->next;
    node->next = cur->next;
    cur->next = node;
    return head;
}

Node* remove(Node* head, int p){
    if (p == 0){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node* cur = head;
    for (int i = 0; i < p - 1; ++i) cur = cur->next;
    Node* temp = cur->next;
    cur->next = temp->next;
    delete temp;
    return head;
}

Node* replace(Node* head, int p1, int p2){
    Node* node;
    if (p1 == 0){
        node = head;
        head = head->next;
    }
    else {
        Node* cur = head;
        for (int i = 0; i < p1 - 1; ++i) cur = cur->next;
        node = cur->next;
        cur->next = node->next;
    }

    if (p2 == 0){
        node->next = head;
        return node;
    }

    Node* cur = head;
    for (int i = 0; i < p2 - 1; ++i) cur = cur->next;
    node->next = cur->next;
    cur->next = node;
    return head;
}

Node* reverse(Node* head){
    Node* prev = nullptr;
    Node* cur = head;
    while (cur != nullptr){
        Node* next = cur->next; // keep next value
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
    while (cur) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
}

Node* cyclic_left(Node* head, int x){
    if (head == nullptr || head->next == nullptr || x == 0) return head; // if no list or list with 1 element or no motion, just return it
    int c = 1;
    Node* tail = head;
    while (tail->next != nullptr){
        tail = tail->next;
        c++;
    }
    x %= c; // find its mod, if len(node) = 4, and there are 10 oper. it is full 2 cycles and 2 left, or 10 % 4 == 2
    if (x == 0) return head;
    Node* newTail = head;
    // traverse x times
    for (int i = 1; i < x; ++i) newTail = newTail->next;
    Node* newHead = newTail->next;
    tail->next = head;
    newTail->next = nullptr;

    return newHead;
}


Node* cyclic_right(Node* head, int x){
    if (head == nullptr || head->next == nullptr || x == 0) return head;
    Node* tail = head;
    int c = 1;
    while (tail->next != nullptr){
        tail = tail->next;
        c++;
    }
    x %= c;
    int left = (c - x);
    if (left == 0) return head;
    Node* newTail = head;
    for (int i = 1; i < left; ++i) newTail = newTail->next;
    Node* newHead = newTail->next;
    tail->next = head;
    newTail->next = nullptr;
    return newHead;
}


int main(){
    Node* head = nullptr;
    while (true){
        int command;
        cin >> command;
        if (command == 0) break;
        else if (command == 1){
            int x, p;
            cin >> x >> p;
            head = insert(head, new Node(x), p);
        }
        else if (command == 2){
            int p;
            cin >> p;
            head = remove(head, p);
        }
        else if (command == 3) print(head);
        
        else if (command == 4){
            int p1, p2;
            cin >> p1 >> p2;
            head = replace(head, p1, p2);
        }
        else if (command == 5) head = reverse(head);
        else if (command == 6){
            int x;
            cin >> x;
            head = cyclic_left(head, x);
        }
        else if (command == 7){
            int x;
            cin >> x;
            head = cyclic_right(head, x);
        }
    }
    return 0;
}