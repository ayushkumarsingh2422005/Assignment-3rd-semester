#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int median(int arr[], int n) {
    if (n % 2 == 0) {
        return (arr[n / 2] + arr[n / 2 - 1]) / 2;
    } else {
        return arr[n / 2];
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    bubbleSort(arr, n);
    int ans = median(arr, n);
    cout << ans << endl;

    return 0;
}
