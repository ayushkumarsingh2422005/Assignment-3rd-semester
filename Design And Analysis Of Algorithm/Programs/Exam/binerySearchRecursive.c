#include <stdio.h>

// Function to perform binary search
int binarySearch(int arr[], int left, int right, int data) {
    if (right >= left) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == data) return mid;
        if (arr[mid] > data)
            return binarySearch(arr, left, mid - 1, data);
        else
            return binarySearch(arr, mid + 1, right, data);
    }
    return -1;
}
int main() {
    int a[] = {0, 4, 7, 10};
    int n = sizeof(a) / sizeof(a[0]);
    int data = 7;
    int left = 0, right = n - 1;
    // Binary search
    printf("Binary search for element %d in array:\n",
           binarySearch(a, left, right, data));
}
