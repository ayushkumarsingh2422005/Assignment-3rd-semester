#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;
node *root = NULL;
// creation of root node
node *create(int x) {
    node *newnode = (node *)(malloc(sizeof(node)));
    newnode->data = x;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
    root->data = x;
    root->left = NULL;
    root->right = NULL;
}
node *insert(node *root, int x) {
    if (root == NULL) {
        node *newnode = (node *)(malloc(sizeof(node)));
        // printf("%d is inserted in bst\n", x);
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
void inorder(node *root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
void postorder(node *root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
void preorder(node *root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
bool search(node *root, int x) {
    if (root == NULL) {
        return false;
    }
    if (root->data == x) {
        return true;
    }
    if (root->data > x) {
        search(root->left, x);
    }
    if (root->data < x) search(root->right, x);
}

int main() {
    // creation of bst
    root = create(2);
    printf("Number of data to input: ");
    int n;
    scanf("%d", &n);  // Corrected scanf usage
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        insert(root, x);
    }

    // Inorder printing
    printf("Inorder traversal:\n");
    inorder(root);
    printf("\n");

    // Postorder printing
    printf("Postorder traversal:\n");
    postorder(root);
    printf("\n");

    // Preorder printing
    printf("Preorder traversal:\n");
    preorder(root);
    printf("\n");

    // Element to search for
    printf("Element to search for: ");
    int s;
    scanf("%d", &s);  // Corrected scanf usage
    if (search(root, s)) {
        printf("Element %d is found\n", s);
    } else {
        printf("Element %d is not found\n", s);
    }
    printf("\n");

    return 0;
}