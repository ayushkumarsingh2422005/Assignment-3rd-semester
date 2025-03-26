#include <iostream>
#include <stack>
#include <limits.h>

using namespace std;

struct MinStack {
    stack<int> s;
    stack<int> minStack;
    MinStack() {
        minStack.push(INT_MAX);
    }
    void push(int val) {
        s.push(val);
        minStack.push(min(val, minStack.top()));
    }
    void pop() {
        if (!s.empty()) {
            s.pop();
            minStack.pop();
        }
    }
    int top() {
        if (!s.empty()) {
            return s.top();
        }
        return -1;
    }
    int getMin() {
        return minStack.top();
    }
};

int main() {
    MinStack minStack;
    minStack.push(5);
    minStack.push(3);
    minStack.push(7);
    minStack.push(2);
    cout << "Minimum element: " << minStack.getMin() << endl; // 2
    minStack.pop();
    cout << "Minimum element after pop: " << minStack.getMin() << endl; // 3
    cout << "Top element: " << minStack.top() << endl; // 7
    return 0;
}
