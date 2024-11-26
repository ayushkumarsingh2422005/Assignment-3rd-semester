#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// Insertion in BST
Node* insert(Node* root, int data) {
    if (!root) 
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

// Inorder Traversal
void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// Preorder Traversal
void preorder(Node* root) {
    if (root) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder Traversal
void postorder(Node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

// Search in BST
bool search(Node* root, int key) {
    if (!root)
        return false;
    if (root->data == key)
        return true;
    else if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

// Find Minimum
Node* findMin(Node* root) {
    while (root && root->left)
        root = root->left;
    return root;
}

// Find Maximum
Node* findMax(Node* root) {
    while (root && root->right)
        root = root->right;
    return root;
}

// Deletion in BST
Node* deleteNode(Node* root, int key) {
    if (!root)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
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

// Find Predecessor
Node* findPredecessor(Node* root, int key) {
    Node* predecessor = nullptr;
    while (root) {
        if (key > root->data) {
            predecessor = root;
            root = root->right;
        } else {
            root = root->left;
        }
    }
    return predecessor;
}

// Find Successor
Node* findSuccessor(Node* root, int key) {
    Node* successor = nullptr;
    while (root) {
        if (key < root->data) {
            successor = root;
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return successor;
}

// Main Function
int main() {
    Node* root = nullptr;

    // Insertions
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    // Traversals
    cout << "Inorder Traversal: ";
    inorder(root);
    cout << "\n";

    cout << "Preorder Traversal: ";
    preorder(root);
    cout << "\n";

    cout << "Postorder Traversal: ";
    postorder(root);
    cout << "\n";

    // Search
    int key = 40;
    cout << "Search " << key << ": " << (search(root, key) ? "Found" : "Not Found") << "\n";

    // Minimum and Maximum
    cout << "Minimum Value: " << findMin(root)->data << "\n";
    cout << "Maximum Value: " << findMax(root)->data << "\n";

    // Predecessor and Successor
    Node* predecessor = findPredecessor(root, key);
    Node* successor = findSuccessor(root, key);
    cout << "Predecessor of " << key << ": " << (predecessor ? to_string(predecessor->data) : "None") << "\n";
    cout << "Successor of " << key << ": " << (successor ? to_string(successor->data) : "None") << "\n";

    // Deletion
    root = deleteNode(root, 50);
    cout << "Inorder Traversal after deleting 50: ";
    inorder(root);
    cout << "\n";

    return 0;
}
