// Implementation of AVL Trees (self-balancing BST)
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
};

int height(Node* node) {
    if (node == NULL) return 0;
    return node->height;
}

int maxOf(int a, int b) {
    return (a > b) ? a : b;
}

Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;  // new node is a leaf
    return newNode;
}

int getBalance(Node* node) {
    if (node == NULL) return 0;
    return height(node->left) - height(node->right);
}

void updateHeight(Node* node) {
    node->height = 1 + maxOf(height(node->left), height(node->right));
}

// Right rotation: left child x becomes the new root of this subtree
// (used when the tree is too heavy on the left side)
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);
    return x;
}

// Left rotation: right child y becomes the new root of this subtree
// (used when the tree is too heavy on the right side)
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);
    return y;
}

// fix the balance of a node after insert/delete
Node* balance(Node* node) {
    updateHeight(node);
    int bf = getBalance(node);

    // Left Left case
    if (bf > 1 && getBalance(node->left) >= 0) {
        return rightRotate(node);
    }
    // Left Right case
    if (bf > 1 && getBalance(node->left) < 0) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    // Right Right case
    if (bf < -1 && getBalance(node->right) <= 0) {
        return leftRotate(node);
    }
    // Right Left case
    if (bf < -1 && getBalance(node->right) > 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

Node* insert(Node* node, int value) {
    if (node == NULL) {
        return createNode(value);
    }
    if (value < node->data) {
        node->left = insert(node->left, value);
    } else if (value > node->data) {
        node->right = insert(node->right, value);
    } else {
        return node;  // duplicates not allowed
    }
    return balance(node);
}

Node* findMin(Node* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

Node* deleteNode(Node* node, int value) {
    if (node == NULL) return NULL;

    if (value < node->data) {
        node->left = deleteNode(node->left, value);
    } else if (value > node->data) {
        node->right = deleteNode(node->right, value);
    } else {
        if (node->left == NULL || node->right == NULL) {
            Node* child = (node->left != NULL) ? node->left : node->right;
            delete node;
            return child;  // may be NULL
        }
        Node* successor = findMin(node->right);
        node->data = successor->data;
        node->right = deleteNode(node->right, successor->data);
    }
    return balance(node);
}

bool search(Node* node, int value) {
    if (node == NULL) return false;
    if (node->data == value) return true;
    if (value < node->data) return search(node->left, value);
    return search(node->right, value);
}

void inorder(Node* node) {
    if (node == NULL) return;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

void preorder(Node* node) {
    if (node == NULL) return;
    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

int main() {
    Node* root = NULL;

    // inserting sorted data would make a normal BST a straight line,
    // but the AVL tree keeps balancing itself
    int values[] = {10, 20, 30, 40, 50, 25};
    for (int i = 0; i < 6; i++) {
        root = insert(root, values[i]);
    }

    cout << "Preorder:  ";
    preorder(root);
    cout << endl;
    cout << "Inorder:   ";
    inorder(root);
    cout << endl;
    cout << "Root: " << root->data << ", Height: " << height(root) << endl;

    cout << "Search 25: " << (search(root, 25) ? "Found" : "Not found") << endl;

    root = deleteNode(root, 40);
    cout << "After deleting 40, preorder: ";
    preorder(root);
    cout << endl;
    cout << "Root: " << root->data << ", Height: " << height(root) << endl;

    return 0;
}
