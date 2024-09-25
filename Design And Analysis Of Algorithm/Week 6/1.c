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
int main() {
    // creation of bst
    root = create(2);
    printf("number of data need to input");
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        insert(root, x);
    }
    // inorder printing
    inorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    preorder(root);
}