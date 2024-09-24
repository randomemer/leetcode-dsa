#include <bits/stdc++.h>

#include <climits>
#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/maximum-number-of-points-with-cost

class Solution {
 private:
  vector<vector<int>> points;
  vector<vector<long long>> memo;

 public:
  long long maxPoints(vector<vector<int>>& points) {
    int m = points.size(), n = points[0].size();
    vector<vector<long long>> dp = vector(m, vector(n, 0LL));

    for (int j = 0; j < n; j++) {
      dp[0][j] = points[0][j];
    }

    for (int i = 1; i < m; i++) {
      vector<long long> left_max(n, 0), right_max(n, 0);

      left_max[0] = dp[i - 1][0];
      for (int j = 1; j < n; j++) {
        left_max[j] = max(left_max[j - 1], dp[i - 1][j] + j);
      }

      right_max[n - 1] = dp[i - 1][n - 1] - (n - 1);
      for (int j = n - 2; j >= 0; j--) {
        right_max[j] = max(right_max[j + 1], dp[i - 1][j] - j);
      }

      for (int j = 0; j < n; j++) {
        dp[i][j] = points[i][j] + max(left_max[j] - j, right_max[j] + j);
      }
    }

    long long mx = 0;
    for (auto& num : dp.back()) {
      mx = max(mx, num);
    }

    return mx;
  }
};

int main() {
  vector<vector<int>> grid1 = {{1, 2, 3}, {1, 5, 1}, {3, 1, 1}};
  vector<vector<int>> grid2 = {{1, 5}, {2, 3}, {4, 2}};

  Solution sol;
  cout << "Max Points : " << sol.maxPoints(grid1) << "\n";
  cout << "Max Points : " << sol.maxPoints(grid2) << endl;

  return 0;
}
