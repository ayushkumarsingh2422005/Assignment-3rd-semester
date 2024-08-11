#include <iostream>
using namespace std;
void merge(int *arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

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
}

void mergeSort(int *arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void sort(int *arr, int len) {
    mergeSort(arr, 0, len - 1);
}

int main()
{
    int arr[] = {4, 242, 99, 78, 97, 19, 23, 51, 0, 81, 92, 87, 53};
    int size = sizeof(arr) / sizeof(arr[0]);
    sort(arr, size);
    int ans[size];
    int start = 0;
    int end = size - 1;
    for (int i = 0; i < size; i++)
    {
        if (i % 2 == 0)
        {
            ans[i] = arr[start];
            start++;
        }
        else
        {
            ans[i] = arr[end];
            end--;
        }
    }
    for (int i = 0; i < size; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
