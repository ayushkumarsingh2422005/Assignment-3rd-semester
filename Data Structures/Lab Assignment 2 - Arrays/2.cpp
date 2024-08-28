#include <iostream>
using namespace std;

void sort(int *arr, int len){
    for(int i = 0; i < len-1; i++){
        for(int j = 0; j < len-i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
int uniqueElements(int *arr, int len){
    int unique = 1;
    int temp = arr[0];
    for(int i = 0; i < len-1; i++){
        if(arr[i] != temp){
            unique++;
            temp = arr[i];
        }
    }
    return unique;
}

int main(int argc, char const *argv[])
{
    int arr[] = {1,3,9,4,5,6,2,1,5,6,7,10};
    int len = sizeof(arr)/sizeof(arr[0]);
    sort(arr, len);
    int unique = uniqueElements(arr, len);
    
    cout << endl << "Number of unique elements: " << unique << endl;
    return 0;
}
