#include <iostream>
using namespace std;

void towerOfHanoi(double n, double x, double y, double z) {
    if (n == 1) {
        cout << "Move disk 1 from rod A to rod C" << endl;
        return;
    }
    towerOfHanoi(n - 1, 'A', 'C', 'B');
    cout << "Move disk " << n << " from rod A to rod C" << endl;
    towerOfHanoi(n - 1, 'B', 'A', 'C');
}
int main(int argc, char const *argv[])
{
    double n;
    cout << "Enter the number of disks: ";
    cin >> n;
    towerOfHanoi(n, 'A', 'B', 'C');
    return 0;
}
