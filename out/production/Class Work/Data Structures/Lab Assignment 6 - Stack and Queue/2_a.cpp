#include <iostream>

#include "./1.cpp"
using namespace std;

bool isOperand(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') ||
           (ch >= '0' && ch <= '9');
}
int precedence(char ch) {
    switch (ch) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}
string infixToPostfix(string infix) {
    Stack stack;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];
        if (isOperand(ch)) {
            postfix += ch;
        } else {
            while (!stack.isEmpty() &&
                   precedence(ch) <= precedence(stack.top)) {
                postfix += stack.pop();
            }
            stack.push(ch);
        }
    }
    while (!stack.isEmpty()) {
        postfix += stack.pop();
    }
    return postfix;
}

int main() {
    string infix = "5+4+3*2";
    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;
    return 0;
}
