#include <iostream>
using namespace std;

int mode(int arr[], int n) {
    int max_count = 0;
    int mode = -1;
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (arr[i] == arr[j]) count++;
        }

        if (count > max_count) {
            max_count = count;
            mode = arr[i];
        }
    }
    int mode_count = 0;
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (arr[i] == arr[j]) count++;
        }

        if (count == max_count) {
            if (arr[i] != mode) return -1;  // More than one mode
            mode_count++;
        }
    }

    return mode;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    int result = mode(arr, n);
    if (result == -1)
        cout << "No unique mode found." << endl;
    else
        cout << "Mode of data is " << result << endl;

    return 0;
}
