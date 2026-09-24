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
    int triangles(Node* root){
        if (root == nullptr) return 0;
        // if current forms a triangle, we +1 for overall, if not, we dont skip its children, just +0
        int current = (root->right != nullptr && root->left != nullptr);
        return current + triangles(root->left) + triangles(root->right);
    }
};

int main(){
    int n, data;
    BST* bst = new BST();
    cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> data;
        bst->root = bst->insert(bst->root, data);
    }

    cout << bst->triangles(bst->root);
    return 0;
}