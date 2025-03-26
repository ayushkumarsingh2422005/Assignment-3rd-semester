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
    struct Node* result = NULL;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = temp->data;
    newNode->next = NULL;
    newNode->prev = NULL;
    result = newNode;
    temp = temp->next;
    while (temp != NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = temp->data;
        result->prev = newNode;
        newNode->next = result;
        newNode->prev = NULL;
        result = result->prev;
        temp = temp->next;
    }
    return result;
}
struct Node* insertAtFirst(struct Node* head, int data) {
    struct Node* tempNode = (struct Node*)malloc(sizeof(struct Node));
    tempNode->data = data;
    tempNode->next = head;
    tempNode->prev = NULL;
    head->prev = tempNode;
    head = tempNode;
    return head;
}
Node* insertBetween(Node* head, int data, int n) {
    Node* tempNode = (Node*)malloc(sizeof(Node));
    Node* temp = head;
    tempNode->data = data;
    tempNode->next = NULL;
    tempNode->prev = NULL;
    int pos = 0;
    while (temp->next != NULL) {
        if (n == pos) {
            tempNode->prev = temp->prev;
            temp->prev->next = tempNode;
            temp->prev = tempNode;
            tempNode->next = temp;
            return head;
        }
        temp = temp->next;
        pos++;
    }
    return head;

}
// void deletion(Node* head){
//     Node* temp = head;
//     head=head->next;
//     head->prev=NULL;
//     temp->next=NULL;
//     delete temp;
//     // return head;
// }
Node* update(Node* head){
    int pos=0;
    while (){
        if
    }

}


int main(int argc, char const* argv[]) {
    struct Node* head = createLinedList();
    // head = insertBetween(head, 10, 3);5
    // deletion(head);
    Node *temp = head;
    head = head->next;
    delete temp;
    printLinkedList(head);
    // cout << temp->data;
    return 0;
}
