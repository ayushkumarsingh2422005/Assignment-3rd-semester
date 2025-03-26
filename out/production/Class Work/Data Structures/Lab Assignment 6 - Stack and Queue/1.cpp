#include <iostream>
using namespace std;

struct Node {
    string data;
    Node* next;
    Node(string d, Node* n = nullptr) : data(d), next(n) {}
};

struct Stack {
    Node* head;
    string top;

    Stack() : head(nullptr), top("") {}

    void push(string data) {
        head = new Node(data, head);
        top = data;
    }

    string pop() {
        if (!head) return "";
        string data = head->data;
        Node* temp = head;
        head = head->next;
        delete temp;
        top = head ? head->data : "";
        return data;
    }

    bool isEmpty() { return !head; }

    void view() {
        for (Node* temp = head; temp; temp = temp->next)
            cout << temp->data << ' ';
        cout << endl;
    }
};


// int main() {
//     Stack stack;

//     cout << "Pushing elements: a, b, c, d" << endl;
//     stack.push('a');
//     stack.push('b');
//     stack.push('c');
//     stack.push('d');
//     cout << "Current stack: ";
//     stack.view();

//     cout << "Popping two elements..." << endl;
//     cout << "Popped: " << stack.pop() << ", " << stack.pop() << endl;
//     cout << "Current stack: ";
//     stack.view();

//     cout << "Top of the stack: " << stack.top << endl;
//     return 0;
// }
