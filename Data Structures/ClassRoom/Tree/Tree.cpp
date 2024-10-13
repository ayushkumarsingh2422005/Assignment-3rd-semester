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

Node* insertData(Node* root, int data) {
    Node* temp = root;
    while (temp != NULL) {
        if (data > temp->data) {
            if (temp->right == NULL) {
                temp->right = createNode(data);
                return root;
            } else {
                temp = temp->right;
            }
        } else {
            if (temp->left == NULL) {
                temp->left = createNode(data);
                return root;
            } else {
                temp = temp->left;
            }
        }
    }
    return root;  // Added to ensure the function always returns a value
}

void preorder(Node* root) {
    if (root == NULL) {
        int i = 1;
        cout << i;
        i++;
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void inorder(Node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int level(Node* root) {
    if (root == NULL) {
        return 0;
    }
    int left = level(root->left);
    int right = level(root->right);
    return max(left, right) + 1;
}
int countZeroDegree(Node* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    int left = countZeroDegree(root->left);
    int right = countZeroDegree(root->right);
    return left + right;
}
int countOneDegree(Node* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL ^ root->right == NULL) {
        return 1;
    }
    int left = countOneDegree(root->left);
    int right = countOneDegree(root->right);
    return left + right;
}
int countTwoDegree(Node* root) {
    if (root == NULL) {
        return 0;
    }
    int count = 0;
    if (root->left != NULL && root->right != NULL) {
        count = 1;
    }
    int left = countTwoDegree(root->left);
    int right = countTwoDegree(root->right);
    return left + right + count;
}
int main() {
    Node* root = createNode(100);
    root = insertData(root, 200);
    root = insertData(root, 50);
    root = insertData(root, 150);
    root = insertData(root, 300);
    root = insertData(root, 20);
    root = insertData(root, 70);
    // root = insertData(root, 1000);

    // Preorder Traversal
    cout << "Preorder Traversal: ";
    preorder(root);
    cout << endl;

    // Postorder Traversal
    cout << "Postorder Traversal: ";
    postorder(root);
    cout << endl;

    // Inorder Traversal
    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    // level count
    cout << "Level Count: ";
    cout << level(root) << endl;

    // zero count
    cout << "Zero Degree Count: ";
    cout << countZeroDegree(root) << endl;

    // one count
    cout << "One Degree Count: ";
    cout << countOneDegree(root) << endl;

    // two count
    cout << "Two Degree Count: ";
    cout << countTwoDegree(root) << endl;

    return 0;
}
