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

struct node* insertBefore(struct node* head, int before, int data) {
    if (head == nullptr) {
        return nullptr;
    }
    if (head->data == before) {
        struct node* newNode = new node{data, head};
        return newNode;
    }
    struct node* temp1 = head->next;
    struct node* temp2 = head;
    while (temp1 != nullptr) {
        if (temp1->data == before) {
            struct node* newNode = new node{data, temp1};
            temp2->next = newNode;
            return head;
        }
        temp2 = temp1;
        temp1 = temp1->next;
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
    head = insertBefore(head, 5, 50); // insert before
    printLinkedList(head); // print linked list
    return 0;
}