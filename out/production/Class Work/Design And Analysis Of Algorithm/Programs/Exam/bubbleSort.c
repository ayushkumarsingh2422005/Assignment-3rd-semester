#include <stdio.h>
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");
}
void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr, j, j+1);
            }
        }
    }
}
int main(int argc, char const *argv[]) {
    int arr[] = {1, 4, 2, 7, 5, 8, 2};
    bubbleSort(arr, sizeof(arr) / sizeof(arr[0]));
    printArray(arr, sizeof(arr) / sizeof(arr[0]));
    return 0;
}
