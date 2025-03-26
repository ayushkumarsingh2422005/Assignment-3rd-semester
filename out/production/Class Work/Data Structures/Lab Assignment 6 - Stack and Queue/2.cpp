#include <iostream>
#include <algorithm>
#include "./1.cpp"  // Updated Stack implementation for strings
using namespace std;

bool isOperand(char ch) { return isalnum(ch); }
int precedence(char ch) {
    return (ch == '^') ? 3 : (ch == '*' || ch == '/') ? 2 : (ch == '+' || ch == '-') ? 1 : 0;
}

string reverseBrackets(string exp) {
    for (char &ch : exp) {
        if (ch == '(') ch = ')';
        else if (ch == ')') ch = '(';
    }
    return exp;
}

string infixToPostfix(string infix) {
    Stack stack;
    string postfix = "";
    for (char ch : infix) {
        if (isOperand(ch)) postfix += ch;
        else {
            while (!stack.isEmpty() && precedence(ch) <= precedence(stack.top[0]))
                postfix += stack.pop();
            stack.push(string(1, ch));
        }
    }
    while (!stack.isEmpty()) postfix += stack.pop();
    return postfix;
}

string postfixToInfix(string postfix) {
    Stack stack;
    for (char ch : postfix) {
        if (isOperand(ch)) stack.push(string(1, ch));
        else {
            string b = stack.pop(), a = stack.pop();
            stack.push("(" + a + ch + b + ")");
        }
    }
    return stack.pop();
}

// Derive infixToPrefix using infixToPostfix
string infixToPrefix(string infix) {
    reverse(infix.begin(), infix.end());
    string reversedInfix = reverseBrackets(infix);
    string postfix = infixToPostfix(reversedInfix);
    reverse(postfix.begin(), postfix.end());
    return postfix;
}

// Derive postfixToPrefix by combining postfixToInfix and infixToPrefix
string postfixToPrefix(string postfix) {
    string infix = postfixToInfix(postfix);
    return infixToPrefix(infix);
}

// Derive prefixToInfix by reversing the prefix and treating it as a postfix
string prefixToInfix(string prefix) {
    reverse(prefix.begin(), prefix.end());
    string infix = postfixToInfix(prefix);
    return infix;
}

// Derive prefixToPostfix by combining prefixToInfix and infixToPostfix
string prefixToPostfix(string prefix) {
    string infix = prefixToInfix(prefix);
    return infixToPostfix(infix);
}

int main() {
    string infix = "5+4+3*2", postfix = "54+32*+", prefix = "+5+4*32";

    cout << "Infix to Postfix:\t" << infixToPostfix(infix) << endl;
    cout << "Infix to Prefix:\t" << infixToPrefix(infix) << endl;
    cout << "Postfix to Infix:\t" << postfixToInfix(postfix) << endl;
    cout << "Postfix to Prefix:\t" << postfixToPrefix(postfix) << endl;
    cout << "Prefix to Infix:\t" << prefixToInfix(prefix) << endl;
    cout << "Prefix to Postfix:\t" << prefixToPostfix(prefix) << endl;

    return 0;
}
