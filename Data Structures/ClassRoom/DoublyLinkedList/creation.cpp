#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createLinedList() {
    int n;
    cout << "Enter number of elements : ";
    cin >> n;
    n--;
    cout << "Enter data : ";
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    cin >> head->data;
    head->prev = NULL;
    head->next = NULL;
    struct Node* temp = head;
    while (n--) {
        struct Node* tempNode = (struct Node*)malloc(sizeof(struct Node));
        cin >> tempNode->data;
        tempNode->next = NULL;
        tempNode->prev = temp;
        temp->next = tempNode;
        temp = temp->next;
    }
    // cout << temp->prev->prev->next->data << endl;
    return head;
}

void printLinkedList(struct Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

struct Node* reverseLinkedList(struct Node* head) {
    struct Node* temp = head;
    struct Node* result = new Node();
    result->data = temp->data;  // Initialize result with the first node's data
    result->prev = NULL;
    result->next = NULL;
    
    struct Node* tail = result;  // Keep track of the end of the reversed list
    
    while (temp->next != NULL) {
        struct Node* newNode = new Node();
        newNode->data = temp->next->data;
        
        newNode->next = result->prev;
        newNode->prev = result;
        result->prev = newNode;
        
        temp = temp->next;
        result = newNode;
    }
    
    return tail;  // Return the head of the reversed list
}

int main(int argc, char const* argv[]) {
    struct Node* head = createLinedList();
    struct Node* reversed = reverseLinkedList(head);
    printLinkedList(head);
    printLinkedList(reversed);
    return 0;
}
