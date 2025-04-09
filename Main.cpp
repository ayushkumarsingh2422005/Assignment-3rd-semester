#include <iostream>
#include <vector>
using namespace std;

bool isBSTTraversal(vector<int>& arr) {
    // your code here
    int len = arr.size();
    for (int i = 0; i < len - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}
int main() { vector<int> numbers = {8, 14, 45, 64, 100}; }
