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

struct node* deleteLast(struct node* head) {
    if (head == nullptr) {
        return head;
    }
    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }
    struct node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    struct node* delNode = temp->next;
    temp->next = nullptr;
    delete delNode;
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
    head = deleteLast(head); // delete last node
    printLinkedList(head); // print linked list
    return 0;
}