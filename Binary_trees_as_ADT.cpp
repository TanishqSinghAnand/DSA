// Binary Tree as ADT
// Nodes are inserted level by level (left to right),
// and the tree is printed using the three traversals.
#include <iostream>
#include <queue>
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

class BinaryTree {
    Node* root;

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

    void postorder(Node* node) {
        if (node == NULL) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    int height(Node* node) {
        if (node == NULL) return 0;
        int lh = height(node->left);
        int rh = height(node->right);
        return (lh > rh ? lh : rh) + 1;
    }

    int countNodes(Node* node) {
        if (node == NULL) return 0;
        return 1 + countNodes(node->left) + countNodes(node->right);
    }

    bool search(Node* node, int value) {
        if (node == NULL) return false;
        if (node->data == value) return true;
        return search(node->left, value) || search(node->right, value);
    }

public:
    BinaryTree() {
        root = NULL;
    }

    // insert at the first empty spot (level order)
    void insert(int value) {
        Node* newNode = createNode(value);
        if (root == NULL) {
            root = newNode;
            return;
        }

        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();

            if (temp->left == NULL) {
                temp->left = newNode;
                return;
            } else {
                q.push(temp->left);
            }

            if (temp->right == NULL) {
                temp->right = newNode;
                return;
            } else {
                q.push(temp->right);
            }
        }
    }

    void levelOrder() {
        if (root == NULL) return;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();
            cout << temp->data << " ";
            if (temp->left != NULL) q.push(temp->left);
            if (temp->right != NULL) q.push(temp->right);
        }
        cout << endl;
    }

    void inorder() { inorder(root); cout << endl; }
    void preorder() { preorder(root); cout << endl; }
    void postorder() { postorder(root); cout << endl; }
    int height() { return height(root); }
    int countNodes() { return countNodes(root); }
    bool search(int value) { return search(root, value); }
};

int main() {
    BinaryTree tree;

    int values[] = {1, 2, 3, 4, 5, 6, 7};
    for (int i = 0; i < 7; i++) {
        tree.insert(values[i]);
    }

    cout << "Level order: ";
    tree.levelOrder();
    cout << "Inorder:     ";
    tree.inorder();
    cout << "Preorder:    ";
    tree.preorder();
    cout << "Postorder:   ";
    tree.postorder();

    cout << "Height: " << tree.height() << endl;
    cout << "Total nodes: " << tree.countNodes() << endl;
    cout << "Is 5 present? " << (tree.search(5) ? "Yes" : "No") << endl;
    cout << "Is 9 present? " << (tree.search(9) ? "Yes" : "No") << endl;

    return 0;
}
