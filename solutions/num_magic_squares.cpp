#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  int numMagicSquaresInside(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    if (m < 3 || n < 3) return false;

    int res = 0;

    for (int i = 0; i < m - 2; i++) {
      for (int j = 0; j < n - 2; j++) {
        res += (int)is_magic(grid, i, j);
      }
    }

    return res;
  }

  bool is_magic(vector<vector<int>>& grid, int i, int j) {
    int total = 15;
    unordered_set<int> s;

    // Check rows and cols;
    for (int x = 0; x < 3; x++) {
      int r = 0, c = 0;

      for (int y = 0; y < 3; y++) {
        int ri = grid[i + x][j + y];
        int ci = grid[i + y][j + x];

        if (!(1 <= ri && ri <= 9)) return false;
        s.insert(ri);

        r += ri;
        c += ci;
      }

      if (r != 15 || c != 15) return false;
    }

    if (s.size() != 9) return false;

    // Check diagonals
    int d1 = 0, d2 = 0;
    for (int di = 0; di < 3; di++) {
      d1 += grid[i + di][j + di];
      d2 += grid[i + di][j + 2 - di];
    }

    if (d1 != 15 || d2 != 15) return false;

    return true;
  }
};

int main() {
  Solution sol;

  vector<vector<int>> tc1, tc2;

  tc1 = {{4, 3, 8, 4}, {9, 5, 1, 9}, {2, 7, 6, 2}};
  tc2 = {{8}};

  cout << sol.numMagicSquaresInside(tc1) << endl;
  cout << sol.numMagicSquaresInside(tc2) << endl;

  return 0;
}