#include <format>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

template <typename T>

class UnionFind {
 public:
  int count = 0;

  unordered_map<T, T> parent;
  unordered_map<T, int> rank;

  // Find the root of the element with path compression
  T find(const T& x) {
    if (parent[x] != x) {
      parent[x] = find(parent[x]);  // Path compression
    }
    return parent[x];
  }

  // Union of two sets by rank
  void unionSets(const T& x, const T& y) {
    if (!parent.contains(x)) {
      parent[x] = x;
      rank[x] = 1;
    }
    if (!parent.contains(y)) {
      parent[y] = y;
      rank[y] = 1;
    }

    T rootX = find(x);
    T rootY = find(y);

    if (rootX == rootY) return;

    if (rank[rootX] > rank[rootY]) {
      parent[rootY] = rootX;
    } else if (rank[rootX] < rank[rootY]) {
      parent[rootX] = rootY;
    } else {
      parent[rootY] = rootX;
      rank[rootX]++;  // Increment the rank of the new root
    }

    count++;
  }

  // Check if two elements are in the same set
  bool isConnected(const T& x, const T& y) { return find(x) == find(y); }
};

class Solution {
 public:
  int removeStones(vector<vector<int>>& stones) {
    int n = stones.size();
    UnionFind<int> uf(n);

    for (auto s : stones) {
      uf.unionSets(s[0], s[1] + 1e4);
    }

    for (auto [node, p] : uf.parent) {
      int rank = uf.rank[node];
      // cout << format("({}, {})", node, rank) << ", ";

      if (node == p && rank > 1) n--;
    }

    // cout << endl;

    return n;
  }
};

int main() {
  Solution sol;

  vector<vector<int>> tc1, tc2, tc3;
  int res;

  tc1 = {{0, 0}, {0, 1}, {1, 0}, {1, 2}, {2, 1}, {2, 2}};
  res = sol.removeStones(tc1);
  cout << "tc1 : " << res << endl;

  tc2 = {{0, 0}, {0, 2}, {1, 1}, {2, 0}, {2, 2}};
  res = sol.removeStones(tc2);
  cout << "tc2 : " << res << endl;

  tc3 = {{0, 0}};
  res = sol.removeStones(tc3);
  cout << "tc3 : " << res << endl;

  return 0;
}
