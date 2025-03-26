#include <stdio.h>

// Structure to represent an item
struct Item {
    int weight;
    int value;
};

// Function to sort items based on value/weight ratio
void swap(struct Item* a, struct Item* b) {
    struct Item temp = *a;
    *a = *b;
    *b = temp;
}

// Comparator function to sort items by their value/weight ratio in descending order
int partition(struct Item arr[], int low, int high) {
    int pivot = arr[high].value / arr[high].weight;
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if ((arr[j].value / arr[j].weight) > pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(struct Item arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to calculate the maximum value that can be obtained
double fractionalKnapsack(int W, struct Item arr[], int n) {
    quickSort(arr, 0, n - 1);  // Sort items based on value/weight ratio
    
    double maxValue = 0.0;
    
    for (int i = 0; i < n; i++) {
        if (W == 0) break;  // Stop when the knapsack is full

        if (arr[i].weight <= W) {
            // If the item can be completely added
            W -= arr[i].weight;
            maxValue += arr[i].value;
        } else {
            // Add fraction of the item
            maxValue += arr[i].value * ((double) W / arr[i].weight);
            W = 0;
        }
    }
    return maxValue;
}

int main() {
    int W = 50;  // Knapsack capacity

    // Example items (value, weight)
    struct Item arr[] = {{60, 10}, {100, 20}, {120, 30}};
    int n = sizeof(arr) / sizeof(arr[0]);

    double maxValue = fractionalKnapsack(W, arr, n);

    printf("Maximum value in Knapsack = %.2f\n", maxValue);
    return 0;
}
