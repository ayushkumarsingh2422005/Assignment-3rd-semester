#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};
struct Node* circularLinkedList(int arr[], int size) {
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = arr[0];
    head->next = NULL;
    struct Node* temp = head;
    for (int i = 1; i < size; i++) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = arr[i];
        newNode->next = NULL;
        temp->next = newNode;
        temp = temp->next;
    }
    temp->next = head;
    return head;
}
struct Node* deleteFirst(struct Node* head) {
    if (head == NULL) {
        return NULL;
    }
    struct Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = head->next;
    return temp->next;
}

void printLinkedList(struct Node* head) {
    struct Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
}

int main(int argc, char const* argv[]) {
    int arr[] = {1, 55, 2, 56, 1, 2, 3, 45};
    int n = sizeof(arr) / sizeof(arr[0]);
    struct Node* head = circularLinkedList(arr, n);
    head = deleteFirst(head);
    printLinkedList(head);
    return 0;
}