#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    int arr[] = {9, 5, 2, 4, 1, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    int min1 = arr[0];
    int min2 = arr[0];
    for (int i = 0; i < size; i++) {
        if (arr[i] < min1) {
            min2 = min1;
            min1 = arr[i];
        } else if (arr[i] < min2 && arr[i] != min1) {
            min2 = arr[i];
        }
    }
    cout << min1 + min2 << endl;
    return 0;
}
