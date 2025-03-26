#include <stdio.h>

int factorial(int n){
    if (n == 0)
        return 1;
    else
        return (n * factorial(n - 1));
}
int main(int argc, char const *argv[])
{
    int a;
    printf("Enter a number: ");
    scanf("%d", &a);
    printf("The factorial of %d is: %d\n", a, factorial(a));
    return 0;
}
