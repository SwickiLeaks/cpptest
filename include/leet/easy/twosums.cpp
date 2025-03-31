
#include <bits/stdc++.h>
#include <ranges>

using namespace std;

#define CustomMap unordered_map<int, int>

/**
 * Enumerate function to get the index and value of the container
 * Returns a vector of pairs containing the index and value
 */
// template <typename T>
// auto enumerate(const T &container)
// {
//     vector<pair<int, typename T::value_type>> result;
//     int index = 0;
//     for (const auto &value : container)
//     {
//         result.emplace_back(index++, value);
//     }
//     return result;
// }

/**
 * @brief Class containing the solution for the problem
 */
class Solution
{
public:
    Solution() {}
    ~Solution() {}

    vector<int> twoSum(vector<int> &nums, int target) const
    {
        CustomMap numMap;

        // for (auto &&[index, value] : enumerate(nums))
        for (int index = 0; index < nums.size(); index++)
        {
            int value = nums[index];
            int complement = target - value;

            if (numMap.contains(complement))
                return vector<int>{numMap[complement], index};

            numMap[value] = index;
        }

        return vector<int>{};
    }
};

/**
 * @brief Main function
 */
int main()
{
    Solution solution;

    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = solution.twoSum(nums, target);
    if (!result.empty())
        cout << "Indices: " << result[0] << " " << result[1] << endl;
    else
        cout << "No solution found" << endl;

    return 0;
}