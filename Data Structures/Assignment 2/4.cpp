#include <iostream>
#include <map>
#include <vector>

using namespace std;
int main(int argc, char const *argv[])
{
    map<int, int> elementCountMap;
    vector<int> data = {1, 2, 3, 1, 2, 1};

    for (int element : data)
    {
        elementCountMap[element]++;
    }
    for (const auto &pair : elementCountMap)
    {
        cout << "Element: " << pair.first << ", Count: " << pair.second << endl;
    }

    return 0;
}
