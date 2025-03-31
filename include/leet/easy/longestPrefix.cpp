#include <algorithm>
#include <bits/stdc++.h>
#include <ranges>
#include <string>

using namespace std;

/**
 * @brief Class containing the solution for the problem
 */
class Solution {
public:
  Solution() {}
  ~Solution() {}

  string longestCommonPrefix(vector<string> &strs) const {
    if (strs.empty())
      return "";

    string prefix = strs[0];

    for (auto &&str : strs) {
      while (str.find(prefix) != 0) {
        prefix = prefix.substr(0, prefix.size() - 1);
        if (prefix.empty())
          return "";
      }
      reverse(str.begin(), str.end());
    }

    return prefix;
  }
};

/**
 * @brief Main function
 */
int main() {
  Solution solution;

  vector<string> strs = {"flower", "flow", "flight"};
  for (auto &&str : strs)
    cout << str << endl;

  cout << solution.longestCommonPrefix(strs) << endl;

  for (auto &&str : strs)
    cout << str << endl;
  return 0;
}