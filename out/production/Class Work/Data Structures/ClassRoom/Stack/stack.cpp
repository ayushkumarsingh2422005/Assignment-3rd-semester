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

    Stack() {
        head = NULL;
        top = "NULL";
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
            head = deleteFirst(head);
            if (head == NULL) {
                top = "NULL";
            } else {
                top = head->data;
            }
            return data;
        }
    }
    bool isEmpty() {
        return head == NULL;
    }
};

int main(int argc, char const* argv[]) {
    Stack stack;
    string str = "[({2+4}*6)/[8]+9-(6)*6+7]";
    bool validated = true;
    for (int i = 0; i < str.size(); i++) {
        char temp = str[i];
        if (temp == '(' || temp == '{' || temp == '[') {
            string temp_str(1, temp);
            stack.push(temp_str);
        }
        if (temp == ')' || temp == '}' || temp == ']') {
            string s = stack.pop();
            if (s == "NULL") {
                validated = false;
                break;
            }
            if (temp == ')' && s != "(") {
                validated = false;
                break;
            }
            if (temp == ']' && s != "[") {
                validated = false;
                break;
            }
            if (temp == '}' && s != "{") {
                validated = false;
                break;
            }
        }
    }
    if (stack.top != "NULL") {
        validated = false;
    }

    cout << validated;
    return 0;
}
