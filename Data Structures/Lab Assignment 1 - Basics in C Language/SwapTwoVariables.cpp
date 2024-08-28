#include <iostream>

void swap1(int &a, int &b) {
    a = a + b;
    b = a - b;
    a = a - b;
}

void swap2(int &a, int &b) {
    a = a * b;
    b = a / b;
    a = a / b;
}

void swap3(int &a, int &b) {
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

int main() {
    int a = 5, b = 10;

    std::cout << "Original: " << a << ", " << b << std::endl;

    swap1(a, b);
    std::cout << "After swap1: " << a << ", " << b << std::endl;

    swap2(a, b);
    std::cout << "After swap2: " << a << ", " << b << std::endl;

    swap3(a, b);
    std::cout << "After swap3: " << a << ", " << b << std::endl;

    return 0;
}
