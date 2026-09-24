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
        if (data < node->data) node->left = insert(node->left, data);
        else if (data > node->data) node->right = insert(node->right, data);
        return node;
    }
    int diameter(Node* node, int& ans){
        if (node == nullptr) return 0;

        int left = diameter(node->left, ans);
        int right = diameter(node->right, ans);

        ans = max(ans, left + right + 1);
        return 1 + max(left, right);
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
    int ans = 0;
    bst->diameter(bst->root, ans);
    cout << ans;
    return 0;
}