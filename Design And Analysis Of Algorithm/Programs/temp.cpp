#include <iostream>
using namespace std;

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int main(int argc, char const *argv[]) {
    int left[] = {1, 2, 4, 6, 7};
    int right[] = {3, 4, 5, 8};
    int left_size = sizeof(left) / sizeof(left[0]);
    int right_size = sizeof(right) / sizeof(right[0]);
    int l = 0, r = 0;
    int ans[left_size +right_size];

    while (l < left_size && r < right_size) {
        if (left[l] < right[r]) {
            ans[l+r] = left[l];
            l++;
        } else {
            ans[l+r] = right[r];
            r++;
        }
    }

    while (l < left_size) {
        ans[l+r] = left[l];
        l++;
    }
    while (r < right_size) {
        ans[l+r] = right[r];
        r++;
    }

    for (int i = 0; i < left_size + right_size; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}
