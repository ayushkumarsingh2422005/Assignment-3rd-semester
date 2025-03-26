#include <stdio.h>

void towerOfHanoi(int n, char source, char target, char auxiliary)
{
    if (n == 0)
        return;
    towerOfHanoi(n - 1, source, auxiliary, target);
    printf("Move disk %d from rod %c to rod %c\n", n, source, target);
    towerOfHanoi(n - 1, auxiliary, target, source);
}
int main(int argc, char const *argv[])
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    towerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}
