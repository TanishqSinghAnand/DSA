// Binary Search Tree (BST)
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;  // duplicates are ignored
}

bool search(Node* root, int value) {
    if (root == NULL) return false;
    if (root->data == value) return true;
    if (value < root->data) return search(root->left, value);
    return search(root->right, value);
}

Node* findMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

Node* deleteNode(Node* root, int value) {
    if (root == NULL) return NULL;

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        // case 1 and 2: zero or one child
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // case 3: two children -> replace with inorder successor
        Node* successor = findMin(root->right);
        root->data = successor->data;
        root->right = deleteNode(root->right, successor->data);
    }
    return root;
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = NULL;
    int values[] = {50, 30, 70, 20, 40, 60, 80};

    for (int i = 0; i < 7; i++) {
        root = insert(root, values[i]);
    }

    cout << "Inorder (sorted): ";
    inorder(root);
    cout << endl;
    cout << "Preorder:  ";
    preorder(root);
    cout << endl;
    cout << "Postorder: ";
    postorder(root);
    cout << endl;

    cout << "Search 40: " << (search(root, 40) ? "Found" : "Not found") << endl;
    cout << "Search 90: " << (search(root, 90) ? "Found" : "Not found") << endl;

    root = deleteNode(root, 20);  // leaf
    cout << "After deleting 20: ";
    inorder(root);
    cout << endl;

    root = deleteNode(root, 30);  // one child
    cout << "After deleting 30: ";
    inorder(root);
    cout << endl;

    root = deleteNode(root, 50);  // two children (root)
    cout << "After deleting 50: ";
    inorder(root);
    cout << endl;

    return 0;
}
