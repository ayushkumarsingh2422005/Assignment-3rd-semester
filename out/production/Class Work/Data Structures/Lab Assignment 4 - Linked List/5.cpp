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

struct node* removeAlternate(struct node* head) {
    struct node* tail = head;

    while (tail != nullptr && tail->next != nullptr) {
        struct node* delNode = tail->next;  // The node to be deleted
        tail->next = delNode->next;         // Bypass the node
        delete delNode;  // Free the memory of the deleted node

        tail = tail->next;  // Move to the next node
    }
    return head;
}


void printLinkedList(struct node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 3, 5, 5, 7, 8, 8, 55};
    int n = sizeof(arr) / sizeof(arr[0]);
    struct node* head = linkedList(arr, n);  // create linked list
    head = removeAlternate(head); // delete alternate node
    printLinkedList(head); // print linked list
    return 0;
}