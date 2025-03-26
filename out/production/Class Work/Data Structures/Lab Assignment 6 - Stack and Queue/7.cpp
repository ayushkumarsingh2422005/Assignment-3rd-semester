#include <stdio.h>
#include <stdlib.h>
// a. insertion in the double ended queque
void enfront(int x, int deque[], int size, int *f, int *r) {
    if (*f == 0 && *r == size - 1 || *f == *r + 1) {
        printf("queue is full\n");
        return;
    } else if (*f == -1 && *r == -1) {
        *f = *r = 0;
        deque[*f] = x;
    } else if (*f == 0) {
        *f = size - 1;
        deque[*f] = x;
    } else {
        (*f)--;
        deque[*f] = x;
    }
}

void enrear(int x, int deque[], int size, int *f, int *r) {
    if (*f == 0 && *r == size - 1 || *f == *r + 1) {
        printf("queue is full\n");
        return;
    } else if (*f == -1 && *r == -1) {
        *f = *r = 0;
        deque[*r] = x;
    } else if (*r == size - 1) {
        *r = 0;
        deque[*r] = x;
    } else {
        (*r)++;
        deque[*r] = x;
    }
}
// b & c. deletion and display of double ended queque
void display(int f, int r, int deque[], int n) {
    int i = f;
    while (i != r) {
        printf("%d ", deque[i]);
        i = (i + 1) % n;
    }
    printf("%d", deque[r]);
}

int main() {
    int n;
    printf("size of deque\n");
    scanf("%d", &n);
    int deq[n];
    int front, rear;
    front = rear = -1;

    enfront(-1, deq, n, &front, &rear);
    enfront(-2, deq, n, &front, &rear);
    enrear(8, deq, n, &front, &rear);
    enrear(5, deq, n, &front, &rear);
    enrear(4, deq, n, &front, &rear);

    printf("contents of deque\n");
    display(front, rear, deq, n);

    return 0;
}