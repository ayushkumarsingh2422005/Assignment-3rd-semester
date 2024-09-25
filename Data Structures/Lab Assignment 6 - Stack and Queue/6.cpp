#include <stdio.h>
#include <stdlib.h>

// Function to insert an element into the circular queue
void insert(int a[], int n, int x, int *r, int *f) {
    if ((*r + 1) % n == *f) {
        printf("Queue is full\n");
        return;
    } else if (*r == -1 && *f == -1) {
        *r = *f = 0;  // Initialize front and rear
        a[*r] = x;
    } else {
        *r = (*r + 1) % n;  // Wrap around
        a[*r] = x;
    }
    printf("Inserted: %d\n", x);
}

// Function to remove an element from the circular queue
void pop(int a[], int n, int *r, int *f) {
    if (*r == -1 && *f == -1) {
        printf("Queue is empty\n");
        return;
    } else if (*f == *r) {
        *f = *r = -1;  // Queue is now empty
    } else {
        *f = (*f + 1) % n;  
    }
    printf("Removed an element\n");
}

// Function to display the circular queue
void display(int a[], int n, int f, int r) {
    if (f == -1 && r == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");
    int i = f;
    while (1) {
        printf("%d ", a[i]);
        if (i == r) break;
        i = (i + 1) % n;
    }
    printf("\n");
}

// Main function
int main() {
    int n;
    printf("Size of the queue: ");
    scanf("%d", &n);

    int cq[n];
    int r = -1;  // Rear index
    int f = -1;  // Front index

    insert(cq, n, 10, &r, &f);
    insert(cq, n, 20, &r, &f);
    insert(cq, n, 30, &r, &f);
    display(cq, n, f, r);

    pop(cq, n, &r, &f);
    display(cq, n, f, r);

    insert(cq, n, 40, &r, &f);
    insert(cq, n, 50, &r, &f);
    insert(cq, n, 60, &r, &f);  // This will indicate that the queue is full
    display(cq, n, f, r);

    return 0;
}
//circular