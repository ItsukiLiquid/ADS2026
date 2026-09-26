#include <iostream>
using namespace std;
struct Node{
    string val;
    Node* next;
    Node* prev;
    Node(string val){
        this->val = val;
        this->next = nullptr;
        this->prev = nullptr;
    }
};
struct DoublyLinkedList{
    string val;
    Node* head = nullptr;
    Node* tail = nullptr;
    void add_front(string val){
        Node* newNode = new Node(val);
        if (head == nullptr){
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        cout << "ok" << endl;
    }
    void add_back(string val){
        Node* newNode = new Node(val);
        if (tail == nullptr){
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        cout << "ok" << endl;
    }
    void erase_front(){
        if (head == nullptr){
            cout << "error" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        cout << temp->val << endl;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete temp;
    }
    void erase_back(){
        if (tail == nullptr){
            cout << "error" << endl;
            return;
        }
        Node* temp = tail;
        tail = tail->prev;
        cout << temp->val << endl;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        delete temp;
    }
    void front(){
        if (head == nullptr){
            cout << "error" << endl;
            return;
        }
        cout << head->val << endl;
    }
    void back(){
        if (tail == nullptr) cout << "error" << endl;
        else cout << tail->val << endl;
    }
    void clear(){
        if (head == nullptr){
            cout << "ok" << endl;
            return;
        }
        Node* cur = head;
        while (cur){
            Node* temp = cur;
            cur = cur->next;
            delete temp;
        }
        head = tail = nullptr;
        cout << "ok" << endl;
    }
};
int main(){
    string command, title;
    DoublyLinkedList list;
    while (cin >> command){
        if (command == "add_front"){
            cin >> title;
            list.add_front(title);
        }
        if (command == "add_back"){
            cin >> title;
            list.add_back(title);
        }
        if (command == "erase_front"){
            list.erase_front();
        }
        if (command == "erase_back"){
            list.erase_back();
        }
        if (command == "front"){
            list.front();
        }
        if (command == "back"){
            list.back();
        }
        if (command == "clear"){
            list.clear();
        }
        if (command == "exit"){
            cout << "goodbye" << endl;
            break;
        }
    }
    return 0;
}