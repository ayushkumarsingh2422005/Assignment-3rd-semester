#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// creting BST using recursion

Node* insert(Node* root, int data) {
    Node* newNode = createNode(data);
    if(root == NULL)
        return newNode;
    Node* current = root;
    while(true){
        if(data < current->data){
            if(current->left == NULL){
                current->left = newNode;
                break;
            }
            current = current->left;
        }
        else{
            if(current->right == NULL){
                current->right = newNode;
                break;
            }
            current = current->right;
        }
    }
    return root;
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main(int argc, char const* argv[]) {
    // taking size and element as input from a user and prointing it
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;
    int arr[n];
    cout << "Enter the nodes: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    // creating BST using recursion
    Node* root = NULL;
    for (int i = 0; i < n; i++) root = insert(root, arr[i]);

    // printing inorder traversal of BST
    cout << "Inorder traversal of the BST: ";
    inorder(root);
    cout << endl;
    return 0;
}
