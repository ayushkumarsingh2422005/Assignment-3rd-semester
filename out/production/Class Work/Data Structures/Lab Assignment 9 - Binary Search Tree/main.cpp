#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(NULL), right(NULL) {}
};

// 1. Insert into BST using Recursion
Node* insertRecursive(Node* root, int data) {
    if (!root) return new Node(data);
    if (data < root->data) root->left = insertRecursive(root->left, data);
    else if (data > root->data) root->right = insertRecursive(root->right, data);
    return root;
}

// 2. Insert into BST using Iteration
Node* insertIterative(Node* root, int data) {
    Node* newNode = new Node(data);
    if (!root) return newNode;

    Node* current = root;
    Node* parent = NULL;
    while (current) {
        parent = current;
        if (data < current->data) current = current->left;
        else if (data > current->data) current = current->right;
        else return root; // Avoid duplicates
    }

    if (data < parent->data) parent->left = newNode;
    else parent->right = newNode;
    
    return root;
}

// 3a. Search in BST using Recursion
bool searchRecursive(Node* root, int key) {
    if (!root) return false;
    if (root->data == key) return true;
    else if (key < root->data) return searchRecursive(root->left, key);
    else return searchRecursive(root->right, key);
}

// 3b. Search in BST using Iteration
bool searchIterative(Node* root, int key) {
    while (root) {
        if (root->data == key) return true;
        else if (key < root->data) root = root->left;
        else root = root->right;
    }
    return false;
}

// 4. Delete an element from the BST
Node* findMin(Node* root) {
    while (root->left) root = root->left;
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (!root) return NULL;
    if (key < root->data) root->left = deleteNode(root->left, key);
    else if (key > root->data) root->right = deleteNode(root->right, key);
    else {
        // Node to be deleted found
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
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

// 5. Generate BST from given Preorder traversal
Node* buildBSTFromPreorder(int preorder[], int size) {
    if (size == 0) return NULL;
    
    Node* root = new Node(preorder[0]);
    for (int i = 1; i < size; ++i) {
        insertIterative(root, preorder[i]);
    }
    
    return root;
}

// Helper function to display BST (Inorder Traversal)
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;

    // 1. Insert using Recursion
    root = insertRecursive(root, 50);
    root = insertRecursive(root, 30);
    root = insertRecursive(root, 70);
    root = insertRecursive(root, 20);
    root = insertRecursive(root, 40);
    root = insertRecursive(root, 60);
    root = insertRecursive(root, 80);
    cout << "BST created using Recursion:\n";
    inorder(root); // Should print Inorder Traversal
    cout << endl;

    // 2. Insert using Iteration
    root = insertIterative(root, 10);
    root = insertIterative(root, 90);
    cout << "BST after Iterative Insertions:\n";
    inorder(root); // Should print updated Inorder Traversal
    cout << endl;

    // 3a. Search using Recursion
    int searchKey = 60;
    if (searchRecursive(root, searchKey)) 
        cout << "Element " << searchKey << " found (Recursive)\n";
    else 
        cout << "Element " << searchKey << " not found (Recursive)\n";

    // 3b. Search using Iteration
    searchKey = 25;
    if (searchIterative(root, searchKey)) 
        cout << "Element " << searchKey << " found (Iterative)\n";
    else 
        cout << "Element " << searchKey << " not found (Iterative)\n";

    // 4. Delete a node from BST
    root = deleteNode(root, 70);
    cout << "BST after deletion of 70:\n";
    inorder(root); // Should print Inorder Traversal after deletion
    cout << endl;

    // 5. Build BST from Preorder traversal
    int preorder[] = {100, 50, 150, 30, 60, 130, 170};
    int n = sizeof(preorder) / sizeof(preorder[0]);
    Node* rootFromPreorder = buildBSTFromPreorder(preorder, n);
    cout << "BST created from Preorder:\n";
    inorder(rootFromPreorder); // Should print the BST created from Preorder
    cout << endl;

    return 0;
}
