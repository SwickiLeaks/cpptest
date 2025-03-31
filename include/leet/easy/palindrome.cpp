
#include <bits/stdc++.h>
#include <ranges>
#include <algorithm>
#include <string>

using namespace std;

/**
 * @brief Class containing the solution for the problem
 */
class Solution
{
public:
    Solution() {}
    ~Solution() {}

    bool isPalindrome(int x) const
    {
        // Negative numbers and numbers ending in 0 cannot be palindromes
        if (x < 0 || (x % 10 == 0 && x != 0))
            return false;

        // Convert int into string of numbers
        string xStr = to_string(x);
        string reverseXStr = to_string(x);
        reverse(reverseXStr.begin(), reverseXStr.end());

        if (strcmp(xStr.c_str(), reverseXStr.c_str()) != 0)
            return false;

        return true;
    }
};

/**
 * @brief Main function
 */
int main()
{
    Solution solution;

    vector<int> testCases = {
        121,
        122,
        11011,
        -121,
        10,
        0};

    for (auto &&testCase : testCases)
    {
        cout << boolalpha << solution.isPalindrome(testCase) << endl;
    }

    return 0;
}