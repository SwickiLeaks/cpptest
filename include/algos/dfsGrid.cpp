
#include <bits/stdc++.h>

using namespace std;

/**
 * Need to brush up on these concepts for every leetcode problem
 * 3. DFS
 */

// Define our grid data structures
using Grid = vector<vector<char>>;
using Point = pair<int, int>;

template <typename VisitFn, typename NeighborFn>
void dfsGrid(const Point &cell, VisitFn shouldVisit, NeighborFn getNeighbors) {
  if (!shouldVisit(cell))
    return;

  // Using callstack
  auto [currentX, currentY] = cell;
  for (const auto &[nx, ny] : getNeighbors(startX, startY)) {
    dfsGrid({nx, ny}, shouldVisit, getNeighbors);
  }
}

/**
 * @brief Class containing the solution for the problem
 */
class Solution {
public:
  Solution() {}
  ~Solution() {}
};

/**
 * @brief Main function
 */
int main() {
  Solution solution;

  // Initialize the grid
  vector<vector<char>> grid = {
      {' ', '#', ' '}, {' ', ' ', ' '}, {'#', ' ', ' '}};

  // Initialize visit and directions DS
  int numRows = grid.size(), numCols = grid[0].size();
  vector<vector<bool>> visited(numRows, vector<bool>(numCols, false));

  // Only for vertical/horizontal traversal
  vector<Point> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

  // Visit Function.  Marks node as visited
  auto shouldVisit = [&](Point p) -> bool {
    auto [x, y] = p;

    // If OoB return false
    if (x < 0 || x >= numRows || y < 0 || y >= numCols)
      return false;

    // If already visited (or any other conditions) return false
    if (visited[x][y])
      return false;

    visited[x][y] = true;
    cout << format("Visited Node [{}, {}]: {}", x, y, grid[x][y]) << endl;
    return true;
  };

  // Neighbor Function.  Returns list of neighbors
  auto getNeighbors = [&](int x, int y) -> vector<Point> {
    vector<Point> neighbors;
    for (auto [dx, dy] : directions) {
      neighbors.emplace_back(x + dx, y + dy);
    }
    return neighbors;
  };

  // Starting point
  Point start = {0, 0};

  dfsGrid(start, shouldVisit, getNeighbors);

  return 0;
}