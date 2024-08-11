#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int arr1[] = {8,6,5,4,3,1};
    int arr2[] = {10,9,5,4,3,1};
    int len = sizeof(arr1)/sizeof(arr1[0]);
    int ans[len];
    int i = 0;
    int j = 0;
    while (i < len && j < len)
    {
        if (arr1[i] > arr2[j])
        {
            /* code */
            ans[i+j] = arr1[i];
            i++;
        } else {
            ans[i+j] = arr2[j];
            j++;
        }
        
    }
    while (i < len)
    {
        ans[i+j] = arr1[i];
        i++;
    }
    while (j < len){
        ans[i+j] = arr2[j];
        j++;
    }
    
    for (int i = 0; i < len*2; i++){
        cout << ans[i] << " ";
    }
    return 0;
}
