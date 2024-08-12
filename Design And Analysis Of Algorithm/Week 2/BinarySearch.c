#include <stdio.h>

int binarySearch(int *arr, int target, int size){
    int start = 0;
    int end = size-1;
    int operation = 0;
    while (start <= end)
    {
        operation++;
        int mid = start + (end - start)/2;
        if (arr[mid] == target)
        {
            printf("Number of Operations : %d\n", operation);
            return mid;
        }
        if (arr[mid] < target)
        {
            start = mid + 1;
        }
        if (arr[mid] > target)
        {
            end = mid - 1;
        }
    }
    printf("Number of Operations : %d\n", operation);
    return -1;
}

int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(arr)/sizeof(arr[0]);
    int target;
    scanf("%d", &target);
    printf("Number found at index : %d\n", binarySearch(arr, target, size));
    return 0;
}
