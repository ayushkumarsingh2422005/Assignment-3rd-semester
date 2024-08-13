#include <iostream>
using namespace std;

struct realtype
{
    int left;
    int right;
};

int real(struct realtype number){
    return number.left;
}
int main(int argc, char const *argv[])
{
    int left, right;
    cout << "Enter the left part of decimal point : ";
    cin >> left;
    cout << "Enter the right part of decimal point : ";
    cin >> right;
    struct realtype number = {left, right};

    cout << "real part : " << real(number) << endl;
    cout << "actual number : " << number.left << "." << number.right <<endl;

    return 0;
}
