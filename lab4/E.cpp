#include <iostream>
#include <vector>
#include <algorithm>
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
void maxWidth(Node* node, int level, vector<int>& levels){
    if (node == nullptr) return;

    // expand vector with 1 level
    if (level == levels.size()) levels.push_back(0);
    // if counter value, +1 width for certain level
    levels[level]++;

    maxWidth(node->left, level + 1, levels);
    maxWidth(node->right, level + 1, levels);
}


int main(){
    int n, x, y, z;
    cin >> n;
    vector<Node*> nodes(n + 1);
    for (int i = 1; i <= n; ++i){
        nodes[i] = new Node(i);
    }
    for (int i = 0; i < n - 1; ++i){
        cin >> x >> y >> z;

        if (z == 1) nodes[x]->left = nodes[y];
        else nodes[x]->right = nodes[y];
    }
    vector<int> levels = {};
    maxWidth(nodes[1], 0, levels);
    cout << *max_element(levels.begin(), levels.end());
    return 0;
}