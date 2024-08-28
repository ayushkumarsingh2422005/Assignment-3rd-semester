#include <iostream>

// Function that uses call by value
void callByValue(int a) {
    a = 20; // Change local copy of the argument
    std::cout << "Inside callByValue: a = " << a << std::endl;
}

// Function that uses call by reference
void callByReference(int &b) {
    b = 30; // Change the actual argument
    std::cout << "Inside callByReference: b = " << b << std::endl;
}

int main() {
    int x = 10, y = 10;

    std::cout << "Before callByValue: x = " << x << std::endl;
    callByValue(x); // Pass by value
    std::cout << "After callByValue: x = " << x << std::endl;

    std::cout << "Before callByReference: y = " << y << std::endl;
    callByReference(y); // Pass by reference
    std::cout << "After callByReference: y = " << y << std::endl;

    return 0;
}
