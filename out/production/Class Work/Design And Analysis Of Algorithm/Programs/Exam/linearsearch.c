#include <stdio.h>
int main() {
    int a[] = {0, 4, 7, 2};
    int n = sizeof(a) / sizeof(a[0]);
    int data = 2;
    for (int i = 0; i < n; i++) {
        if (data == a[i]) {
            printf("element found at %d\n", i);
            break;
        }
    }
    return 0;
}
