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
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        int min_idx = i;
        for (int j = i; j < size; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(arr, i, min_idx);
    }
}
int main(int argc, char const *argv[]) {
    int arr[] = {1, 4, 2, 7, 5, 8, 2};
    selectionSort(arr, sizeof(arr) / sizeof(arr[0]));
    printArray(arr, sizeof(arr) / sizeof(arr[0]));
    return 0;
}
