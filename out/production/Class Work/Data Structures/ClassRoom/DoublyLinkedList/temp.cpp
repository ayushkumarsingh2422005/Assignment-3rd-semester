#include <bits/stdc++.h>
using namespace std;

int main()
{
  const int branches = 20;
  const int items = 10;

  // 2D array
  double sales[branches][items] = {0};
  double branchTotal[branches] = {0};
  double itemTotal[items] = {0};
  double grandTotal = 0;
  int br_num, it_num;
  double amount;

  cout << "Enter -1 to stop. ";

  for (int i = 0; i < 20; i++)
  {
    br_num = i;

    cout << "Enter two input: item number and sales amount for branch number " << i + 1 << endl;

    while (true)
    {
      cin >> it_num;
      if (it_num == -1)
        break;
      cin >> amount;
      it_num -= 1;

      sales[br_num][it_num] += amount;
      branchTotal[br_num] += amount;

      grandTotal += amount;
    }
  }

  //  Displaying the Table
  cout << "\n The Sales Report of department stores is: :\n";

  cout << "Branch  ";
  for (int i = 0; i < items; i++)
  {
    cout << "Item" << (i + 1) << "  ";
  }

  cout << "Total\n";

  for (int i = 0; i < branches; i++)
  {

    cout << (i + 1) << "        "; // Branch number

    for (int j = 0; j < items; j++)
    {

      cout << sales[i][j] << "      ";
    }

    cout << branchTotal[i] << "\n";
  }

  cout << "TOTAL                                                                             ";

  cout << grandTotal << "\n";

  return 0;
}