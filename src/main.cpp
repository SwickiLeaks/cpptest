#include <format>
#include <interviewDB/minesweeper.hpp>
#include <iostream>
#include <leet/medium/strings/longestPalindrome.hpp>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * @brief Main function
 */
int main() {

  class MineSweeper ms(5, 5, 5);

  ms.printBoard(true);

  // MessageParser mp;
  // vector<string> input = {
  //     "// Begin Input",   "Message Vehicle",  "float x_position",
  //     "float y_position", "float velocity",   "float acceleration",
  //     "int num_wheels",   "string name",      "",
  //     "Message Vector2d", "float x_position", "float y_position",
  //     "// End Input"};
  // mp.parse(input);

  // vector<Segment> input = {{{1, 1}, {2, 2}, {4, 4}},
  //                          {{2.5, 2.5}, {3.5, 3.5}},
  //                          {{2, 1}, {4, 2}},
  //                          {{3, 3}, {6, 6}},
  //                          {{8, 8}, {9, 9}},
  //                          {{1, 1},
  //                           {2, 2},
  //                           {4, 4},
  //                           {2.5, 2.5},
  //                           {3.5, 3.5},
  //                           {3, 3},
  //                           {6, 6},
  //                           {8, 8},
  //                           {9, 9}}};

  // LaneSegments ls;

  // vector<Segment> mergedSegments = ls.mergeSegments(input);

  // for (const auto &s : mergedSegments) {
  //   cout << "Merged Segment" << endl;
  //   for (const auto &p : s) {
  //     cout << format("{}, {}", p.first, p.second) << endl;
  //   }
  // }

  return 0;
}