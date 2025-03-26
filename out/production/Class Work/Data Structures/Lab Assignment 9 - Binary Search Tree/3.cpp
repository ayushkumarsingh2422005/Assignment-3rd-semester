// Searching in BST
// a. Write a program that allows searching for an element using recursion. The program
// must handle edge cases, such as:
// • An empty tree (return a suitable message).
// • Duplicate entries (only one instance should be stored in the BST).
// • The program should support multiple search attempts for different elements
// after tree construction.
// b. Extend the BST to support non-recursive (iterative) search implementation.

#include <iostream>

using namespace std;

// Node structure

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new node

Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to insert a node into the BST

Node* insert(Node* root, int data) {
    if (root == NULL) {
        root = newNode(data);
        return root;
    }

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

// Function to search for an element using recursion

bool search(Node* root, int data) {
    if (root == NULL) {
        cout << "Element not found in the tree." << endl;
        return false;
    }

    if (root->data == data)
        return true;

    if (data < root->data)
        return search(root->left, data);
    else
        return search(root->right, data);
}

// Function to search for an element using non-recursive (iterative) search

bool iterativeSearch(Node* root, int data) {
    if (root == NULL) {
        cout << "Element not found in the tree." << endl;
        return false;
    }

    Node* current = root;

    while (current != NULL) {
        if (current->data == data)
            return true;

        if (data < current->data)
            current = current->left;
        else
            current = current->right;
    }

    cout << "Element not found in the tree." << endl;
    return false;
}

// Main function

int main() {
    Node* root = NULL;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    int data;

    cout << "Enter the element to search: ";
    cin >> data;

    cout << "Searching using recursion..." << endl;
    if (search(root, data))
        cout << "Element found in the tree." << endl;

    cout << "Searching using iterative..." << endl;
    if (iterativeSearch(root, data))
        cout << "Element found in the tree." << endl;

    return 0;
}