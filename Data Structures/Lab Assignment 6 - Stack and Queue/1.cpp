#include <iostream>
#include <limits>
using namespace std;

struct Node {
    char data;
    Node* next;
};

struct Stack {
   private:
    Node* head;
    Node* insertBeforeFirst(Node* head, char data) {
        Node* temp = new Node{data, nullptr};
        temp->next = head;
        return temp;
    }
    Node* deleteFirst(Node* head) {
        if (head == NULL) {
            return head;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

   public:
    char top;
    Stack() {
        head = NULL;
        top = '\0';
    }
    void push(char data) {
        head = insertBeforeFirst(head, data);
        top = data;
    }
    char pop() {
        if (head == NULL) {
            top = '\0';
            return top;
        } else {
            char data = head->data;
            head = deleteFirst(head);
            if (head == NULL) {
                top = '\0';
            } else {
                top = head->data;
            }
            return data;
        }
    }
    bool isEmpty() { return head == NULL; }
    void view() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
};

// int main() {
//     Stack stack;
//     // stack.push('a');
//     // stack.push('b');
//     // stack.push('c');
//     // stack.push('d');
//     stack.view();
//     stack.pop();
//     cout << stack.pop();
//     stack.view();
//     cout << stack.top;
//     return 0;
// }
