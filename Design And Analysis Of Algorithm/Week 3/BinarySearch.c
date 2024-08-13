#include <stdio.h>

int binarySearch(int arr[], int target, int n) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
        return mid;
        else if (arr[mid] < target)
        left = mid + 1;
        else if (arr[mid] > target)
        right = mid - 1;
    }
    return -1;
}
int main(int argc, char const *argv[])
{
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n); 

    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int target;
    printf("Enter the target element: ");
    scanf("%d", &target);
    printf("number found at index = %d\n", binarySearch(arr, target, n));
    return 0;
}
