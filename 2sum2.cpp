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

    auto it = std::upper_bound(numbers.begin(), numbers.end(), target);
    numbers.assign(numbers.begin(), it);

    printVec(numbers);

    int maxId = numbers.size() - 1;
    int minId = 0;

    int targetSubMin = target - numbers[minId];
    int targetSubMax = target - numbers[maxId];

    while (maxId != minId)
    {
        numbers.assign(numbers.begin() + minId, numbers.begin() + maxId + 1);

        bool isTargetSubMinPresent = std::binary_search(numbers.begin(), numbers.end(), targetSubMin);
        if (targetSubMin > target)
            minId++;
        else if (!isTargetSubMinPresent)
            minId++;
        else if (isTargetSubMinPresent)
        {
            auto it2 = std::lower_bound(numbers.begin(), numbers.end(), targetSubMin);
            int targetSubMinPos = static_cast<int>(it2 - numbers.begin());

            return vector<int>({minId, targetSubMinPos});
        }

        targetSubMin = target - numbers[minId];

        bool isTargetSubMaxPresent = std::binary_search(numbers.begin(), numbers.end(), targetSubMax);
        if (targetSubMax > target)
            maxId--;
        else if (!isTargetSubMaxPresent)
            maxId--;
        else if (isTargetSubMaxPresent)
        {
            auto it2 = std::lower_bound(numbers.begin(), numbers.end(), targetSubMax);
            int targetSubMaxPos = static_cast<int>(it2 - numbers.begin());

            return vector<int>({maxId, targetSubMaxPos});
        }

        targetSubMax = target - numbers[maxId];
    }

    return {};
}

int main()
{

    vector<int> v{1, 3, 4, 5, 7, 10, 11};
    int target = 9;
    vector<int> v2 = ts2(v, target);
    printVec(v2);
}