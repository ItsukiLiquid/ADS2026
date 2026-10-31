#include <iostream>
using namespace std;
struct Node{
    public:
    int val;
    Node* next;
    Node (int val){
        this->val = val;
        this->next = nullptr;
    }
};
Node* delete_node(Node* head, int target){
    Node* dummy = head;
    Node* cur = dummy;
    while (cur->next){
        if (cur->next->val == target){
            while (cur->next && cur->next->val == target){
                Node* temp = cur->next;
                cur->next = temp->next;
                delete temp;
            }
        }
        else cur = cur->next;
    }
    return dummy->next;
}
void print(Node* head){
    Node* dummy = head;
    while (dummy){
        cout << dummy->val << " ";
        dummy = dummy->next;
    }
}

int main(){
    int n, val, target; cin >> n;
    Node* head = new Node(0);
    Node* dummy = head;
    for (int i = 0; i < n; ++i){
        cin >> val;
        dummy->next = new Node(val);
        dummy = dummy->next;
    }
    cin >> target;
    Node* new_head = delete_node(head, target);
    print(new_head);
    return 0;
}
