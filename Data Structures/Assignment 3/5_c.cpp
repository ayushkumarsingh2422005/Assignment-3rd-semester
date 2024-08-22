#include <iostream>
#include <cmath>
using namespace std;

struct realtype
{
    int left;
    int right;
};

int digitcount(int n){
    int digits = 0;
    while (n--)
    {
        n /= 10;
        digits++;
    }
    return digits;
}
struct realtype add(struct realtype num1, struct realtype num2){
    struct realtype sum;
    int num1_right_length = digitcount(num1.right);
    int num2_right_length = digitcount(num2.right);
    sum.left = num1.left + num2.left;
    if (num1_right_length > num2_right_length){
        num2.right = pow(10, num1_right_length - num2_right_length)*num2.right;
    } else {
        num1.right = pow(10, num2_right_length - num1_right_length)*num1.right;
    }
    
    sum.right = num1.right + num2.right;
    sum.left += sum.right/100;
    sum.right %= 100;
    return sum;
}

struct realtype sub(struct realtype num1, struct realtype num2){
    struct realtype diff;
    int num1_right_length = digitcount(num1.right);
    int num2_right_length = digitcount(num2.right);
    diff.left = num1.left - num2.left;
    if (num1_right_length > num2_right_length){
        num2.right = pow(10, num1_right_length - num2_right_length)*num2.right;
    } else {
        num1.right = pow(10, num2_right_length - num1_right_length)*num1.right;
    }
    diff.right = num1.right - num2.right;
    if (diff.right < 0){
        diff.left--;
        diff.right += 100;
    }
    return diff;
}
int main(int argc, char const *argv[])
{
    struct realtype number1;
    struct realtype number2;
    struct realtype number3;
    cout << "Enter the real part of 1st decimal number : ";
    cin >> number1.left;
    
    cout << "Enter the real part of 2nd decimal number : ";
    cin >> number2.left;
    cout << "Enter the decimal part of 1st decimal number : ";
    cin >> number1.right;
    cout << "Enter the decimal part of 2nd decimal number : ";
    cin >> number2.right;

    number3 = add(number1, number2);
    cout << "Sum of two decimal numbers : " << number3.left << "." << number3.right << endl;

    number3 = sub(number1, number2);
    cout << "Difference of two decimal numbers : " << number3.left << "." << number3.right << endl;
    return 0;
}
