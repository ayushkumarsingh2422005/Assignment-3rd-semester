#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int pr;        // priority
    int data;     // data
    struct node *next;
} pq;

pq *head = NULL;

// Function to create a new node
pq *create(int x, int p) {
    pq *new_ = (pq *)malloc(sizeof(pq));
    new_->data = x;
    new_->pr = p;
    new_->next = NULL;
    return new_;
}

// Function to insert a new node
void insert(int p, int x) {
    pq *newnode = create(x, p);
    if (head == NULL || head->pr >= p) {
        newnode->next = head;
        head = newnode;
        return;
    }
    
    pq *tmp = head;
    while (tmp->next != NULL && tmp->next->pr < p) {
        tmp = tmp->next;
    }
    newnode->next = tmp->next;
    tmp->next = newnode;
}

// Function to delete the node with the highest priority
void deleteHighestPriority() {
    if (head == NULL) {
        printf("Priority Queue is empty. Nothing to delete.\n");
        return;
    }
    
    pq *temp = head;
    head = head->next; // Move head to the next node
    free(temp); // Free the old head
    printf("Deleted node with priority %d and data %d\n", temp->pr, temp->data);
}

// Function to display the queue
void display(pq *t) {
    pq *tmp = t;
    while (tmp != NULL) {
        printf("%d is data and %d is priority\n", tmp->data, tmp->pr);
        tmp = tmp->next;
    }
}

int main() {
    head = create(5, 0);
    insert(20, 5);
    insert(10, 3);
    insert(2, 4);
    insert(2, 9);
    
    printf("Priority Queue before deletion:\n");
    display(head);

    deleteHighestPriority(); // Delete the node with the highest priority (lowest priority value)
    
    printf("Priority Queue after deletion:\n");
    display(head);
    
    return 0;
}