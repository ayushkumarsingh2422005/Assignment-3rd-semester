#include <iostream>
using namespace std;

struct Node {
    string data;
    Node* next;
    Node(string d) : data(d), next(nullptr) {}
};

class Queue {
   private:
    Node *start, *end;

   public:
    Queue() : start(nullptr), end(nullptr) {}

    void enque(string data) {
        Node* temp = new Node(data);
        if (!start) end = temp;
        else start->next = temp;
        start = temp;
    }

    string deque() {
        if (!end) return "";
        string data = end->data;
        Node* temp = end;
        end = end->next;
        delete temp;
        return data;
    }

    bool isEmpty() { return !end; }

    void view() {
        for (Node* temp = end; temp; temp = temp->next)
            cout << (temp == end ? "" : " -> ") << temp->data;
        cout << endl;
    }
};

int main() {
    Queue q;
    q.enque("apple");
    q.enque("banana");
    q.enque("orange");
    q.enque("maroon");
    q.view();
    cout << q.deque() << endl;
    q.view();
    return 0;
}
