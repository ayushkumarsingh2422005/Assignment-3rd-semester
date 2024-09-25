#include <stdio.h>
#include <stdlib.h>  // For malloc

struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Function to create a new node
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new node in the binary search tree
struct node* insert(struct node* root, int x) {
    if (root == NULL) {
        struct node* newnode = (struct node*)(malloc(sizeof(struct node)));
        if (newnode == NULL) {
            printf("Memory allocation failed\n");
            return NULL;
        }
        newnode->data = x;
        newnode->left = NULL;
        newnode->right = NULL;
        return newnode;
    }
    if (x >= root->data) {
        root->right = insert(root->right, x);
    } else {
        root->left = insert(root->left, x);
    }
    return root;
}

// In-order traversal to print the BST
void inorder(struct node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Pre-order traversal to print the BST
void preorder(struct node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    inorder(root->left);
    inorder(root->right);
}

// Post-order traversal to print the BST
void postorder(struct node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    inorder(root->right);
    printf("%d ", root->data);
}

// height of tree
int height(struct node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}

// is balanced binery tree
int balanced(struct node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if (abs(leftHeight - rightHeight) > 1) return -1;
    if (leftHeight == -1 || rightHeight == -1)
        return -1;  // unbalanced tree detected

    return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}

// diameter of tree
int maxDiameter = 0;  // Global variable to store maximum diameter
int max(int a, int b) { return (a > b) ? a : b; }
int diameter(struct node* root) {
    if (root == NULL) return 0;

    int leftHeight = diameter(root->left);
    int rightHeight = diameter(root->right);

    maxDiameter = max(maxDiameter, leftHeight + rightHeight + 1);
    return max(leftHeight, rightHeight) + 1;
}

// minimum element
int minValue(struct node* root) {
    struct node* current = root;
    while (current && current->left != NULL) current = current->left;
    return current->data;
}

// maximum element
int maxValue(struct node* root) {
    struct node* current = root;
    while (current && current->right != NULL) current = current->right;
    return current->data;
}

// Search value
int searchValue(struct node* root, int value) {
    if (root == NULL) return 0;
    if (value == root->data) return 1;
    if (value < root->data) {
        return searchValue(root->left, value);
    } else {
        return searchValue(root->right, value);
    }
}

// find Predecessor
int findPredec(struct node* root, int value) {
    if (root == NULL) {
        return -1;
    }
    if (root->data == value) {
        return -1;
    }

    struct node* temp = root;
    struct node* prev = NULL;
    while (temp != NULL) {
        if (temp->data == value) {
            return prev->data;
        } else if (temp->data > value) {
            prev = temp;
            temp = temp->left;
        } else {
            prev = temp;
            temp = temp->right;
        }
    }

    return -1;
}

// find Successor
int findSucce(struct node* root, int value) {
    if (root == NULL) {
        return -1;
    }

    struct node* temp = root;
    while (temp != NULL) {
        if (temp->data == value) {
            if (temp->left == NULL) {
                return -1;
            }
            return temp->left->data;
        } else if (temp->data > value) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }

    return -1;
}

// delete the node
void deleteUtility(struct node* temp) {
    if (temp == NULL) return;
    if (temp->left == NULL) {
        struct node* rightChild = temp->right;
        free(temp);
        temp = rightChild;
    } else if (temp->right == NULL) {
        struct node* leftChild = temp->left;
        free(temp);
        temp = leftChild;
    } else {
        int succValue = minValue(temp->right);
        temp->data = succValue;
        deleteUtility(temp->right);
    }
}
void deleteNode(struct node* root, int key) {
    if (root == NULL) return;
    struct node* temp = root;
    while (temp != NULL) {
        if (key == temp->data) {
            deleteUtility(temp);
        } else if (key > temp->data) {
            temp = temp->right;
        } else {
            temp = temp->left;
        }
    }
}

int main(int argc, char const* argv[]) {
    struct node* root = NULL;

    // Insert nodes into the tree
    root = insert(root, 100);
    root = insert(root, 20);
    root = insert(root, 200);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 150);
    root = insert(root, 300);

    // Print the tree in in-order traversal (sorted order)
    printf("In-order traversal of the BST: ");
    inorder(root);
    printf("\n");

    // Print the tree in pre-order traversal
    printf("Pre-order traversal of the BST: ");
    preorder(root);
    printf("\n");

    // Print the tree in post-order traversal (reversed sorted order)
    printf("Post-order traversal of the BST: ");
    postorder(root);
    printf("\n");

    // Calculate and print the height of the tree
    int treeHeight = height(root);
    printf("Height of the BST: %d\n", treeHeight);

    // Check if the tree is balanced
    int isBalanced = balanced(root);
    if (isBalanced == -1) {
        printf("The BST is not balanced.\n");
    } else {
        printf("The BST is balanced with height: %d\n", isBalanced - 1);
    }

    // Calculate and print the diameter of the tree
    diameter(root);
    printf("Diameter of the BST: %d\n", maxDiameter);

    // Find and print the minimum element in the tree
    int minElement = minValue(root);
    printf("Minimum element in the BST: %d\n", minElement);

    // Find and print the maximum element in the tree
    int maxElement = maxValue(root);
    printf("Maximum element in the BST: %d\n", maxElement);

    // Search for a value in the tree
    int searchValue_ = 25;
    int found = searchValue(root, searchValue_);

    if (found) {
        printf("%d found in the BST.\n", searchValue_);
    } else {
        printf("%d not found in the BST.\n", searchValue_);
    }

    // finding Predecessor
    int predecessor = findPredec(root, 1);
    printf("Predecer of %d is %d", 150, predecessor);

    // finding Successor
    int successor = findSucce(root, 100);
    printf("\nSuccessor of %d is %d", 150, successor);

    // Delete a node from the tree
    int deleteValue = 150;
    deleteNode(root, deleteValue);
    printf("\nAfter deleting %d, the BST is: ", deleteValue);
    inorder(root);
    printf("\n");

    return 0;
}
