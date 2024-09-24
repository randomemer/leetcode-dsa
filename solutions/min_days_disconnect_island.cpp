#include <iostream>
#include <vector>

using namespace std;

class Solution {
 private:
  vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

 public:
  int minDays(vector<vector<int>>& grid) {
    int count = countIslands(grid);
    if (count != 1) return 0;

    // Only one island is present. Break any one island
    // and see if we get any change in island count
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (grid[i][j] == 1) {
          grid[i][j] = 0;

          int c = countIslands(grid);
          if (c != 1) return 1;

          grid[i][j] = 1;
        }
      }
    }

    return 2;
  }

 private:
  int countIslands(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<bool>> visited(m, vector(n, false));
    int count = 0;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1 && !visited[i][j]) {
          dfs(grid, visited, i, j);
          count++;
        }
      }
    }

    return count;
  }

  void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i,
           int j) {
    if (!(0 <= i && i < grid.size()) || !(0 <= j && j < grid[0].size())) return;
    if (grid[i][j] != 1) return;
    if (visited[i][j]) return;

    visited[i][j] = true;

    for (auto& d : dirs) {
      dfs(grid, visited, i + d[0], j + d[1]);
    }
  }
};

int main() {
  Solution sol;

  vector<vector<int>> tc;
  int res;

  tc = {{0, 1, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}};
  res = sol.minDays(tc);
  cout << "tc1 : " << res << endl;

  tc = {{1, 0, 1, 0}};
  res = sol.minDays(tc);
  cout << "tc2 : " << res << endl;

  return 0;
}