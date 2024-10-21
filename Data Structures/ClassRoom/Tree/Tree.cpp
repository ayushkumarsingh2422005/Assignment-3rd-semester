#include <iostream>
#include <queue>
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
void levelOrder(Node* root) {
    queue<Node*> que;
    if (root == NULL) {
        return;
    }

    que.push(root);
    while (!que.empty()) {
        Node* tempNode = que.front();
        que.pop();
        cout << tempNode->data << " ";
        if (tempNode->left != NULL) {
            que.push(tempNode->left);
        }
        if (tempNode->right != NULL) {
            que.push(tempNode->right);
        }
    }
}
Node* search(Node* root, int data) {
    Node* temp = root;
    while (temp != NULL) {
        if (data == temp->data) {
            return temp;
            break;
        }
        if (data > temp->data) {
            temp = temp->right;
        } else {
            temp = temp->left;
        }
    }
    return NULL;
}
Node* deleteNodePre(Node* root, int data) {
    Node* temp = search(root, data);
    if (temp == NULL) return root;
    Node* temp2 = temp;
    if (temp2->right != NULL) temp2 = temp2->right;
    while (temp2->left->left != NULL) {
        temp2 = temp2->left;
    }
    temp->data = temp2->left->data;
    delete(temp2->left);
    temp2->left = NULL;
    return root;
}
int main() {
    Node* root = createNode(100);
    root = insertData(root, 200);
    root = insertData(root, 50);
    root = insertData(root, 150);
    root = insertData(root, 300);
    root = insertData(root, 20);
    root = insertData(root, 70);
    // root = insertData(root, 120);
    // root = insertData(root, 110);
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

    // LevelOrder Traversal
    cout << "LevelOrder Traversal: ";
    levelOrder(root);
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

    deleteNodePre(root, 100);
    cout << "LevelOrder Traversal: ";
    levelOrder(root);

    return 0;
}
