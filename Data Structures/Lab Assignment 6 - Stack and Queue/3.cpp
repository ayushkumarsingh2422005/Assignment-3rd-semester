#include <iostream>
using namespace std;

struct Node {
    string data;
    Node* next;
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
        top = '\0';
    }
    void push(string data) {
        head = insertBeforeFirst(head, data);
        top = data;
    }
    string pop() {
        if (head == NULL) {
            top = '\0';
            return top;
        } else {
            string data = head->data;
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

int evaluatePostfix(string postfix[], int depth) {
    Stack st;
    for (int i = 0; i < depth; i++) {
        string s = postfix[i];
        if (s == "*" || s == "+" || s == "-" || s == "/") {
            string s1 = st.pop();
            string s2 = st.pop();
            int num1 = stoi(s1);
            int num2 = stoi(s2);
            if (s == "+") {
                st.push(to_string(num1 + num2));
            } else if (s == "*") {
                st.push(to_string(num1 * num2));
            } else if (s == "/") {
                st.push(to_string(num1 / num2));
            } else if (s == "-") {
                st.push(to_string(num1 - num2));
            }
        } else {
            st.push(s);
        }
    }
    return stoi(st.top);
}
int main() {
    string postfix[] = {"5", "4", "+", "3", "2", "*", "+"};
    int size = sizeof(postfix) / sizeof(postfix[0]);
    int ans = evaluatePostfix(postfix, size);
    cout << "Result: " << ans << endl;
    return 0;
}
