#include <climits>  // Include this header for INT_MIN and INT_MAX
#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* constructBST(vector<int>& preOrder, int& preIndex, int minVal,
                   int maxVal) {
    if (preIndex >= preOrder.size()) {
        return nullptr;
    }
    int rootVal = preOrder[preIndex];
    if (rootVal < minVal || rootVal > maxVal) {
        return nullptr;
    }
    Node* root = new Node(rootVal);
    preIndex++;
    root->left = constructBST(preOrder, preIndex, minVal, rootVal);
    root->right = constructBST(preOrder, preIndex, rootVal, maxVal);
    return root;
}

void inorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {
    vector<int> preOrder = {100, 50, 20, 70, 200, 150, 300};
    int preIndex = 0;
    int minVal = INT_MIN, maxVal = INT_MAX;
    Node* root = constructBST(preOrder, preIndex, minVal, maxVal);
    cout << "Inorder traversal of the constructed BST: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
