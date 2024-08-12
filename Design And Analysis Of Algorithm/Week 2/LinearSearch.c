#include <stdio.h>

int linerSerach(int *arr, int target, int size){
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}
int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(arr)/sizeof(arr[0]);
    int target;
    scanf("%d", &target);
    printf("%d\n", linerSerach(arr, target, size));
    return 0;
}
