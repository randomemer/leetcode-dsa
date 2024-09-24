#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

// distance, vertex
typedef pair<double, int> vpair;

// https://leetcode.com/problems/path-with-maximum-probability

class Solution {
 public:
  double maxProbability(int n, vector<vector<int>>& edges,
                        vector<double>& succProb, int start_node,
                        int end_node) {
    unordered_map<int, vector<vpair>> graph;
    vector<double> dists = vector(n, 0.0);

    for (int i = 0; i < edges.size(); i++) {
      int x = edges[i][0];
      int y = edges[i][1];

      graph[x].push_back(make_pair(succProb[i], y));
      graph[y].push_back(make_pair(succProb[i], x));
    }

    priority_queue<vpair> pq;
    pq.push(make_pair(1.0, start_node));
    dists[start_node] = 1.0;

    while (!pq.empty()) {
      auto [p, u] = pq.top();
      pq.pop();

      if (u == end_node) return p;
      //   cout << "u : " << u << endl;

      for (auto pair : graph[u]) {
        int v = pair.second;
        double prob = p * pair.first;

        if (prob > dists[v]) {
          dists[v] = prob;
          pq.push(make_pair(prob, v));
        }
      }
    }

    return 0.0;
  }
};

int main() {
  Solution sol;

  vector<vector<int>> edges;
  vector<double> probs;
  double res;

  // Testcase 1
  edges = {{0, 1}, {1, 2}, {0, 2}};
  probs = {0.5, 0.5, 0.2};

  res = sol.maxProbability(3, edges, probs, 0, 2);
  cout << "max prob : " << res << endl;

  return 0;
}