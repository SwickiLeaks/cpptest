
#include <algorithm>
#include <bits/stdc++.h>
#include <ranges>
#include <string>

using namespace std;

#define interval_t vector<int>

/**
 * Function that prints a vector of intervals
 * Used for debugging
 */
void printVectors(vector<interval_t> intervals) {
  for (auto &&in : intervals) {
    cout << "Vector" << endl;
    for (auto &&v : in) {
      cout << v << ", ";
    }
    cout << "" << endl << endl;
  }
}

/**
 * Function that compares two intervals and returns the one with a lower
 * starting value
 */
bool compareIntervals(interval_t &i1, interval_t &i2) { return i1[0] < i2[0]; }

/**
 * Method 2 using std::function
 */
bool ascendingOrder(interval_t &a, interval_t &b) { return a[0] < b[0]; };
std::function<bool(interval_t &, interval_t &)> comparator = ascendingOrder;

/**
 * Method 3 using a external comparator with dynamic variables
 */
class ProxComparator {
  int target;

public:
  ProxComparator(bool target) : target(target) {}
  bool operator()(interval_t &a, interval_t &b) const {
    return target ? a[0] < b[0] : a[0] > b[0];
  }
};

/**
 * @brief Class containing the solution for the problem
 */
class Solution {
public:
  Solution() {}
  ~Solution() {}

  vector<interval_t> merge(vector<interval_t> &intervals) {
    if (intervals.empty())
      return {};

    // Step 1: Sort intervals by start time
    // The [] means we are capturing no external variables
    // sort(intervals.begin(), intervals.end(), comparator);
    // sort(intervals.begin(), intervals.end(), ProxComparator(true));
    // sort(intervals.begin(), intervals.end(), compareIntervals);
    sort(intervals.begin(), intervals.end(),
         [](interval_t &a, interval_t &b) { return a[0] < b[0]; });

    // Step 2: Merge intervals.  Push a copy of the first interval into result
    // to start the iteration
    vector<interval_t> result;
    result.push_back(intervals[0]);

    for (auto &&interval : intervals) {
      interval_t mergedInterval = result.back();

      if (interval[0] <= mergedInterval[1]) {
        mergedInterval[1] = max(mergedInterval[1], interval[1]);
        result.push_back(mergedInterval);
      } else {
        result.push_back(interval);
      }
    }

    // Step 3: Return the result
    return result;
  }
};

/**
 * @brief Main function
 */
int main() {
  Solution solution;

  vector<interval_t> intervals = {{1, 3}, {15, 18}, {8, 10}, {2, 6}, {5, 9}};

  vector<interval_t> result = solution.merge(intervals);

  cout << "Result" << endl;
  cout << "-------------------" << endl;
  printVectors(result);

  return 0;
}