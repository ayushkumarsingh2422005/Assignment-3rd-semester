#include <iostream>
using namespace std;

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");
}
void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr, j, j + 1);
            }
        }
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int temp = i;
        while (arr[temp] < arr[temp - 1] && temp > 0) {
            swap(arr, temp, temp - 1);
            temp--;
        }
    }
}

int main() {
    int arr[] = {2, 6, 3, 7, 3, 1, 8, 9};
    insertionSort(arr, 8);
    printArray(arr, 8);
    return 0;
}
