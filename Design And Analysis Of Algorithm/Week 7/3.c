#include <stdio.h>
#include <stdlib.h>

// Structure for each node of Huffman tree
struct MinHeapNode {
    char data;                         // One of the input characters
    unsigned freq;                     // Frequency of the character
    struct MinHeapNode *left, *right;  // Left and right child of this node
};

// Structure for Min Heap: Collection of heap (or huffman tree) nodes
struct MinHeap {
    unsigned size;               // Current size of Min Heap
    unsigned capacity;           // Capacity of Min Heap
    struct MinHeapNode** array;  // Array of heap node pointers
};

// Function to create a new heap node
struct MinHeapNode* createNode(char data, unsigned freq) {
    struct MinHeapNode* temp =
        (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    temp->data = data;
    temp->freq = freq;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to create a Min Heap of given capacity
struct MinHeap* createMinHeap(unsigned capacity) {
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct MinHeapNode**)malloc(minHeap->capacity *
                                                  sizeof(struct MinHeapNode*));
    return minHeap;
}

// Swap two heap nodes
void swapNodes(struct MinHeapNode** a, struct MinHeapNode** b) {
    struct MinHeapNode* temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify the Min Heap at given index
void minHeapify(struct MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size &&
        minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;

    if (right < minHeap->size &&
        minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;

    if (smallest != idx) {
        swapNodes(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

// Check if size of heap is 1
int isSizeOne(struct MinHeap* minHeap) { return (minHeap->size == 1); }

// Extract the minimum value node from heap
struct MinHeapNode* extractMin(struct MinHeap* minHeap) {
    struct MinHeapNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

// Insert a new node to Min Heap
void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode) {
    ++minHeap->size;
    int i = minHeap->size - 1;

    // Insert the new node at the end
    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = minHeapNode;
}

// Function to build a Min Heap
void buildMinHeap(struct MinHeap* minHeap) {
    int n = minHeap->size - 1;
    for (int i = (n - 1) / 2; i >= 0; --i) {
        minHeapify(minHeap, i);
    }
}

// Check if this node is a leaf node
int isLeaf(struct MinHeapNode* root) { return !(root->left) && !(root->right); }

// Create a Min Heap and insert all characters of data[]
struct MinHeap* createAndBuildMinHeap(char data[], int freq[], int size) {
    struct MinHeap* minHeap = createMinHeap(size);
    for (int i = 0; i < size; ++i) {
        minHeap->array[i] = createNode(data[i], freq[i]);
    }
    minHeap->size = size;
    buildMinHeap(minHeap);
    return minHeap;
}

// Build Huffman Tree
struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size) {
    struct MinHeapNode *left, *right, *top;

    // Step 1: Create a min heap of capacity equal to size and build a min heap
    struct MinHeap* minHeap = createAndBuildMinHeap(data, freq, size);

    // Iterate until the size of the heap becomes 1
    while (!isSizeOne(minHeap)) {
        // Step 2: Extract the two minimum freq items from the min heap
        left = extractMin(minHeap);
        right = extractMin(minHeap);

        // Step 3: Create a new internal node with freq equal to the sum of the
        // two nodes' freqs
        top = createNode('$', left->freq + right->freq);

        // Step 4: Make the two extracted nodes as children of this new node
        top->left = left;
        top->right = right;

        // Step 5: Add this node to the min heap
        insertMinHeap(minHeap, top);
    }

    // Step 6: The remaining node is the root node and the tree is complete
    return extractMin(minHeap);
}

// Print the codes (Huffman Codes) by traversing the Huffman Tree
void printCodes(struct MinHeapNode* root, int arr[], int top) {
    // Assign 0 to the left edge and recur
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }

    // Assign 1 to the right edge and recur
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }

    // If this is a leaf node, then it contains one of the input characters,
    // print the character and its code
    if (isLeaf(root)) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; ++i) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

// The main function that builds a Huffman Tree and prints Huffman codes
void HuffmanCodes(char data[], int freq[], int size) {
    // Build Huffman Tree
    struct MinHeapNode* root = buildHuffmanTree(data, freq, size);

    // Print Huffman codes using the Huffman tree built above
    int arr[100], top = 0;
    printCodes(root, arr, top);
}

int main() {
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Huffman Codes:\n");
    HuffmanCodes(arr, freq, size);

    return 0;
}
