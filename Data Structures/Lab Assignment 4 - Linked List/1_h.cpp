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

struct node* deleteNthElement(struct node* head, int n) {
    if (head == nullptr) {
        return head;
    }
    if (n == 0) {
        struct node* delNode = head;
        head = head->next;
        delete delNode;
        return head;
    }
    int index = 0;
    struct node* prev = nullptr;
    struct node* temp = head;
    while (temp != nullptr) {
        if (index == n) {
            struct node* delNode = temp;
            prev->next = temp->next;
            delete delNode;
            return head;
        }
        prev = temp;
        temp = temp->next;
        index++;
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
    head = deleteNthElement(head, 4); // delete nth node
    printLinkedList(head); // print linked list
    return 0;
}