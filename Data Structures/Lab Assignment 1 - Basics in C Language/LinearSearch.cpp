#include <iostream>
using namespace std;

int linear_search(int *a, int size, int n){
    for (int i = 0; i < size; i++){
        if (a[i] == n)
        {
            return i;
        }
    }
    return -1;
}
int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 3, 4, 5};
    int num = 3;
    int result = linear_search(arr, sizeof(arr)/sizeof(arr[0]), num);
    cout << result << endl;
    return 0;
}
