#include <bits/stdc++.h>
using namespace std;
struct Node{
    public:
    int val;
    Node *left, *right;
    Node (int val){
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};
struct BST{
    public:
    Node* root;

    BST(){
        this->root = nullptr;
    }
    Node* insert(Node* root, int val){
        if (root == nullptr){
            root = new Node(val);
            return root;
        }
        if (val < root->val) root->left = insert(root->left, val);
        else root->right = insert(root->right, val);
        return root;
    }
    int DFS(Node* root){
        if (!root) return 0; // nullptr = 0
        if (!root->left && !root->right) return 1; // root = 1 but no childs: leaf
        return 1 + max(DFS(root->left), DFS(root->right));
    }
};
int main() {
    int n, val; cin >> n;
    BST* bst = new BST();
    for (int i = 0; i < n; ++i){
        cin >> val;
        bst->root = bst->insert(bst->root, val);
    }
    cout << bst->DFS(bst->root);

    return 0;
}
