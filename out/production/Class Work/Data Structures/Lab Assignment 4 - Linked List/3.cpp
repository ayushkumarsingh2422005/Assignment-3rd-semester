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

struct node* concat(struct node* head1, struct node* head2) {
    struct node* head = nullptr;
    struct node* tail = nullptr;
    if (head1->data < head2->data) {
        head = tail = head1;
        head1 = head1->next;
    } else {
        head = tail = head2;
        head2 = head2->next;
    }
    while (head1 != nullptr && head2 != nullptr) {
        if (head1->data < head2->data) {
            tail->next = head1;
            head1 = head1->next;
        } else {
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
    }
    if (head1 != nullptr) {
        tail->next = head1;
    } else {
        tail->next = head2;
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
    int arr1[] = {1, 3, 5, 5, 7, 8, 8, 55};
    int arr2[] = {2, 4, 5, 5, 4, 2};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    struct node* head1 = linkedList(arr1, n1);  // create linked list1
    struct node* head2 = linkedList(arr2, n2);  // create linked list2
    struct node* head = concat(head1, head2); // concat
    printLinkedList(head); // print linked list
    return 0;
}