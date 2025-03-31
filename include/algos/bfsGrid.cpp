#include <bits/stdc++.h>

using namespace std;

/**
 * Need to brush up on these concepts for every leetcode problem
 * 3. BFS
 */

// Define our grid data structures
using Grid = vector<vector<char>>;
using Point = pair<int, int>;

template <typename VisitFn, typename NeighborFn>
void bfsGrid(const Point &start, VisitFn shouldVisit, NeighborFn getNeighbors) {
  // Queue for BFS algo.  Push starting point onto the queue
  queue<Point> q;
  q.push(start);

  // Mark starting point as visited
  shouldVisit(start);

  while (!q.empty()) {
    auto [coordX, coordY] = q.front();
    q.pop();

    // TODO: Perform problem logic on current node

    // Check surrounding nodes and push unvisited on queue
    for (const auto &[nx, ny] : getNeighbors(coordX, coordY)) {
      if (shouldVisit({nx, ny}))
        q.push({nx, ny});
    }
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

    if (x < 0 || x >= numRows || y < 0 || y >= numCols || visited[x][y])
      return false;

    visited[x][y] = true;
    cout << format("Visited Node [{}, {}]: {}", x, y, grid[x][y]) << endl;
    return true;
  };

  // Neighbor Function.  Returns list of neighbors
  auto getNeighbors = [&](int x, int y) -> vector<Point> {
    vector<Point> neighbors;
    for (auto [dx, dy] : directions) {
      int nx = x + dx, ny = y + dy;
      neighbors.emplace_back(nx, ny);
    }
    return neighbors;
  };

  // Starting point
  Point start = {0, 0};

  bfsGrid(start, shouldVisit, getNeighbors);

  return 0;
}