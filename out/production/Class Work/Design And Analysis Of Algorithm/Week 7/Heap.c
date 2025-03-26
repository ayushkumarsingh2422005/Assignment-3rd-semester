#include <stdio.h>
#include <limits.h>

#define MAX 100

// Min Heap structure
struct MinHeap {
    int size;
    int arr[MAX];
};

// Function to swap two elements
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Function to heapify the tree rooted at index i
// size is the size of the heap
void minHeapify(struct MinHeap* heap, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap->size && heap->arr[left] < heap->arr[smallest])
        smallest = left;

    if (right < heap->size && heap->arr[right] < heap->arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&heap->arr[i], &heap->arr[smallest]);
        minHeapify(heap, smallest);
    }
}

// Function to build a Min Heap from an array
void buildMinHeap(struct MinHeap* heap) {
    int startIdx = (heap->size / 2) - 1;

    // Perform reverse level order traversal from last non-leaf node and heapify each node
    for (int i = startIdx; i >= 0; i--) {
        minHeapify(heap, i);
    }
}

// Function to insert an element into the Min Heap
void insert(struct MinHeap* heap, int element) {
    if (heap->size >= MAX) {
        printf("Heap overflow\n");
        return;
    }

    // Insert the new element at the end
    heap->size++;
    int i = heap->size - 1;
    heap->arr[i] = element;

    // Fix the Min Heap property if it's violated
    while (i != 0 && heap->arr[(i - 1) / 2] > heap->arr[i]) {
        swap(&heap->arr[i], &heap->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to delete the minimum element (root) from the Min Heap
int deleteMin(struct MinHeap* heap) {
    if (heap->size <= 0) {
        printf("Heap underflow\n");
        return INT_MAX;
    }

    if (heap->size == 1) {
        heap->size--;
        return heap->arr[0];
    }

    // Store the minimum value and remove it
    int root = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;

    // Heapify the root
    minHeapify(heap, 0);

    return root;
}

// Function to perform Heap Sort
void heapSort(struct MinHeap* heap) {
    int originalSize = heap->size;

    for (int i = heap->size - 1; i > 0; i--) {
        // Move the current root to the end
        swap(&heap->arr[0], &heap->arr[i]);

        // Reduce the heap size and heapify the root element
        heap->size--;
        minHeapify(heap, 0);
    }

    // Restore original size
    heap->size = originalSize;
}

// Function to print the heap
void printHeap(struct MinHeap* heap) {
    printf("Heap: ");
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->arr[i]);
    }
    printf("\n");
}

int main() {
    struct MinHeap heap;
    heap.size = 0;

    // Inserting elements into the heap
    insert(&heap, 12);
    insert(&heap, 11);
    insert(&heap, 13);
    insert(&heap, 5);
    insert(&heap, 6);
    insert(&heap, 7);

    printf("Min Heap after insertion:\n");
    printHeap(&heap);

    // Build the Min Heap
    buildMinHeap(&heap);
    printf("Min Heap after building:\n");
    printHeap(&heap);

    // Delete the minimum element
    int minElement = deleteMin(&heap);
    printf("Deleted minimum element: %d\n", minElement);
    printHeap(&heap);

    // Perform Heap Sort
    heapSort(&heap);
    printf("Heap after Heap Sort:\n");
    printHeap(&heap);

    return 0;
}
