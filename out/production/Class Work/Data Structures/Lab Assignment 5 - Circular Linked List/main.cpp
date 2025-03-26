#include <iostream>
#include <cstdlib>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};

// Function to create a circular linked list from an array
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

// Function to insert a node at the beginning of the list
void insertAtBeginning(Node*& head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = head;
    Node* temp = head;
    
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    head = newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(Node*& head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = head;
    
    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to delete a node at the beginning of the list
void deleteAtBeginning(Node*& head) {
    if (head == NULL) return;
    Node* temp = head;
    
    Node* last = head;
    while (last->next != head) {
        last = last->next;
    }
    
    head = head->next;
    last->next = head;
    free(temp);
}

// Function to traverse and print the circular linked list
void traverse(Node* head) {
    if (head == NULL) return;
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

// Function to search an element in the circular linked list
bool search(Node* head, int key) {
    Node* temp = head;
    do {
        if (temp->data == key) return true;
        temp = temp->next;
    } while (temp != head);
    return false;
}

// Function to sort the circular linked list
void sortList(Node* head) {
    if (head == NULL) return;
    Node* current = head;
    Node* index = NULL;
    int temp;
    do {
        index = current->next;
        while (index != head) {
            if (current->data > index->data) {
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
            index = index->next;
        }
        current = current->next;
    } while (current->next != head);
}

// Function to update a node value
void update(Node* head, int oldValue, int newValue) {
    Node* temp = head;
    do {
        if (temp->data == oldValue) {
            temp->data = newValue;
            return;
        }
        temp = temp->next;
    } while (temp != head);
    cout << "Value " << oldValue << " not found!" << endl;
}

int main() {
    Node* head = NULL;
    int choice, value, searchValue, oldValue, newValue;
    int arr[] = {5, 12, 7, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // Create circular linked list
    head = circularLinkedList(arr, n);
    
    while (true) {
        cout << "\n--- Circular Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Delete at Beginning\n";
        cout << "4. Traverse\n";
        cout << "5. Search\n";
        cout << "6. Sort\n";
        cout << "7. Update\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at beginning: ";
                cin >> value;
                insertAtBeginning(head, value);
                break;
            case 2:
                cout << "Enter value to insert at end: ";
                cin >> value;
                insertAtEnd(head, value);
                break;
            case 3:
                deleteAtBeginning(head);
                cout << "Deleted node at beginning.\n";
                break;
            case 4:
                cout << "Circular Linked List: ";
                traverse(head);
                break;
            case 5:
                cout << "Enter value to search: ";
                cin >> searchValue;
                if (search(head, searchValue))
                    cout << "Value found.\n";
                else
                    cout << "Value not found.\n";
                break;
            case 6:
                sortList(head);
                cout << "List sorted.\n";
                break;
            case 7:
                cout << "Enter old value to update: ";
                cin >> oldValue;
                cout << "Enter new value: ";
                cin >> newValue;
                update(head, oldValue, newValue);
                break;
            case 8:
                cout << "Exiting...\n";
                exit(0);
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
    
    return 0;
}
