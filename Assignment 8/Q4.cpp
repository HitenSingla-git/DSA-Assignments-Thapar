#include <iostream>
#include <climits>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int v) {
        data = v;
        left = right = NULL;
    }
};

class BinaryTree {
public:
    Node* root;

    BinaryTree() {
        root = NULL;
    }

    bool isBSTUtil(Node* node, long long minVal, long long maxVal) {
        if (!node) return true;
        if (node->data <= minVal || node->data >= maxVal) return false;
        return isBSTUtil(node->left, minVal, node->data) &&
               isBSTUtil(node->right, node->data, maxVal);
    }

    bool isBST() {
        return isBSTUtil(root, LLONG_MIN, LLONG_MAX);
    }
};

int main() {
    BinaryTree t;

    t.root = new Node(10);
    t.root->left = new Node(5);
    t.root->right = new Node(20);
    t.root->left->left = new Node(3);
    t.root->left->right = new Node(7);

    if (t.isBST()) cout << "Tree is BST";
    else cout << "Tree is not BST";
}
