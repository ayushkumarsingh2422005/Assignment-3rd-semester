#include <bits/stdc++.h>
using namespace std;
int main() {
    int arr[] = {4, 242, 99, 78, 97, 19, 23, 51, 0, 81, 92, 87, 53};
    int size = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + size);
    int ans[size];
    int start = 0;
    int end = size - 1;
    for (int i = 0; i < size; i++) {
        if (i % 2 == 0) {
            ans[i] = arr[start];
            start++;
        } else {
            ans[i] = arr[end];
            end--;
        }
    }
    for (int i = 0; i < size; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}
