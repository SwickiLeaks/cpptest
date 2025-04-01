/**
    Similar to https://leetcode.com/problems/minesweeper/description/. You need
    to implement the following interfaces:

    initiate: generate a minesweeper map randomly.
    click: reveal a cell, if it's a mine, return; otherwise, reveal all
    connected cells and show the number of mines in the surrounding 8 cells.


    Data structures needed
    - grid of chars - vector<vector<char>> board
    - track revealed tiles -  vector<vector<bool>> revealed

    Need to
    - Initiate a random game board with M x N dimensions and "numMines" mines
    - Ability to reveal cell at coord (x, y)
        If it's a mine, reveal it and return
        If not, show the number of adjacent mines
        If it has 0 adjacent mines, flood-fill to reveal connected zero-mine
        cells
 */

#include <bits/stdc++.h>
using namespace std;

class MineSweeper {
private:
  int m, n;
  vector<vector<char>> board;
  vector<vector<bool>> revealed;
  const vector<pair<int, int>> directions = {
      {1, 0}, {-1, 0}, {0, 1}, {0, -1}, {-1, 1}, {-1, -1}, {1, 1}, {1, -1}};

  /**
   * @brief Determine if cell is in bounds or not
   */
  bool cellInBounds(int x, int y) { return x >= 0 && x < m && y >= 0 && y < n; }

  /**
   * @brief Generate mines randomly throughout the board
   */
  void generateMines(int numMines) {
    srand(time(0));
    int placed = 0;

    while (placed < numMines) {
      int x = rand() % m;
      int y = rand() % n;

      if (board[x][y] == 'M')
        continue;

      board[x][y] = 'M';
      placed++;
    }
  }

  /**
   * @brief Counts the number of adjacent mines to another mine
   */
  int countAdjacentMines(int x, int y) {
    int result = 0;

    for (auto &[dx, dy] : directions) {
      int nx = x + dx, ny = y + dy;
      if (cellInBounds(nx, ny) && board[nx][ny] == 'M') {
        result++;
      }
    }

    return result;
  }

public:
  /**
   * @brief Constructor for new minesweeper board
   */
  MineSweeper(int rows, int cols, int numMines) : m(rows), n(cols) {
    // Initialize blank board and false revealed state
    board.assign(m, vector<char>(n, '0'));
    revealed.assign(m, vector<bool>(n, false));

    // Generate mines
    generateMines(numMines);

    cout << "Mines adjacent to (1, 1): " << countAdjacentMines(1, 1) << endl;
  }

  /**
   * @brief Print the game board, which flag to determine whether to show mines
   * or not
   */
  void printBoard(bool showMines = false) {
    cout << "Full Visible Board: " << endl;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (!revealed[i][j])
          cout << "■ ";
        else
          cout << board[i][j] << " ";
      }
      cout << endl;
    }
  }

  /**
   * @brief Perform the action of clicking on a single cell
   * Should reveal cell.  If it's a mine, return;  Otherwise reveal all
   * connected cells and show the number of mines in surrounding 8 cells
   */
  void click(int x, int y) {
    // If attempting to click outside of bounds or a previously revealed cell
    if (!cellInBounds(x, y) || revealed[x][y])
      return;

    // If the cell is a mine
    if (board[x][y] == 'M') {
      revealed[x][y] = true;
      cout << "Clicked Mine" << endl;
      return;
    }

    // If the cell is free, need to reveal
    queue<pair<int, int>> q;
    q.emplace(x, y);

    while (!q.empty()) {
      auto [nx, ny] = q.front();
      q.pop();

      if (!cellInBounds(nx, ny) || revealed[nx][ny])
        continue;

      revealed[nx][ny] = true;

      if (board[nx][ny] != '0')
        continue;

      for (auto [dx, dy] : directions) {
        int nextX = nx + dx, nextY = ny + dy;
        if (cellInBounds(nextX, nextY) && !revealed[nextX][nextY]) {
          q.emplace(nextX, nextY);
        }
      }
    }
  }
};