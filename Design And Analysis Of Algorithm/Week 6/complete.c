#include <stdio.h>
#include <stdlib.h>

// Define the structure of the BST node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new BST node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to find the minimum value node in a BST
struct Node* findMin(struct Node* root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete a node from the BST
struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) {
        return root;
    }
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function for inorder traversal of the BST
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Function for preorder traversal of the BST
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Function for postorder traversal of the BST
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Function to search for a node in the BST
struct Node* search(struct Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return search(root->left, data);
    }
    return search(root->right, data);
}

// Function to find the predecessor of a node in the BST
struct Node* findPredecessor(struct Node* root, struct Node* node) {
    if (node->left != NULL) {
        return findMin(node->left);
    }
    struct Node* predecessor = NULL;
    while (root != NULL) {
        if (node->data > root->data) {
            predecessor = root;
            root = root->right;
        } else if (node->data < root->data) {
            root = root->left;
        } else {
            break;
        }
    }
    return predecessor;
}

// Function to find the successor of a node in the BST
struct Node* findSuccessor(struct Node* root, struct Node* node) {
    if (node->right != NULL) {
        return findMin(node->right);
    }
    struct Node* successor = NULL;
    while (root != NULL) {
        if (node->data < root->data) {
            successor = root;
            root = root->left;
        } else if (node->data > root->data) {
            root = root->right;
        } else {
            break;
        }
    }
    return successor;
}

// Function to find the minimum value in the BST
int findMinimum(struct Node* root) {
    struct Node* minNode = findMin(root);
    return (minNode != NULL) ? minNode->data : -1;
}

// Function to find the maximum value in the BST
int findMaximum(struct Node* root) {
    struct Node* current = root;
    while (current && current->right != NULL) {
        current = current->right;
    }
    return (current != NULL) ? current->data : -1;
}

// Main function
int main() {
    struct Node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");

    printf("Minimum value in the BST: %d\n", findMinimum(root));
    printf("Maximum value in the BST: %d\n", findMaximum(root));

    int searchVal = 40;
    struct Node* searchResult = search(root, searchVal);
    if (searchResult != NULL) {
        printf("Node %d found in the BST.\n", searchVal);
    } else {
        printf("Node %d not found in the BST.\n", searchVal);
    }

    root = deleteNode(root, 20);
    printf("Inorder traversal after deleting 20: ");
    inorder(root);
    printf("\n");

    struct Node* node = search(root, 30);
    struct Node* predecessor = findPredecessor(root, node);
    struct Node* successor = findSuccessor(root, node);
    if (predecessor != NULL) {
        printf("Predecessor of %d: %d\n", node->data, predecessor->data);
    } else {
        printf("No predecessor found for %d\n", node->data);
    }
    if (successor != NULL) {
        printf("Successor of %d: %d\n", node->data, successor->data);
    } else {
        printf("No successor found for %d\n", node->data);
    }

    return 0;
}
