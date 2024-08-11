#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int **p;
    p = (int **)malloc(sizeof(int *) * 3);
    p[0] = (int *)malloc(sizeof(int) * 4);
    p[1] = (int *)malloc(sizeof(int) * 4);
    p[0][0] = 1;
    printf("%d\n", p[0][0]);
    printf("%d\n", p[1][1]); // This will print the address of the memory allocated for p[2]
}
