#include <iostream>
using namespace std;

void merge(int arr[], int low, int mid, int high) {
    int left_size = mid - low + 1;
    int right_size = high - mid;
    int left[left_size];
    int right[right_size];
    int l, r;
    for (l = 0; l < left_size; l++) {
        left[l] = arr[low + l];
    }
    for (r = 0; r < right_size; r++) {
        right[r] = arr[mid + 1 + r];
    }
    l = 0, r = 0;
    while (l < left_size && r < right_size) {
        if (left[l] < right[r]) {
            arr[low+l+r] = left[l];
            l++;
        } else {
            arr[low+l+r] = right[r];
            r++;
        }
    }

    while (l < left_size) {
        arr[low+l+r] = left[l];
        l++;
    }
    while (r < right_size) {
        arr[low+l+r] = right[r];
        r++;
    }
}
void helperMerge(int arr[], int low, int high) {
    if (high <= low) {
        return;
    }

    int mid = low + (high - low) / 2;
    helperMerge(arr, low, mid);
    helperMerge(arr, mid + 1, high);
    merge(arr, low, mid, high);
}
void mergeSort(int arr[], int size) { helperMerge(arr, 0, size - 1); }
int main(int argc, char const *argv[]) {
    int arr[] = {2, 7, 8, 6, 9, 2, 1};
    mergeSort(arr, sizeof(arr) / sizeof(arr[0]));
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
