#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
};

int height(Node* node){
    if(node == nullptr) return 0;
    return node->height;
}

Node* newNode(int data){
    Node* node = new Node();
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1;
    return node;
}

int getBalance(Node* node){
    if(node == nullptr) return 0;
    return height(node->left) - height(node->right);
}

void updateHeight(Node* node){
    node->height = 1 + max(height(node->left), height(node->right));
}

Node* rightRotate(Node* y){
    Node* x = y->left;
    Node* t = x->right;

    x->right = y;
    y->left = t;

    updateHeight(y);
    updateHeight(x);
    return x;
}

Node* leftRotate(Node* x){
    Node* y = x->right;
    Node* t = y->left;

    y->left = x;
    x->right = t;

    updateHeight(x);
    updateHeight(y);
    return y;
}

Node* balance(Node* node){
    updateHeight(node);
    int bf = getBalance(node);

    // LL
    if(bf > 1 && getBalance(node->left) >= 0){
        return rightRotate(node);
    }
    // LR
    if(bf > 1 && getBalance(node->left) < 0){
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    // RR
    if(bf < -1 && getBalance(node->right) <= 0){
        return leftRotate(node);
    }
    // RL
    if(bf < -1 && getBalance(node->right) > 0){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

Node* insert(Node* root, int data){
    if(root == nullptr) return newNode(data);

    if(data < root->data){
        root->left = insert(root->left, data);
    }
    else if(data > root->data){
        root->right = insert(root->right, data);
    }
    else{
        return root;
    }
    return balance(root);
}

Node* findMin(Node* root){
    while(root->left != nullptr){
        root = root->left;
    }
    return root;
}

Node* deleteNode(Node* root, int val){
    if(root == nullptr) return nullptr;

    if(val < root->data){
        root->left = deleteNode(root->left, val);
    }
    else if(val > root->data){
        root->right = deleteNode(root->right, val);
    }
    else{
        if(root->left == nullptr || root->right == nullptr){
            Node* temp = root->left ? root->left : root->right;
            delete root;
            return temp;
        }
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return balance(root);
}

void inorder(Node* root){
    if(root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root){
    if(root == nullptr) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    Node* root = nullptr;
    int arr[] = {10, 20, 30, 40, 50, 25};

    for(int i = 0; i<6; i++){
        root = insert(root, arr[i]);
    }

    cout << "preorder: ";
    preorder(root);
    cout << endl;
    cout << "inorder: ";
    inorder(root);
    cout << endl;
    cout << "root: " << root->data << " height: " << height(root) << endl;

    root = deleteNode(root, 40);
    cout << "preorder: ";
    preorder(root);
    cout << endl;
    cout << "root: " << root->data << " height: " << height(root) << endl;

    return 0;
}
