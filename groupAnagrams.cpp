#include <vector>
#include <string>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <iterator>

#include <tuple>
#include <map>

using std::cout;
using std::string;
using std::vector;

template <typename T>
void printVec(const vector<T> &vec)
{
    std::copy(cbegin(vec), cend(vec), std::ostream_iterator<T>(cout, ","));
}

template <typename U>
void printNestedVec(const vector<vector<U>> &vec)
{
    cout << "\n";
    for (const auto &v : vec)
    {

        cout << "[";
        printVec(v);
        cout << "]\n";
    }
}

vector<vector<string>> stringToCharSets(const std::vector<std::string> &input)
{
    if (input.empty())
        return vector<vector<string>>();

    std::map<std::vector<char>, vector<string>> mapStr;

    for (const auto &str : input)
    {
        std::vector<char> charSet(str.begin(), str.end());
        std::sort(charSet.begin(), charSet.end());
        mapStr[charSet]
            .push_back(str);
    }

    vector<vector<string>> vec;
    for (const auto &[k, v] : mapStr)
    {

        vec.push_back(v);
    }

    return vec;
}

int strToInt(string str)
{

    return std::accumulate(cbegin(str), cend(str), 0, [](int sum, unsigned char c)
                           { return sum + static_cast<int>(c); });
}

int main()
{

    vector<string> vec{"eat", "tea", "tan", "ate", "nat", "bat"};
    // vector<string> vec{"cab", "tin", "pew", "duh", "may", "ill", "buy", "bar", "max", "doc"};
    // vector<string> vec{"aa", "a"};
    auto v = stringToCharSets(vec);

    printNestedVec(v);
}