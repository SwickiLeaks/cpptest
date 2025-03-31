
#include <algorithm>
#include <bits/stdc++.h>
#include <ranges>
#include <string>

using namespace std;

/**
 * Node defintion
 */
class Node {
public:
  int val;
  vector<Node *> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node *>();
  }
  Node(int _val) {
    val = _val;
    neighbors = vector<Node *>();
  }
  Node(int _val, vector<Node *> _neighbors) {
    val = 0;
    neighbors = vector<Node *>(_neighbors);
  }
};

/**
 * @brief Class containing the solution for the problem
 */
class Solution {
public:
  Solution() {}
  ~Solution() {}

  unordered_map<Node *, Node *> clonedNodes;

  Node *cloneGraph(Node *node) {
    if (!node)
      return nullptr;

    // If already visited, return the cloned node
    if (clonedNodes.contains(node)) {
      return clonedNodes[node];
    }

    // Clone the current node
    Node *clonedNode = new Node(node->val);
    clonedNodes[node] = clonedNode;

    // Recursively clone all neighbors
    for (Node *neighbor : node->neighbors) {
      clonedNode->neighbors.push_back(cloneGraph(neighbor));
    }

    return clonedNode;
  }
};

/**
 * @brief Main function
 */
int main() {
  Solution solution;

  Node *node1 = new Node(1);
  Node *node2 = new Node(2);
  Node *node3 = new Node(3);
  Node *node4 = new Node(4);

  node1->neighbors = {node2, node4};
  node2->neighbors = {node1, node3};
  node3->neighbors = {node2, node4};
  node4->neighbors = {node1, node3};

  Node *clonedGraph = solution.cloneGraph(node1);

  return 0;
}