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
    int leaves(Node* node){
        if (node == nullptr) return 0;
        int current = (node->right == nullptr && node->left == nullptr); // no child
        return current + leaves(node->left) + leaves(node->right);
    }
};
int main(){
    int n, data;
    cin >> n;
    BST* bst = new BST();
    
    for (int i = 0; i < n; ++i){
        cin >> data;
        bst->root = bst->insert(bst->root, data);
    }
    cout << bst->leaves(bst->root);
    return 0;
}