#include <iostream>
using namespace std;
int binarySearch(int *a, int n, int num){
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] == num)
            return mid;
        else if (a[mid] < num)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1; // Element not found in the array
}

int main(int argc, char const *argv[])
{
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    int num = 13;
    int result = binarySearch(arr, n, num);
    cout << result << endl;
    return 0;
}
