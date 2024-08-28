#include <stdio.h>

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    while (i <= j) {
        while (i <= high && arr[i] <= pivot) {
            i++;
        }
        while (j >= low && arr[j] >= pivot) {
            j--;
        }
        if (i < j) {
            swap(arr, i, j);
        }
    }
    swap(arr, low, j);
    return j;
}

void helperSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        helperSort(arr, low, pivotIndex - 1);
        helperSort(arr, pivotIndex + 1, high);
    } else {
        return;
    }
}
void quickSort(int arr[], int size) { helperSort(arr, 0, size - 1); }
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");
}
int main(int argc, char const *argv[]) {
    int arr[] = {9, 1, 8, 2, 7, 3, 4, 6, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, size);
    printArray(arr, size);
    return 0;
}
