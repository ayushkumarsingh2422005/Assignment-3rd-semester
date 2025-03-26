#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

Node* insertNode(Node* root, int data) {
    if (!root) return new Node(data);
    if (data >= root->data) root->right = insertNode(root->right, data);
    else root->left = insertNode(root->left, data);
    return root;
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void levelorder(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* node = q.front();
        q.pop();
        cout << node->data << " ";
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
}

void inorder_iterative(Node* root) {
    stack<Node*> s;
    Node* current = root;
    while (!s.empty() || current) {
        while (current) {
            s.push(current);
            current = current->left;
        }
        current = s.top();
        s.pop();
        cout << current->data << " ";
        current = current->right;
    }
}

void preorder_iterative(Node* root) {
    if (!root) return;
    stack<Node*> s;
    s.push(root);
    while (!s.empty()) {
        Node* node = s.top();
        s.pop();
        cout << node->data << " ";
        if (node->right) s.push(node->right);
        if (node->left) s.push(node->left);
    }
}

void postorder_iterative(Node* root) {
    if (!root) return;
    stack<Node*> s1, s2;
    s1.push(root);
    while (!s1.empty()) {
        Node* node = s1.top();
        s1.pop();
        s2.push(node);
        if (node->left) s1.push(node->left);
        if (node->right) s1.push(node->right);
    }
    while (!s2.empty()) {
        cout << s2.top()->data << " ";
        s2.pop();
    }
}

int searchInOrder(int inOrder[], int start, int end, int value) {
    for (int i = start; i <= end; i++)
        if (inOrder[i] == value) return i;
    return -1;
}

Node* btUsingPreAndInOrder(int preOrder[], int inOrder[], int start, int end, int& preIndex) {
    if (start > end) return nullptr;
    Node* root = new Node(preOrder[preIndex++]);
    if (start == end) return root;
    int inIndex = searchInOrder(inOrder, start, end, root->data);
    root->left = btUsingPreAndInOrder(preOrder, inOrder, start, inIndex - 1, preIndex);
    root->right = btUsingPreAndInOrder(preOrder, inOrder, inIndex + 1, end, preIndex);
    return root;
}

int totalNodes(Node* root) {
    if (!root) return 0;
    return 1 + totalNodes(root->left) + totalNodes(root->right);
}

int totalNodeDeg0(Node* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    return totalNodeDeg0(root->left) + totalNodeDeg0(root->right);
}

int totalNodeDeg1(Node* root) {
    if (!root) return 0;
    int count = (root->left == nullptr) ^ (root->right == nullptr) ? 1 : 0;
    return count + totalNodeDeg1(root->left) + totalNodeDeg1(root->right);
}

int totalNodeDeg2(Node* root) {
    if (!root) return 0;
    int count = (root->left && root->right) ? 1 : 0;
    return count + totalNodeDeg2(root->left) + totalNodeDeg2(root->right);
}

int height(Node* root) {
    if (!root) return -1;
    return 1 + max(height(root->left), height(root->right));
}

bool isStrictBinaryTree(Node* root) {
    return totalNodeDeg1(root) == 0;
}

int main() {
    Node* tree = new Node(100);
    insertNode(tree, 200);
    insertNode(tree, 50);
    insertNode(tree, 70);
    insertNode(tree, 20);
    insertNode(tree, 150);
    insertNode(tree, 250);

    cout << "Preorder: ";
    preorder(tree);
    cout << "\nPreorder iterative: ";
    preorder_iterative(tree);

    cout << "\nInorder: ";
    inorder(tree);
    cout << "\nInorder iterative: ";
    inorder_iterative(tree);

    cout << "\nPostorder: ";
    postorder(tree);
    cout << "\nPostorder iterative: ";
    postorder_iterative(tree);

    cout << "\nLevelOrder: ";
    levelorder(tree);

    cout << "\nTotal Nodes: " << totalNodes(tree);
    cout << "\nNodes with degree 0: " << totalNodeDeg0(tree);
    cout << "\nNodes with degree 1: " << totalNodeDeg1(tree);
    cout << "\nNodes with degree 2: " << totalNodeDeg2(tree);
    cout << "\nHeight: " << height(tree) + 1;
    cout << "\nIs strict binary tree? " << (isStrictBinaryTree(tree) ? "Yes" : "No");

    int preOrder[] = {100, 50, 20, 70, 200, 150, 250};
    int inOrder[] = {20, 50, 70, 100, 150, 200, 250};
    int preIndex = 0;
    Node* root = btUsingPreAndInOrder(preOrder, inOrder, 0, 6, preIndex);
    cout << "\nInorder traversal of constructed tree: ";
    inorder(root);

    return 0;
}
