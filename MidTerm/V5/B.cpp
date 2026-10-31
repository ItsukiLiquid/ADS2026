#include <bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node *left, *right;
    Node (int val){
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};
struct BST{
    Node* root;
    BST(){
        this->root = nullptr;
    }
    Node* insert(Node* node, int val){
        if (!node) {node = new Node(val); return node;}
        if (val < node->val) node->left = insert(node->left, val);
        else node->right = insert(node->right, val);
        return node;
    }
    int leaves(Node* node){
        if (!node) return 0;
        int current = !node->left && !node->right;
        return current + leaves(node->left) + leaves(node->right);
    }
};
int main() {
    int n, val; cin >> n;
    BST* bst = new BST();
    for (int i = 0; i < n; ++i){
        cin >> val;
        bst->root = bst->insert(bst->root, val);
    }
    cout << bst->leaves(bst->root);

    return 0;
}
