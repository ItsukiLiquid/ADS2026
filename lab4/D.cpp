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
    void sumLevels(Node* node, int level, vector<int>& sums){
        if (node == nullptr) return;

        // we expand the vector by 1 because we are increasing level
        if (level == sums.size()) sums.push_back(0);
        sums[level] += node->data;

        sumLevels(node->left, level + 1, sums);
        sumLevels(node->right, level + 1, sums);
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
    vector<int> sums = {};
    bst->sumLevels(bst->root, 0, sums); // modifies sums
    cout << sums.size() << endl;
    for (int levelCount: sums) cout << levelCount << " ";
    return 0;
}