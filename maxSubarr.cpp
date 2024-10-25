#include <vector>
#include <limits>
#include <algorithm>
#include <iostream>
#include <iterator>

#include <fstream>
#include <string>
#include <sstream>
#include <stdexcept>

using std::cout;
using std::vector;

template <typename T>
void printVec(const vector<T> &vec)
{
    std::copy(cbegin(vec), cend(vec), std::ostream_iterator<T>(cout, ","));
    std::cout << "\n";
}

std::vector<int> readNumbersFromFile(const std::string &filename)
{
    std::vector<int> numbers;
    std::ifstream file(filename);

    if (!file.is_open())
    {
        throw std::runtime_error("Unable to open file: " + filename);
    }

    std::string line;
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        int number;

        // Read numbers separated by commas
        while (ss >> number)
        {
            numbers.push_back(number);
            // Skip comma if present
            if (ss.peek() == ',')
            {
                ss.ignore();
            }
        }
    }

    file.close();
    return numbers;
}

int maxSubArray(vector<int> &nums)
{
    vector<int> prevArr{};
    int prevSum = -std::numeric_limits<int>::max();

    vector<int> globalArr{};
    int globalMax = -std::numeric_limits<int>::max();

    vector<vector<int>> subArrs{};
    vector<int> newSums{};

    int maxIdx;

    for (size_t i = 0; i < nums.size(); ++i)
    {
        prevArr.push_back(nums[i]);
        subArrs.push_back(prevArr);
        subArrs.push_back(vector<int>({nums[i]}));

        prevSum += nums[i];
        newSums.push_back(prevSum);
        newSums.push_back(nums[i]);

        maxIdx = newSums[0] > newSums[1] ? 0 : 1;

        if (newSums[maxIdx] > globalMax)
        {
            globalMax = newSums[maxIdx];
            globalArr = subArrs[maxIdx];
        }

        prevArr = subArrs[maxIdx];
        prevSum = newSums[maxIdx];

        subArrs.clear();
        newSums.clear();
    }
    printVec(globalArr);
    return globalMax;
}

int main()
{
    // vector<int> nums{1, -3, 2, 1, -1};
    // vector<int> nums{1, 2, 3, 4, 5};
    // vector<int> nums{-1, -2, -3, -4, -5};
    vector<int> nums = readNumbersFromFile("maxArrtest.txt");
    int result = maxSubArray(nums);
    cout << result << "\n";
}