#include <stdio.h>
void tower(int n, char s, char a, char d) {
    if (n == 0) return;
    tower(n-1, a, s, d);
    printf("Move disk %d from %c to %c\n", n, s, d);
    tower(n-1, s, d, a);
}
int main() {
    tower(50, 'S', 'A', 'D');
    return 0;
}
