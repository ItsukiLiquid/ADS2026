#include <iostream>
using namespace std;

struct Node{
    string val;
    Node* next;
    Node* prev;
    Node (string val){
        this->val = val;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

struct DoubleLinkedList {
    Node* head = nullptr;
    Node* tail = nullptr;
    // int sz = 0;

    void add_front(string title){
        Node* newNode = new Node(title);
        if (head == nullptr){ // list is empty
            head = tail = newNode;
        }
        else { // if list isnt empty
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
        // sz++;
        cout << "ok" << endl;
    }

    void add_back(string title){
        Node* newNode = new Node(title);
        if (tail == nullptr){
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        cout << "ok" << endl;
    }

    void erase_front(){
        if (head == nullptr){ // list is empty, nothing to remove
            cout << "error" << endl;
            return;
        }
        Node* temp = head;
        cout << temp->val << endl;
        head = head->next;
        if (head != nullptr){ // list isn't empty, head has address to an object
            head->prev = nullptr;
        }
        else { // if nothing is left, the tail should also be NoneType
            tail = nullptr;
        }
        delete temp;
    }

    void erase_back(){
        if (tail == nullptr){
            cout << "error" << endl;
            return;
        }
        Node* temp = tail;
        cout << temp->val << endl;
        tail = tail->prev;
        if (tail != nullptr) tail->next = nullptr;
        else head = nullptr;
        delete temp;
    }

    void front(){
        if (head == nullptr) cout << "error" << endl;
        else cout << head->val << endl;
    }

    void back(){
        if (tail == nullptr) cout << "error" << endl;
        else cout << tail->val << endl;
    }

    void clear(){
        Node* cur = head;
        while (cur != nullptr){
            Node* temp = cur;
            cur = cur->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
        cout << "ok" << endl;
    }
};

int main(){
    DoubleLinkedList list;
    string command, title;
    while (cin >> command){
        if (command == "add_front"){
            cin >> title;
            list.add_front(title);
        }
        if (command == "add_back"){
            cin >> title;
            list.add_back(title);
        }
        if (command == "erase_front") list.erase_front();
        if (command == "erase_back") list.erase_back();
        if (command == "front") list.front();
        if (command == "back") list.back();
        if (command == "clear") list.clear();
        if (command == "exit"){
            cout << "goodbye" << endl;
            break;
        }
    }
    return 0;
}