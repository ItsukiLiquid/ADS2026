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
        if (data <= node->data){
            node->left = insert(node->left, data);
        }
        else{
            node->right = insert(node->right, data);
        }
        return node;
    }
};

bool pathExists(BST* bst, string path){
    Node* root = bst->root;
    for (char dir: path){
        if (dir == 'L'){
            if (root == nullptr) return false;
            root = root->left;
        }
        else{
            if (root == nullptr) return false;
            root = root->right;
        }
    }
    return (root != nullptr);
}

int main(){
    int n, k, data;
    string path;
    cin >> n >> k;
    BST* bst = new BST();
    for (int i = 0; i < n; ++i){
        cin >> data;
        bst->root = bst->insert(bst->root, data);
    }
    // cout << pathExists(bst, "LLL");
    for (int i = 0; i < k; ++i){
        cin >> path;
        BST* copy = bst;
        if (pathExists(copy, path)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}