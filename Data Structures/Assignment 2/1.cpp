#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

int minSwaps(std::vector<int>& arr, int k) {
    int n = arr.size();
    int count = 0;
    int swaps = 0;

    // Count the number of elements less than or equal to k
    for (int i = 0; i < n; ++i) {
        if (arr[i] <= k) {
            count++;
        }
    }

    // Count the number of elements greater than k in the first window of size 'count'
    for (int i = 0; i < count; ++i) {
        if (arr[i] > k) {
            swaps++;
        }
    }

    int minSwaps = swaps;
    for (int i = 0, j = count; j < n; ++i, ++j) {
        if (arr[i] > k) {
            swaps--;
        }
        if (arr[j] > k) {
            swaps++;
        }
        minSwaps = std::min(minSwaps, swaps);
    }

    return minSwaps;
}

int main() {
    std::vector<int> arr = {2, 7, 9, 5, 8, 7, 4};
    int k = 5;

    int result = minSwaps(arr, k);
    std::cout << "Minimum number of swaps required: " << result << std::endl;

    return 0;
}
