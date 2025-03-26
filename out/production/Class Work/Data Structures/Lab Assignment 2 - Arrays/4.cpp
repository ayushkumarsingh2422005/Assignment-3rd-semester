#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    int data[] = {1, 2, 3, 1, 2, 1};
    int size = sizeof(data) / sizeof(data[0]);
    bool counted[size] = {false};

    for (int i = 0; i < size; i++) {
        if (counted[i]) continue;

        int count = 1;
        for (int j = i + 1; j < size; j++) {
            if (data[i] == data[j]) {
                count++;
                counted[j] = true;
            }
        }
        cout << "Element: " << data[i] << ", Count: " << count << endl;
    }

    return 0;
}
