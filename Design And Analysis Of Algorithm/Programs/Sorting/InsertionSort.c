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

void insertionSort(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        int key = i;
        while ( arr[key - 1] > arr[key] && key > 0){
            swap(arr, key, key - 1);
            key--;
        }
    }
    
}

int main(int argc, char const *argv[]) {
    int arr[] = {1, 4, 2, 7, 5, 8, 2};
    insertionSort(arr, sizeof(arr) / sizeof(arr[0]));
    printArray(arr, sizeof(arr) / sizeof(arr[0]));
    return 0;
}