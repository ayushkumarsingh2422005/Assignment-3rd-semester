#include <stdio.h>
int main() {
    int a[] = {0, 4, 7, 10};
    int n = sizeof(a) / sizeof(a[0]);
    int data = 10;
    
    // Binary search
    int left = 0, right = n-1, mid = (right+left)/2;
    while(left <= right) {
        if(a[mid] == data) {
            printf("Element found at index %d\n", mid);
            return 0;
        }
        else if(a[mid] < data)
            left = mid + 1;
        else
            right = mid - 1;
        mid = (right+left)/2;
    }

    return 0;
}
