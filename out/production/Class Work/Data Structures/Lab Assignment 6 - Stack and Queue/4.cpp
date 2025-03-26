#include <iostream>
#include <limits>
using namespace std;

struct Node {
    string data;
    Node* next;  // Use `Node*` instead of `struct node*`
};

struct Stack {
   private:
    Node* head;
    Node* insertBeforeFirst(Node* head, string data) {
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
    string top;
    int size = 0;

    Stack() {
        head = NULL;
        top = "NULL";
    }

    void push(string data) {
        head = insertBeforeFirst(head, data);
        top = data;
        size++;
    }
    string pop() {
        if (head == NULL) {
            top = "NULL";
            return top;
        } else {
            string data = head->data;
            head = deleteFirst(head);
            if (head == NULL) {
                top = "NULL";
            } else {
                top = head->data;
            }
            return data;
        }
        if (size > 0) {
            size--;
        }
    }
    bool isEmpty() { return head == NULL; }
    void view() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

string* mergeStack(Stack& stack1, Stack& stack2) {
    int totalSize = stack1.size + stack2.size;
    string* mergedStack = new string[totalSize];
    int i = 0;
    while (!stack1.isEmpty()) {
        mergedStack[i++] = stack1.pop();
    }
    while (!stack2.isEmpty()) {
        mergedStack[i++] = stack2.pop();
    }
    return mergedStack;
}

int main(int argc, char const* argv[]) {
    Stack stack1;
    Stack stack2;

    stack1.push("A");
    stack1.push("B");
    stack1.push("C");
    stack2.push("a");
    stack2.push("b");
    stack2.push("c");
    stack2.push("c");
    stack2.push("c");

    cout << "Stack 1: ";
    stack1.view();
    cout << "Stack 2: ";
    stack2.view();
    cout << "Merged Stack Size: " << stack1.size + stack2.size << endl;
    string* merged = mergeStack(stack1, stack2);
    cout << "Merged Stack: ";
    for (int i = 0; i < stack1.size + stack2.size; i++) {
        cout << merged[i] << " ";
    }

    return 0;
}
