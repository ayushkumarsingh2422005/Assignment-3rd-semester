#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;
int precedence(string x) {
    if (x == "*" || x == "/") {
        return 1;
    } else if (x == "+" || x == "-") {
        return 0;
    } else {
        return -1;
    }
}
bool isNum(string x) {
    if (x == "+" || x == "-" || x == "/" || x == "*") {
        return false;
    }
    return true;
}
int solve(int first, int second, string op) {
    if (op == "*") {
        return first * second;
    }
    if (op == "/") {
        return second / first;
    }
    if (op == "-") {
        return second - first;
    }
    if (op == "+") {
        return second + first;
    }
}
string infixToPostfix(string infix) {
    stack<string> stack;
    string postfix = "";
    for (int i = 0; i < infix.length(); i++) {
        string st(1, infix.at(i));
        if (isNum(st)) {
            postfix += st;
        } else {
            int stackTopPrecedence;
            if (stack.empty()) {
                stackTopPrecedence = -1;
            } else {
                stackTopPrecedence = precedence(stack.top());
            }
            int currentPrecedence = precedence(st);
            if (currentPrecedence > stackTopPrecedence) {
                stack.push(st);
            } else {
                while (currentPrecedence <= stackTopPrecedence &&
                       !stack.empty()) {
                    postfix += stack.top();
                    stack.pop();
                    if (!stack.empty()) {
                        stackTopPrecedence = precedence(stack.top());
                    }
                }
                stack.push(st);
            }
        }
    }

    while (!stack.empty()) {
        postfix += stack.top();
        stack.pop();
    }

    return postfix;
}
string infixToSuffix(string infix) {
    reverse(infix.begin(), infix.end());
    string reversedPostfix = infixToPostfix(infix);
    reverse(reversedPostfix.begin(), reversedPostfix.end());
    return reversedPostfix;
}
int solvePostfix(string postfix) {
    stack<int> stack;
    for (int i = 0; i < postfix.length(); i++) {
        string st(1, postfix.at(i));
        if (isNum(st)) {
            stack.push(stoi(st));
        } else {
            int first_pop = stack.top();
            stack.pop();
            int second_pop = stack.top();
            stack.pop();
            int result = solve(first_pop, second_pop, st);
            stack.push(result);
        }
    }
    return stack.top();
}
string postfixToInfix(string postfix) {
    stack<string> stack;
    string infix = "";
    for (int i = 0; i < postfix.length(); i++) {
        string st(1, postfix.at(i));
        if (isNum(st)) {
            stack.push(st);
        } else {
            string first_pop = stack.top();
            stack.pop();
            string second_pop = stack.top();
            stack.pop();
            string result = second_pop+st+first_pop;
            stack.push(result);
        }
    }
    return stack.top();
}
int main(int argc, char const *argv[]) {
    string infix = "2+3*5+6";
    string postfix = infixToPostfix(infix);
    string suffix = infixToSuffix(infix);
    string post_to_inf = postfixToInfix(postfix);
    int ans = solvePostfix(postfix);
    cout << postfix << endl;
    cout << suffix << endl;
    cout << ans << endl;
    cout << post_to_inf << endl;
    return 0;
}
