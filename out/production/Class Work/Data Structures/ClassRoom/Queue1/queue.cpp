#include <iostream>
#include <limits>
using namespace std;

struct Node {
    string data;
    Node* next;  // Use `Node*` instead of `Node*`
};

struct Queue {
   private:
    Node* start;
    Node* end;
    Node* insert(Node* start, string data) {
        if (start == NULL) {
            Node* temp = new Node{data, NULL};
            end = temp;
            return temp;
        }
        Node* temp = new Node{data, NULL};
        start->next = temp;
        start = start->next;
        return start;
    }

    Node* deleteNode(Node* end) {
        if (end->next == NULL) {
            delete end;
            return NULL;
        }
        Node* delNode = end;
        end = end->next;
        delete delNode;
        return end;
    }

   public:
    string rear;
    string front;

    Queue() {
        start = NULL;
        end = NULL;
        rear = "";
        front = "";
    }

    void enque(string data) {
        start = insert(start, data);
        rear = start->data;
        front = end->data;
    }
    string deque() {
        if (end == NULL) {
            front = "";
            return front;
        } else {
            string data = end->data;
            end = deleteNode(end);
            if (end == NULL) {
                front = "";
            } else {
                front = end->data;
            }
            return data;
        }
    }
    bool isEmpty() { return end == NULL; }

    void helper(Node* node) {
        if (node == NULL) {
            // cout << endl;
            return;
        }
        helper(node->next);
        if (node->next == NULL) {
            cout << node->data;
        } else {
            cout << " -> " << node->data;
        }
    }
    void view() {
        Node* temp = end;
        helper(temp);
        cout << endl;
    }
};

int main(int argc, char const* argv[]) {
    Queue queue;
    queue.enque("apple");
    queue.enque("banana");
    queue.enque("orange");
    queue.enque("maroon");
    queue.view();
    cout << queue.deque() << endl;
    cout << queue.rear << endl;
    cout << queue.front << endl;
    return 0;
}
