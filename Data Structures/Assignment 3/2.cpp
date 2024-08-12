#include <iostream>
using namespace std;

// Function to find mode of an array

int mode(int arr[], int n)
{
    int max_count = 0;
    int mode = 0;
    int count;

    for (int i = 0; i < n; i++)
    {
        count = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[i] == arr[j])
                count++;
        }

        if (count > max_count)
        {
            max_count = count;
            mode = arr[i];
        }
        if (count == max_count)
        {
            return -1;
        }
        
    }

    return mode;
}
int main(int argc, char const *argv[])
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << " Mode of data is " << mode(arr, n) << endl;
    return 0;
}
