/**
 * Problem Constraints
 *
 * 1. A lane segment is of points on a straight line
 * 2. Segments can only have positive slopes (i.e. y2-y1 / x2-x1 > 0)
 * 3. Only segments with the same slope and overlapping should be merged
 * 4. Input a list of 2D points
 * 5. Output should be a list of merged segments
 */

#include <algorithm>
#include <format>
#include <iostream>
#include <map>
#include <utility>
#include <vector>
using namespace std;

using Point = pair<double, double>;
using Segment = vector<Point>;

class LaneSegments {
public:
  /**
   * @brief Computes the slope between two points
   */
  double computeSlopeOfPoints(Point p1, Point p2) {
    return (p1.second - p2.second) / (p1.first - p2.first);
  }

  /**
   * @brief Computes the slope between two segments
   */
  double computeSlopeOfSegment(Segment s1) {
    return (s1.front().second - s1.back().second) /
           (s1.front().first - s1.back().first);
  }

  /**
   * @brief Determine if two segments are overlapping or not
   * Must have same slope
   */
  bool segmentsOverlapping(Segment &s1, Segment &s2) {
    // Comparator function
    auto compareX = [](const Point &p1, const Point &p2) {
      return p1.first < p2.first;
    };

    if (computeSlopeOfSegment(s1) != computeSlopeOfSegment(s2))
      return false;

    // Min and Max X values for S1
    double s1min = min_element(s1.begin(), s1.end(), compareX)->first;
    double s1max = max_element(s1.begin(), s1.end(), compareX)->first;

    // Min and Max X values for S2
    double s2min = min_element(s2.begin(), s2.end(), compareX)->first;
    double s2max = max_element(s2.begin(), s2.end(), compareX)->first;

    return !(s1max < s2min || s2max < s1min);
  }

  /**
   * @brief Merge together all overlapping segments
   */
  vector<Segment> mergeSegments(const vector<Segment> &inputSegments) {
    vector<Segment> result;

    // TODO: The hard part.  Merge algo for overlapping segments
    map<double, vector<Segment>> slopeGroups;

    // 1. Group segments by slope
    for (const auto &seg : inputSegments) {
      if (seg.size() < 2)
        continue;
      double slope = computeSlopeOfPoints(seg.front(), seg.back());
      slopeGroups[slope].push_back(seg);
    }

    // 2. Sort points in segment then sort the segments in group by x
    for (auto &[slope, group] : slopeGroups) {
      // Need to sort the segments in each group
      for (auto &seg : group) {
        sort(seg.begin(), seg.end());
      }

      sort(group.begin(), group.end(), [](const Segment &a, const Segment &b) {
        return a.front().first < b.front().first;
      });
    }

    // for (const auto &[slope, group] : slopeGroups) {
    //   cout << "Group for slope " << slope << endl;
    //   for (const auto &seg : group) {
    //     cout << "Segment" << endl;
    //     for (const auto &pt : seg) {
    //       cout << format("{}, {}", pt.first, pt.second) << endl;
    //     }
    //   }
    // }

    return result;
  }
};