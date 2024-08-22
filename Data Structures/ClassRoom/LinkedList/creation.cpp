#include <iostream>
using namespace std;

struct node {
    int data;
    struct node* next;
};

struct node* linkedList(int arr[], int size) {
    if (size <= 0) return nullptr; // Handle empty array case

    struct node* head = new node();
    head->data = arr[0];
    struct node* current = head;

    for (int i = 1; i < size; i++) {
        current->next = new node();
        current = current->next;
        current->data = arr[i];
    }
    current->next = nullptr; // Set the last node's next to nullptr
    return head;
}

int main(int argc, char const* argv[]) {
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array
    struct node* first = linkedList(arr, size);
    
    // Optional: Print the linked list to verify
    struct node* current = first;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    // Free the allocated memory (not shown here for brevity)
    
    return 0;
}
