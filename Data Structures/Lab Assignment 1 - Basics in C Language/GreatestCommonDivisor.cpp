#include <iostream>

using namespace std;

int gcd(int x, int y){
    if (y == 0)
        return x;
    return gcd(y, x % y);
}

int main(int argc, char const *argv[])
{
    cout << gcd(15, 10);
    return 0;
}
