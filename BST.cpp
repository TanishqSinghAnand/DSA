#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data){
    Node* node = new Node();
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;
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
    return root;
}

bool search(Node* root, int val){
    if(root == nullptr) return false;
    if(root->data == val) return true;
    if(val < root->data) return search(root->left, val);
    return search(root->right, val);
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
        if(root->left == nullptr){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        if(root->right == nullptr){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
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

void postorder(Node* root){
    if(root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main()
{
    Node* root = nullptr;
    int arr[] = {50, 30, 70, 20, 40, 60, 80};

    for(int i = 0; i<7; i++){
        root = insert(root, arr[i]);
    }

    cout << "inorder: ";
    inorder(root);
    cout << endl;
    cout << "preorder: ";
    preorder(root);
    cout << endl;
    cout << "postorder: ";
    postorder(root);
    cout << endl;

    cout << "search 40: " << search(root, 40) << endl;
    cout << "search 90: " << search(root, 90) << endl;

    root = deleteNode(root, 20);
    inorder(root);
    cout << endl;

    root = deleteNode(root, 30);
    inorder(root);
    cout << endl;

    root = deleteNode(root, 50);
    inorder(root);
    cout << endl;

    return 0;
}
