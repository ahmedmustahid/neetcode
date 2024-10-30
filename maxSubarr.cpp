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
    vector<int> prevArr = vector<int>({nums[0]});
    int prevSum = nums[0];

    vector<int> globalArr = prevArr;
    int globalSum = prevSum;

    for (size_t i = 1; i < nums.size(); ++i)
    {
        vector<int> currArr = vector<int>({nums[i]});
        int currSum = nums[i];
        prevArr.push_back(nums[i]);
        prevSum += currSum;
        if (currSum > prevSum)
        {
            prevSum = std::move(currSum);
            prevArr = std::move(currArr);
        }
        if (prevSum > globalSum)
        {
            globalSum = prevSum;
            globalArr = prevArr;
        }
    }
    printVec(globalArr);
    return globalSum;
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