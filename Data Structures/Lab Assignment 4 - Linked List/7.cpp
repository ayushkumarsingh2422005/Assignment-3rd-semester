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
        return head;
    }

    struct node* newHead = nullptr;
    struct node* current = head;

    while (current != nullptr) {
        struct node* newNode = new node{current->data, nullptr};
        newNode->next = newHead;
        newHead = newNode;
        current = current->next;
    }

    return newHead;
}

void printLinkedList(struct node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 3, 5, 4, 6, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    struct node* head = linkedList(arr, n);  // create linked list
    head = reverseLinkedList(head);
    printLinkedList(head);  // print reversed linked list
    return 0;
}