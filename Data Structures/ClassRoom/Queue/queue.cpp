#include <iostream>
#include <limits>
using namespace std;

struct Node {
    string data;
    Node* next;  // Use `Node*` instead of `Node*`
};

struct Queue {
   private:
    Node* head;
    Node* insertBeforeFirst(Node* head, string data) {
        Node* temp = new Node{data, nullptr};
        temp->next = head;
        return temp;
    }

    Node* deleteLast(Node* head) {
        if (head == nullptr) {
            return head;
        }
        if (head->next == nullptr) {
            delete head;
            return nullptr;
        }
        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        Node* delNode = temp->next;
        temp->next = nullptr;
        delete delNode;
        return head;
    }

   public:
    string top;
    string bottom;

    Queue() {
        head = NULL;
        top = "NULL";
        bottom = "NULL";
    }

    void push(string data) {
        head = insertBeforeFirst(head, data);
        top = data;
    }
    string pop() {
        if (head == NULL) {
            top = "NULL";
            return top;
        } else {
            string data = head->data;
            head = deleteLast(head);
            if (head == NULL) {
                top = "NULL";
            } else {
                top = head->data;
            }
            return data;
        }
    }
    bool isEmpty() { return head == NULL; }
};

int main(int argc, char const* argv[]) {
    Queue queue;
    queue.push("apple");
    queue.push("banana");
    queue.push("orange");
    queue.push("maroon");
    cout << "Top element: " << queue.pop() << endl;
    return 0;
}
