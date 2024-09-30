#include <stdio.h>

int maxElement(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) max = arr[i];
    }
    return max;
}
void countSort(int arr[], int size){
    int max_element = maxElement(arr, size);
    int sorted[max_element + 1];
    for (int i = 0; i <= max_element; i++) {
        sorted[i] = 0;
    }
    for (int i = 0; i < size; i++) {
        sorted[arr[i]] += 1;
    }
    int j = 0;
    for (int i = 0; i <= max_element; i++) {
        while (sorted[i]--) {
            arr[j++] = i;
        }
    }
    
}
int main(int argc, char const *argv[]) {
    int arr[] = {1, 9, 8, 3, 7, 4, 6, 5, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    countSort(arr, size);
    printf("Sorted array in non-decreasing order:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
