#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int data) {
    if (root == NULL) return createNode(data);
    Node* newNode = createNode(data);
    Node* tempRoot = root;

    while (true) {
        if (tempRoot->data < data) {
            if (tempRoot->right == NULL) {
                tempRoot->right = newNode;
                return root;
            }
            tempRoot = tempRoot->right;
        } else if (tempRoot->data > data) {
            if (tempRoot->left == NULL) {
                tempRoot->left = newNode;
                return root;
            }
            tempRoot = tempRoot->left;
        }
    }
}
void inOrder(Node* root){
    if (!root) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
int height(Node* root){
    if (!root) return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return max(leftHeight, rightHeight) + 1;
}
int checkAvl(Node* root){
    int leftHeight = root->left?height(root->left):0;
    int rightHeight = root->right?height(root->right):0;
    if (abs(leftHeight - rightHeight) > 1) return 0;
    return 1;
}
int main(int argc, char const* argv[]) {
    Node* root = createNode(100);
    root = insertNode(root, 150);
    root = insertNode(root, 50);
    root = insertNode(root, 20);
    root = insertNode(root, 70);
    root = insertNode(root, 120);
    root = insertNode(root, 200);
    inOrder(root);
    cout << "\nis AVL : " << checkAvl(root);
    return 0;
}
