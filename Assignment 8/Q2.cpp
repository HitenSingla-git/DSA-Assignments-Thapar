#include <iostream>
using namespace std;


class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};


Node* insert(Node* root, int value) {
    if (root == nullptr) return new Node(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}


bool searchRecursive(Node* root, int key) {
    if (root == nullptr) return false;
    if (root->data == key) return true;
    if (key < root->data)
        return searchRecursive(root->left, key);
    else
        return searchRecursive(root->right, key);
}


bool searchIterative(Node* root, int key) {
    while (root != nullptr) {
        if (key == root->data) return true;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return false;
}


Node* findMax(Node* root) {
    if (root == nullptr) return nullptr;
    while (root->right != nullptr)
        root = root->right;
    return root;
}


Node* findMin(Node* root) {
    if (root == nullptr) return nullptr;
    while (root->left != nullptr)
        root = root->left;
    return root;
}


Node* inOrderSuccessor(Node* root, Node* n) {
    if (n->right != nullptr)
        return findMin(n->right);

    Node* succ = nullptr;
    while (root != nullptr) {
        if (n->data < root->data) {
            succ = root;
            root = root->left;
        } else if (n->data > root->data) {
            root = root->right;
        } else
            break;
    }
    return succ;
}


Node* inOrderPredecessor(Node* root, Node* n) {
    if (n->left != nullptr)
        return findMax(n->left);

    Node* pred = nullptr;
    while (root != nullptr) {
        if (n->data > root->data) {
            pred = root;
            root = root->right;
        } else if (n->data < root->data) {
            root = root->left;
        } else
            break;
    }
    return pred;
}


void inOrderTraversal(Node* root) {
    if (root == nullptr) return;
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}


int main() {
    Node* root = nullptr;

 
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    for (int val : values)
        root = insert(root, val);

    cout << "In-order Traversal of BST: ";
    inOrderTraversal(root);
    cout << "\n";

   
    int key = 40;
    cout << "Recursive search for " << key << ": " 
         << (searchRecursive(root, key) ? "Found" : "Not Found") << endl;
    cout << "Iterative search for " << key << ": " 
         << (searchIterative(root, key) ? "Found" : "Not Found") << endl;


    Node* maxNode = findMax(root);
    if (maxNode) cout << "Maximum element: " << maxNode->data << endl;

  
    Node* minNode = findMin(root);
    if (minNode) cout << "Minimum element: " << minNode->data << endl;

    
    Node* node = root->left->right; 
    Node* succ = inOrderSuccessor(root, node);
    if (succ) cout << "In-order Successor of " << node->data << ": " << succ->data << endl;
    else cout << node->data << " has no successor\n";

  
    Node* pred = inOrderPredecessor(root, node);
    if (pred) cout << "In-order Predecessor of " << node->data << ": " << pred->data << endl;
    else cout << node->data << " has no predecessor\n";

    return 0;
}
