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

struct node* insertAfterLast(struct node* head, int data) {
    struct node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    struct node* newNode = new node{data, nullptr};
    temp->next = newNode;
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
    head = insertAfterLast(head, 5); // insert after last
    printLinkedList(head); // print linked list
    return 0;
}