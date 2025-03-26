#include <iostream>
using namespace std;

bool isMagicSquare(int mat[][3], int n)
{
    // Your implementation here
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += mat[i][j];
        }
        if (sum != 15)
            return false;
    }

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += mat[j][i];
        }
        if (sum != 15)
            return false;
    }

    int sum = 0;
    for (int j = 0; j < n; j++)
    {
        sum += mat[j][j];
    }
    if (sum != 15)
        return false;

    return true;
}

int main()
{
    int mat[3][3] = {
        {2, 7, 6},
        {9, 5, 1},
        {4, 3, 8}};
    cout << isMagicSquare(mat, 3) ? "true": "false";
    return 0;
}
