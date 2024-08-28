#include <stdio.h>

void merge(int arr[], int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[low + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    return;
}

void helperSort(int arr[], int low, int high) {
    if (low >= high) {
        return;
    }
    int mid = low + (high - low) / 2;
    helperSort(arr, low, mid);
    helperSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

void mergeSort(int arr[], int n) { helperSort(arr, 0, n - 1); }

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n");
}
int main(int argc, char const *argv[]) {
    int arr[] = {9, 1, 8, 2, 7, 3, 4, 6, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, size);
    printArray(arr, size);
    return 0;
}
