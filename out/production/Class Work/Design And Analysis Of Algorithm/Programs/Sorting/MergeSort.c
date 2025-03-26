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

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    for (int i=0; i<n1; i++) L[i] = arr[left + i];
    for (int j=0; j<n2; j++) R[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
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
}
void helper(int arr[], int left, int right) {
    if (left >= right){
        return;
    }
    int mid = (left+right)/2;
    helper(arr, left, mid);
    helper(arr, mid+1, right);
    merge(arr, left, mid, right);
}
void mergeSort(int arr[], int n){
    helper(arr, 0, n);
}

int main(int argc, char const *argv[]) {
    int arr[] = {1, 4, 2, 7, 5, 8, 2};
    mergeSort(arr, sizeof(arr) / sizeof(arr[0]));
    printArray(arr, sizeof(arr) / sizeof(arr[0]));
    return 0;
}