
#include <algorithm>
#include <bits/stdc++.h>
#include <ranges>
#include <string>

using namespace std;

#define grid_t vector<vector<char>>

/**
 * @brief Class containing the solution for the problem
 */
class Solution {
public:
  Solution() {}
  ~Solution() {}

  void dfs(grid_t &grid, int row, int col) {
    // If next cell is out of bounds or if next cell is a '0'
    bool outOfBoundsRow = row < 0 || row >= grid.size();
    bool outOfBoundsCol = col < 0 || col >= grid[0].size();

    if (outOfBoundsCol || outOfBoundsRow || grid[row][col] == '0') {
      return;
    }

    // Mark cell as visited
    grid[row][col] = '0';

    // Depth first search to all surrounding cells
    dfs(grid, row + 1, col); // Move down
    dfs(grid, row - 1, col); // Move up
    dfs(grid, row, col + 1); // Move right
    dfs(grid, row, col - 1); // Move left
  };

  int numIslands(grid_t &grid) {
    int count = 0;

    // Iterate over every cell in the grid
    for (int row = 0; row < grid.size(); row++) {
      for (int col = 0; col < grid[0].size(); col++) {
        if (grid[row][col] == '1') {
          count++;
          dfs(grid, row, col);
        }
      }
    }

    return count;
  }
};

/**
 * @brief Main function
 */
int main() {
  Solution solution;

  grid_t grid = {
      {'1', '1', '0', '0', '0'},
      {'1', '1', '0', '0', '0'},
      {'0', '0', '1', '0', '0'},
      {'0', '0', '0', '1', '1'},
  };

  cout << "Number of islands: " << solution.numIslands(grid) << endl;
  return 0;
}