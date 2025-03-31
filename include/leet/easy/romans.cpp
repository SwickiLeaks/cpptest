#include <bits/stdc++.h>
#include <ranges>

using namespace std;

#define CustomMap unordered_map<char, int>

/**
 * @brief Class containing the solution for the problem
 */
class Solution
{
public:
    Solution() {}
    ~Solution() {}

    int romanToInt(string s)
    {
        int result = 0;
        unordered_map<char, int> romanMap = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}};

        for (size_t i = 0; i < s.size(); i++)
        {
            if (i < s.size() - 1 && romanMap[s[i]] < romanMap[s[i + 1]])
            {
                result -= romanMap[s[i]];
            }
            else
            {
                result += romanMap[s[i]];
            }
        }

        return result;
    }
};

/**
 * @brief Main function
 */
int main()
{
    Solution solution;

    vector<string> testCases = {
        "III",
        "IV",
        "IX",
        "LVIII",
        "MCMXCIV"};

    for (auto &&testCase : testCases)
    {
        cout << "Roman: " << testCase << " -> Integer: " << solution.romanToInt(testCase) << endl;
    }

    return 0;
}