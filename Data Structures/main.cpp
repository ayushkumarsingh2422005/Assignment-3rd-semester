#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct Node* linkedList(vector<int>& arr) {
    // int n = arr.size();
    // if (n == 0) return nullptr;

    // struct Node* head = new Node{arr.at(0), nullptr};
    // struct Node* temp = head;
    // for (int i = 1; i < n; i++) {
    //     temp->next = new Node{arr.at(i), nullptr};
    //     temp = temp->next;
    // }
    // temp->next = head;  // Make the list circular
    // return head;

    int n = arr.size();
    if (n == 0) return nullptr;

    Node* head = new Node{arr[0]};
    Node* temp = head;
    for (int i = 1; i < n; i++) {
        temp->next = new Node{arr[i]};
        temp = temp->next;
    }
    return head;
}

void printLinkedList(struct Node* head) {
    if (head == nullptr) return;

    struct Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);  // Stop when we reach the head again
    cout << endl;
}

int main(int argc, char const* argv[]) {
    vector<int> vecArray = {1, 2, 3, 4, 5, 6, 7};
    struct Node* head = linkedList(vecArray);
    printLinkedList(head);
    return 0;
}
