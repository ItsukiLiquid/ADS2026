#include <iostream>
using namespace std;


struct Node{
    int data;
    Node* right;
    Node* left;
    Node(int data){
        this->data = data;
        this->right = nullptr;
        this->left = nullptr;
    }
};

struct BST{
    Node* root;
    BST(){
        this->root = nullptr;
    }
    Node* insert(Node* node, int data){
        if (node == nullptr){
            node = new Node(data);
            return node;
        }
        if (data <= node->data) node->left = insert(node->left, data);
        else node->right = insert(node->right, data);
        return node;
    }
    Node* search(Node* node, int data){
        if (node == nullptr || data == node->data) return node;
        if (data < node->data) return search(node->left, data);
        else return search(node->right, data);
        return node;
    }
    int totalCount(Node* node){
        if (node == nullptr) return 0;
        return 1 + totalCount(node->left) + totalCount(node->right);
    }
};


int main(){
    int n, data, parent;
    cin >> n;
    BST* bst = new BST();
    for (int i = 0; i < n; ++i){
        cin >> data;
        bst->root = bst->insert(bst->root, data);
    }
    cin >> parent;
    Node* node = bst->search(bst->root, parent);
    cout << bst->totalCount(node);
    return 0;
}