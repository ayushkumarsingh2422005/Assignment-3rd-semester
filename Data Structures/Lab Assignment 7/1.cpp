#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};
Node* createTree(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->right = NULL;
    node->left = NULL;
    return node;
}
Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        return createTree(data);
    }
    if (data >= root->data) {
        root->right = insertNode(root->right, data);
    } else {
        root->left = insertNode(root->left, data);
    }

    return root;
}

void preorder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// queue implementation
struct LinkedListNode {
    Node* data;
    LinkedListNode* next;
};
struct Queue {
   private:
    LinkedListNode* front;
    LinkedListNode* rear;

   public:
    Queue() {
        front = NULL;
        rear = NULL;
    }
    void enque(Node* data) {
        LinkedListNode* temp = new LinkedListNode{data, NULL};

        if (rear == NULL) {
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }
    Node* deque() {
        if (front == NULL) {
            return NULL;
        }
        LinkedListNode* temp = front;
        Node* data = front->data;
        front = front->next;
        if (front == NULL) {
            rear = NULL;
        }

        delete temp;
        return data;
    }
    bool isEmpty() { return front == NULL; }
};

// ....................

void levelorder(Node* root) {
    if (root == NULL) return;
    Queue queue;
    queue.enque(root);
    while (!queue.isEmpty()) {
        Node* tempNode = queue.deque();
        cout << tempNode->data << " ";
        if (tempNode->left != NULL) {
            queue.enque(tempNode->left);
        }
        if (tempNode->right != NULL) {
            queue.enque(tempNode->right);
        }
    }
}

// binery tree using inorder and pre order
int searchInOrder(int inOrder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inOrder[i] == value) {
            return i;
        }
    }
    return -1;
}

Node* btUsingPreAndInOrder(int preOrder[], int inOrder[], int start, int end,
                           int& preIndex) {
    if (start > end) {
        return NULL;
    }
    Node* root = createTree(preOrder[preIndex]);
    preIndex++;
    if (start == end) {
        return root;
    }
    int inIndex = searchInOrder(inOrder, start, end, root->data);
    root->left =
        btUsingPreAndInOrder(preOrder, inOrder, start, inIndex - 1, preIndex);
    root->right =
        btUsingPreAndInOrder(preOrder, inOrder, inIndex + 1, end, preIndex);
    return root;
}

int totalnode(Node* root) {
    int l, r;
    if (root == NULL) return 0;
    l = totalnode(root->left);
    r = totalnode(root->right);
    return l + r + 1;
}
int totalNodeDeg0(Node* root) {
    int l, r;
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    l = totalNodeDeg0(root->left);
    r = totalNodeDeg0(root->right);
    return l + r;
}
int totalNodeDeg1(Node* root) {
    int l, r;
    if (root == NULL) return 0;
    int count = 0;
    if (root->left == NULL ^ root->right == NULL) count = 1;
    l = totalNodeDeg1(root->left);
    r = totalNodeDeg1(root->right);
    return l + r + count;
}
int totalNodeDeg2(Node* root) {
    int l, r;
    if (root == NULL) return 0;
    int count = 0;
    if (root->left != NULL && root->right != NULL) count = 1;
    l = totalNodeDeg2(root->left);
    r = totalNodeDeg2(root->right);
    return l + r + count;
}
int height(Node* root){
    if (root == NULL) return -1;
    int l = height(root->left);
    int r = height(root->right);
    return 1+(l>r?l:r);
}

int main(int argc, char const* argv[]) {
    Node* tree = createTree(100);
    insertNode(tree, 200);
    insertNode(tree, 50);
    insertNode(tree, 70);
    insertNode(tree, 20);
    insertNode(tree, 150);
    insertNode(tree, 250);

    cout << "Preorder : ";
    preorder(tree);
    cout << "\nInorder : ";
    inorder(tree);
    cout << "\nPostorder : ";
    postorder(tree);
    cout << "\nLevelOrder : ";
    levelorder(tree);

    cout << "\nTotal Nodes in tree : " << totalnode(tree);
    cout << "\nTotal Nodes with degree 0 : " << totalNodeDeg0(tree);
    cout << "\nTotal Nodes with degree 1 : " << totalNodeDeg1(tree);
    cout << "\nTotal Nodes with degree 2 : " << totalNodeDeg2(tree);
    cout << "\nHeight of tree : " << height(tree)+1;

    // Preorder : 100 50 20 70 200 150 250
    // Inorder : 20 50 70 100 150 200 250

    int preOrder[] = {100, 50, 20, 70, 200, 150, 250};
    int inOrder[] = {20, 50, 70, 100, 150, 200, 250};
    int size = sizeof(inOrder) / sizeof(inOrder[0]);
    int preIndex = 0;
    Node* root = btUsingPreAndInOrder(preOrder, inOrder, 0, size - 1, preIndex);
    cout << "\nInorder traversal of constructed tree: ";
    inorder(root);

    return 0;
}
