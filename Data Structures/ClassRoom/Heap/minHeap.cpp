#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;
struct Heap {
    vector<int> list;

    // Function to swap elements
    void swap(int first, int second) {
        int temp = list[first];
        list[first] = list[second];
        list[second] = temp;
    }

    // Function to get parent index
    int parent(int index) {
        return (index - 1) / 2;
    }

    // Function to get left child index
    int left(int index) {
        return index * 2 + 1;
    }

    // Function to get right child index
    int right(int index) {
        return index * 2 + 2;
    }

    // Function to insert a new value
    void insert(int value) {
        list.push_back(value);
        upheap(list.size() - 1);
    }

    // Helper function to restore heap property upwards
    void upheap(int index) {
        if (index == 0) {
            return;
        }
        int p = parent(index);
        if (list[index] < list[p]) {
            swap(index, p);
            upheap(p);
        }
    }

    // Function to remove the root (smallest element)
    int remove() {
        if (list.empty()) {
            throw runtime_error("Removing from an empty heap!");
        }

        int temp = list[0];
        int last = list.back();
        list.pop_back();

        if (!list.empty()) {
            list[0] = last;
            downheap(0);
        }

        return temp;
    }

    // Helper function to restore heap property downwards
    void downheap(int index) {
        int min = index;
        int leftChild = left(index);
        int rightChild = right(index);

        if (leftChild < list.size() && list[min] > list[leftChild]) {
            min = leftChild;
        }

        if (rightChild < list.size() && list[min] > list[rightChild]) {
            min = rightChild;
        }

        if (min != index) {
            swap(min, index);
            downheap(min);
        }
    }

    // Function to perform heap sort and return the sorted array
    vector<int> heapSort() {
        vector<int> sortedData;
        while (!list.empty()) {
            sortedData.push_back(remove());
        }
        return sortedData;
    }
};

int main() {
    Heap heap;

    // Inserting elements into the heap
    heap.insert(10);
    heap.insert(15);
    heap.insert(20);
    heap.insert(17);
    heap.insert(8);
    heap.insert(11);

    // Performing heap sort
    vector<int> sorted = heap.heapSort();

    // Output sorted values
    for (int val : sorted) {
        cout << val << " ";
    }

    return 0;
}
