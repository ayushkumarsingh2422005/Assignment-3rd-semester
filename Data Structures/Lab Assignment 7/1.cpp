#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// 1. Write a program to create a Binary Tree.
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

// 5. Write an recursive program to traverse a binary tree using the following
// traversal:
// a. Inorder Traversal
// b. Preorder Traversal
// c. Postorder Traversal
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

// LinkedListNode
struct LinkedListNode {
    Node* data;
    LinkedListNode* next;
};
// ....................

// queue implementation
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

// stack implementation
struct Stack {
   private:
    LinkedListNode* head;

    // Insert a new LinkedListNode with Node* before the first element
    LinkedListNode* insertBeforeFirst(LinkedListNode* head, Node* nodeData) {
        LinkedListNode* temp = new LinkedListNode{nodeData, nullptr};
        temp->next = head;
        return temp;
    }

    // Delete the first LinkedListNode
    LinkedListNode* deleteFirst(LinkedListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        LinkedListNode* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

   public:
    Node* top;  // Now `top` stores Node* instead of string

    Stack() {
        head = NULL;
        top = nullptr;
    }

    void push(Node* nodeData) {
        head = insertBeforeFirst(head, nodeData);  // Insert the Node*
        top = nodeData;  // Update the top pointer to the latest Node*
    }

    Node* pop() {
        if (head == NULL) {
            top = nullptr;
            return top;
        } else {
            Node* nodeData =
                head->data;  // Get the Node* stored in the first LinkedListNode
            head = deleteFirst(head);  // Remove the first LinkedListNode
            if (head == NULL) {
                top = nullptr;
            } else {
                top = head->data;  // Update top to the new first Node* in the
                                   // stack
            }
            return nodeData;  // Return the popped Node*
        }
    }

    bool isEmpty() { return head == NULL; }
};
// ....................

// 7. Write a program to perform level-order traversal of a binary tree.
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

// 5. Write an iterative program to traverse a binary tree using the following
// traversal:
// a. Inorder Traversal
// b. Preorder Traversal
// c. Postorder Traversal

void inorder_iterative(Node* root) {
    if (root == NULL) return;
    Stack stack;
    Node* current = root;
    while (!stack.isEmpty() || current != NULL) {
        while (current != NULL) {
            stack.push(current);
            current = current->left;
        }
        current = stack.pop();
        cout << current->data << " ";
        current = current->right;
    }
}
void preorder_iterative(Node* root) {
    if (root == NULL) return;
    Stack stack;
    stack.push(root);
    while (!stack.isEmpty()) {
        Node* tempNode = stack.pop();
        cout << tempNode->data << " ";
        if (tempNode->right != NULL) {
            stack.push(tempNode->right);
        }
        if (tempNode->left != NULL) {
            stack.push(tempNode->left);
        }
    }
}
void postorder_iterative(Node* root) {
    if (root == NULL) return;
    Stack stack1, stack2;
    stack1.push(root);
    while (!stack1.isEmpty()) {
        Node* tempNode = stack1.pop();
        stack2.push(tempNode);
        if (tempNode->left != NULL) {
            stack1.push(tempNode->left);
        }
        if (tempNode->right != NULL) {
            stack1.push(tempNode->right);
        }
    }
    while (!stack2.isEmpty()) {
        cout << stack2.pop()->data << " ";
    }
}

// 8. Write a program to generate tree from a given Pre-order and Inorder
// Traversal of a binary tree.
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

// 11.Write a program to count the total number of nodes in a binary tree
int totalnode(Node* root) {
    int l, r;
    if (root == NULL) return 0;
    l = totalnode(root->left);
    r = totalnode(root->right);
    return l + r + 1;
}

// 12.Write a program to count the number of following nodes in a binary tree:
// a. Nodes with Degree Zero (0)
// b. Nodes with Degree One (1)
// c. Nodes with Degree Two (2)
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

// 10.Write a program to count the height of a binary tree
int height(Node* root) {
    if (root == NULL) return -1;
    int l = height(root->left);
    int r = height(root->right);
    return 1 + (l > r ? l : r);
}

// 2. Write a program to determine if a binary tree is
// a. Strict binary tree
// b. Complete
// c. Almost complete
bool isStrictBinaryTree(Node* root) {
    return !(totalNodeDeg1(root) > 0);
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
    cout << "\nPreorder iterative : ";
    preorder_iterative(tree);

    cout << "\nInorder : ";
    inorder(tree);
    cout << "\nInorder iterative : ";
    inorder_iterative(tree);

    cout << "\nPostorder : ";
    postorder(tree);
    cout << "\nPostorder iterative : ";
    postorder_iterative(tree);

    cout << "\nLevelOrder : ";
    levelorder(tree);

    cout << "\nTotal Nodes in tree : " << totalnode(tree);
    cout << "\nTotal Nodes with degree 0 : " << totalNodeDeg0(tree);
    cout << "\nTotal Nodes with degree 1 : " << totalNodeDeg1(tree);
    cout << "\nTotal Nodes with degree 2 : " << totalNodeDeg2(tree);
    cout << "\nHeight of tree : " << height(tree) + 1;
    cout << "\nIs tree strict binary tree? "
         << (isStrictBinaryTree(tree)? "Yes" : "No");

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
