
#include <algorithm>
#include <bits/stdc++.h>
#include <ranges>
#include <string>

using namespace std;

// Some definitions to clean things up
#define adjacency_list_t vector<vector<pair<int, int>>>
#define min_heap_queue_t                                                       \
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>

/**
 * @brief Helper to print out adjacency list
 */
void printAdjList(vector<vector<pair<int, int>>> aList) {
  cout << "Adjacency List:" << endl;
  for (size_t i = 0; i < aList.size(); i++) {
    cout << format("Node {} -> ", i);
    if (aList[i].empty())
      cout << "[]";
    else {
      for (auto &&[neighbor, weight] : aList[i]) {
        cout << "[" << neighbor << ", " << weight << "]";
      }
    }
    cout << endl;
  }
  cout << endl;
}

/**
 * @brief print the minHeap
 */
void printQueue(min_heap_queue_t q) {
  cout << "Priority Queue: " << endl;
  auto copy = q;
  while (!copy.empty()) {
    auto [distance, node] = copy.top();
    cout << distance << ", " << node << endl;
    copy.pop();
  }
  cout << endl;
}

/**
 * @brief Print vector of ints
 */
void printVector(vector<int> v) {
  // Print the starting distance vector
  for (size_t i = 0; i < v.size(); i++) {
    cout << format("Node {} -> {}", i, v[i]) << endl;
  }
  cout << endl;
}

/**
 * @brief Graph definition
 */
class Graph {
public:
};

/**
 * @brief Class containing the solution for the problem
 */
class Solution {
public:
  Solution() {}
  ~Solution() {}

  // Starting node = k
  // Number of nodes = n
  int networkDelayTime(vector<vector<int>> &times, int n, int k) {
    // Starting Node K
    cout << format("Starting Node {}", k) << endl << endl;

    // Create the graph representation using adjacency list
    adjacency_list_t graph(n + 1);
    for (const auto &time : times) {
      int u = time[0], v = time[1], w = time[2];
      graph[u].emplace_back(make_pair(v, w));
    }

    printAdjList(graph);

    // Priority queue (min heap) for Dijkstra's algo
    min_heap_queue_t minHeap;

    // Distance array initialized to INF.
    // Initialize the distance to starting node (k) = 0
    vector<int> dist(n + 1, INT_MAX);
    dist[k] = 0;

    // Print the starting distance vector
    printVector(dist);

    // Start algo from starting node (k)
    minHeap.emplace(0, k);

    while (!minHeap.empty()) {
      printQueue(minHeap);

      // Get the current distance so far
      auto [currentDistance, currentNode] = minHeap.top();
      minHeap.pop();

      cout << "Evaluating Node: " << currentNode << endl;

      // Only want to update the distance vector if current route is shorter to
      // the current node
      if (currentDistance > dist[currentNode])
        continue;

      // Go through neighbors and decide which to emplace on heap for eval
      for (auto &&[neighbor, neighborDistance] : graph[currentNode]) {
        int nextTravel = currentDistance + neighborDistance;

        if (nextTravel < dist[neighbor]) {
          dist[neighbor] = nextTravel;
          minHeap.emplace(nextTravel, neighbor);
        }
      }
    }

    printVector(dist);
    int maxTime = *max_element(dist.begin() + 1, dist.end());
    return maxTime == INT_MAX ? -1 : maxTime;
  }
};

/**
 * @brief Main function
 */
int main() {
  Solution solution;

  vector<vector<int>> times = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
  int n = 4, k = 2;
  int result = solution.networkDelayTime(times, n, k);
  cout << "Result: " << result << endl;

  return 0;
}