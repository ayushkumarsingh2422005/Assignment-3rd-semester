#include <stdio.h>

int maxElement(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) max = arr[i];
    }
    return max;
}
void countSortByDigit(int arr[], int size, int exponent) {
    int output[size];
    int count[10] = {0};
    for (int i = 0; i < size; i++) {
        int digit = (arr[i] / exponent) % 10;
        count[digit]++;
    }
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    for (int i = size - 1; i >= 0; i--) {
        int digit = (arr[i] / exponent) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }
    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
    }
}
void radixSort(int arr[], int size) {
    int exp = 1;
    int m = maxElement(arr, size);
    while (m / exp > 0) {
        countSortByDigit(arr, size, exp);
        exp *= 10;
    }
}
int main(int argc, char const* argv[]) {
    int arr[] = {1, 9, 8, 3, 7, 4, 6, 5, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    radixSort(arr, size);
    printf("Sorted array in non-decreasing order:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
