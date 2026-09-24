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
    void greaterSum(Node* node, int& sum){
        if (node == nullptr) return;
        greaterSum(node->right, sum);
        sum+= node->data;
        node->data = sum;
        greaterSum(node->left, sum);
    }
    void inOrder(Node* node){
        if (node == nullptr) return;
        inOrder(node->right);
        cout << node->data << " ";
        inOrder(node->left);
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
    int sum = 0;
    bst->greaterSum(bst->root, sum);
    bst->inOrder(bst->root);
    return 0;
}