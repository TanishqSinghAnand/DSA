#include <iostream>
#include <queue>
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
    Node* node = newNode(data);
    if(root == nullptr) return node;

    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp->left == nullptr){
            temp->left = node;
            break;
        }
        q.push(temp->left);

        if(temp->right == nullptr){
            temp->right = node;
            break;
        }
        q.push(temp->right);
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

void levelOrder(Node* root){
    if(root == nullptr) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
}

int height(Node* root){
    if(root == nullptr) return 0;
    return max(height(root->left), height(root->right)) + 1;
}

int countNodes(Node* root){
    if(root == nullptr) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

bool search(Node* root, int val){
    if(root == nullptr) return false;
    if(root->data == val) return true;
    return search(root->left, val) || search(root->right, val);
}

int main()
{
    Node* root = nullptr;
    for(int i = 1; i<=7; i++){
        root = insert(root, i);
    }

    cout << "level: ";
    levelOrder(root);
    cout << endl;
    cout << "inorder: ";
    inorder(root);
    cout << endl;
    cout << "preorder: ";
    preorder(root);
    cout << endl;
    cout << "postorder: ";
    postorder(root);
    cout << endl;

    cout << "height: " << height(root) << endl;
    cout << "nodes: " << countNodes(root) << endl;
    cout << "search 5: " << search(root, 5) << endl;
    cout << "search 9: " << search(root, 9) << endl;

    return 0;
}
