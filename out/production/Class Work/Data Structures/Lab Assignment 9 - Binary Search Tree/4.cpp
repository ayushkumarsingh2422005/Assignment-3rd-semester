// Write a program to delete an element from a BST.

#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return(node);
}

// Function to insert a node in BST

struct Node* insert(struct Node* node, int data) {
    if (node == NULL) return(newNode(data));

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);

    return node;
}

// Function to delete a node from BST

struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}

struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) return root;
    if (data < root->data){
        root->left = deleteNode(root->left, data);
        return root;
    }
    if (data > root->data){
        root->right = deleteNode(root->right, data);
        return root;
    }
    if (root->left == NULL){
        struct Node* temp = root->right;
        free(root);
        return temp;
    }
    if (root->right == NULL){
        struct Node* temp = root->left;
        free(root);
        return temp;
    }
    struct Node* temp = minValueNode(root->right);
    root->data = temp->data;
    root->right = deleteNode(root->right, temp->data);
    return root;
}

// Function to print inorder traversal of BST

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Driver program to test above functions

int main() {
    struct Node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Inorder traversal of the constructed BST is \n");
    inorder(root);

    root = deleteNode(root, 20);
    printf("\nInorder traversal after deleting 20 \n");
    inorder(root);

    root = deleteNode(root, 70);
    printf("\nInorder traversal after deleting 30 \n");
    inorder(root);
}