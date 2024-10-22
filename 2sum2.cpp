#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>

using std::cout;
using std::vector;

template <typename T>
void printVec(const vector<T> &vec)
{
    std::copy(cbegin(vec), cend(vec), std::ostream_iterator<T>(cout, ","));
    std::cout << "\n";
}

vector<int> ts2(vector<int> &numbers, int target)
{
    int maxId = numbers.size() - 1;
    int minId = 0;

    while (maxId != minId)
    {
        int sum = numbers[maxId] + numbers[minId];
        if (sum > target)
            --maxId;
        else if (sum < target)
            ++minId;
        else
        {
            return vector<int>({minId + 1, maxId + 1});
        }
    }

    return {};
}

int main()
{

    // vector<int> v{1, 3, 4, 5, 7, 10, 11};
    // int target = 9;
    vector<int> v{-1, 0, 0, 2, 3, 4};
    int target = 0;
    vector<int> v2 = ts2(v, target);
    printVec(v2);
}