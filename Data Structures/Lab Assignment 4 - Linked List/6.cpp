#include <iostream>
using namespace std;

struct node {
    int data;
    struct node* next;
};

struct node* linkedList(int arr[], int n) {
    struct node* head = new node{arr[0], nullptr};
    struct node* temp = head;
    for (int i = 1; i < n; i++) {
        temp->next = new node{arr[i], nullptr};
        temp = temp->next;
    }
    return head;
}

struct node* reverseLinkedList(struct node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;  // If the list is empty or has only one node, return the
                      // head (no change needed)
    }

    struct node* newHead =
        nullptr;  // This will be the head of the new reversed list
    struct node* current = head;

    while (current != nullptr) {
        struct node* newNode = new node{
            current->data, nullptr};  // Create a new node with the current data
        newNode->next =
            newHead;        // Point the new node's next to the current newHead
        newHead = newNode;  // Move the newHead to the new node
        current = current->next;  // Move to the next node in the original list
    }

    return newHead;  // Return the head of the new reversed list
}

bool isPalindrome(struct node* head) {
    struct node* reversed = reverseLinkedList(head);
    struct node* temp = head;
    while (reversed != nullptr) {
        if (reversed->data != temp->data) {
            return false;
        }

        reversed = reversed->next;
        temp = temp->next;
    }
    return true;
}

void printLinkedList(struct node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 3, 5, 5, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    struct node* head = linkedList(arr, n);  // create linked list
    cout << isPalindrome(head);
    return 0;
}