#include <stdio.h>

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");
}
void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i]   = arr[j];
    arr[j]   = temp;
}
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        swap(arr, min_index, i);
    }
}
int main(int argc, char const *argv[]) {
    int arr[] = {1, 4, 2, 7, 5, 8, 2};
    selectionSort(arr, sizeof(arr) / sizeof(arr[0]));
    printArray(arr, sizeof(arr) / sizeof(arr[0]));
    return 0;
}
