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
void swap(struct Node* a, struct Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

struct Node* sort(struct Node* head) {
    if (head == NULL || head->next == head) return head;
    struct Node* end = NULL;
    int swapped;
    do {
        swapped = 0;
        struct Node* current = head;
        while (current->next != end && current->next != head) {
            if (current->data > current->next->data) {
                swap(current, current->next);
                swapped = 1;
            }
            current = current->next;
        }
        end = current;
    } while (swapped);
    return head;
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
    head = sort(head);
    printLinkedList(head);
    return 0;
}
