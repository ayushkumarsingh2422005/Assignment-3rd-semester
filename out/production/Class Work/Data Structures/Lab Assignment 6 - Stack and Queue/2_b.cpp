#include <algorithm>
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

string infixToPrefix(string infix) {
    reverse(infix.begin(), infix.end());
    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
        } else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }
    string postfix = infixToPostfix(infix);
    reverse(postfix.begin(), postfix.end());
    return postfix;
}

int main() {
    string infix = "5+4+3*2";
    string postfix = infixToPostfix(infix);
    string prefix = infixToPrefix(infix);
    cout << "Infix expression:\t" << infix << endl;
    cout << "Postfix expression:\t" << postfix << endl;
    cout << "Prefix expression:\t" << prefix << endl;
    return 0;
}
