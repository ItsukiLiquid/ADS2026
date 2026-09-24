#include <iostream>
#include <vector>
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
    void inOrder(Node* node, vector<int>& sorted_arr){
        if (node == nullptr) return;
        inOrder(node->left, sorted_arr);
        sorted_arr.push_back(node->data);
        inOrder(node->right, sorted_arr);
    }
};


int main(){
    int n, k, data;
    cin >> n >> k;
    BST* bst = new BST();
    for (int i = 0; i < n; ++i){
        cin >> data;
        bst->root = bst->insert(bst->root, data);
    }
    vector<int> arr;
    bst->inOrder(bst->root, arr);
    if (k > n) cout << -1;
    else cout << arr[k-1];
    return 0;
}