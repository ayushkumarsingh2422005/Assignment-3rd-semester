#include <iostream>
using namespace std;

struct node {
    int data;
    struct node* next;
};

struct node* linkedList(int arr[], int n) {
    if (n == 0) return NULL;
    
    struct node* head = (struct node*)malloc(sizeof(struct node));
    if (head == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    head->data = arr[0];
    head->next = NULL;
    
    struct node* temp = head;
    for (int i = 1; i < n; i++) {
        temp->next = (struct node*)malloc(sizeof(struct node));
        if (temp->next == NULL) {
            printf("Memory allocation failed.\n");
            exit(1);
        }
        temp = temp->next;
        temp->data = arr[i];
        temp->next = NULL;
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
    printLinkedList(head); // print linked list
    return 0;
}