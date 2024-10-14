#include <iostream>
#include <vector>
using namespace std;

int left(int i) { return i * 2 + 1; }
int right(int i) { return i * 2 + 2; }
int parent(int i) { return (i - 1) / 2; }

void swap(int i, int j, vector<int>& list) {
    int temp = list[i];
    list[i] = list[j];
    list[j] = temp;
}

void upheap(vector<int>& list, int index) {
    if (index == 0) return;
    int parent_index = parent(index);
    if (list[parent_index] < list[index]) {
        swap(index, parent_index, list);
        upheap(list, parent_index);
    }
}

void downheap(vector<int>& list, int index) {
    int left_index = left(index);
    int right_index = right(index);
    int size = list.size();

    if (left_index >= size) return;  // No children
    int largest = index;

    // Check if left child exists and is greater than the current index
    if (left_index < size && list[left_index] > list[largest]) {
        largest = left_index;
    }
    // Check if right child exists and is greater than the largest so far
    if (right_index < size && list[right_index] > list[largest]) {
        largest = right_index;
    }
    // If one of the children is larger, swap and continue downheap
    if (largest != index) {
        swap(largest, index, list);
        downheap(list, largest);
    }
}

void insert(vector<int>& list, int data) {
    list.push_back(data);
    upheap(list, list.size() - 1);
}

void remove(vector<int>& list, int index) {
    if (list.empty()) return;  // Handle empty list
    swap(index, list.size() - 1, list);
    list.pop_back();
    if (index < list.size()) {
        downheap(list, index);
    }
}

void printHeap(const vector<int>& list) {
    for (int val : list) {
        cout << val << " ";
    }
    cout << endl;
}

void printVector(const vector<int>& vec) {
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
}
vector<int> sort_(vector<int>& list) {
    vector<int> sorted;
    while (!list.empty()) {
        sorted.push_back(list[0]);
        remove(list, 0);
    }
    return sorted;
}
int main() {
    vector<int> heap;

    // Insert elements into the heap
    insert(heap, 20);
    insert(heap, 15);
    insert(heap, 30);
    insert(heap, 40);
    insert(heap, 10);
    insert(heap, 25);

    // Print heap after insertions
    cout << "Heap after insertions: ";
    printHeap(heap);  // Output: 40 30 25 15 10 20

    // Remove an element from the heap (e.g., at index 1)
    remove(heap, 1);

    // Print heap after removal
    cout << "Heap after removal: ";
    printHeap(heap);  // Output: 40 20 25 15 10

    cout << "Heap Sort: ";
    printVector(sort_(heap));
    return 0;
}
