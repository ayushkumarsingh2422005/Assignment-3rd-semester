#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, north_sum = 0, north_count = 0, south_sum = 0, south_count = 0;
    cout << "Enter the size of the data: ";
    cin >> n;
    int *lat = new int[n];
    int *temp = new int[n];
    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < n; i++){
        cout << "Enter latitude for day " << i + 1 << ": ";
        cin >> lat[i];
        cout << "Enter temperature for day " << i + 1 << ": ";
        cin >> temp[i];

        if (lat[i] >= 1 && lat[i] <= 90){
            north_sum += temp[i];
            north_count++;
        } else {
            south_sum += temp[i];
            south_count++;
        }
    }
    
    for(int i = 0; i < n; i++){
        cout << "Latitude for day " << i + 1 << ": " << lat[i];
        cout << " Temperature for day " << i + 1 << ": " << temp[i] << endl;    
    }
    
    cout << "Average for south " << south_sum/south_count << endl;
    cout << "Average for north " << north_sum/north_count << endl;

    if ((south_sum/south_count) > (north_sum/north_count))
    {
        cout << "Average temp of south is greater ";
    }
    else
    {
        cout << "Average temp of north is greater ";
    }
    return 0;
}
