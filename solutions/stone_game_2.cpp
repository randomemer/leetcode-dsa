#include <bits/stdc++.h>

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 private:
  vector<int> piles;
  int dp[2][100][100];

 public:
  int stoneGameII(vector<int>& piles) {
    this->piles = piles;
    memset(dp, -1, sizeof(dp));

    return recur(0, 1, true);
  }

 private:
  int recur(int i, int m, bool isAlice) {
    if (i == this->piles.size()) {
      return 0;
    }

    if (dp[isAlice][i][m] != -1) return dp[isAlice][i][m];

    int res = (isAlice) ? 0 : INT_MAX;
    int sum = 0;
    int limit = min(2 * m, (int)this->piles.size() - i);

    for (int x = 1; x <= limit; x++) {
      sum += this->piles[i + x - 1];

      if (isAlice) {
        res = max(res, sum + recur(i + x, max(m, x), !isAlice));
      } else {
        res = min(res, recur(i + x, max(m, x), !isAlice));
      }
    }

    return (dp[isAlice][i][m] = res);
  }
};

int main() {
  Solution sol;

  vector<int> piles1 = {2, 7, 9, 4, 4};
  cout << sol.stoneGameII(piles1) << endl;

  vector<int> piles2 = {1, 2, 3, 4, 5, 100};
  cout << sol.stoneGameII(piles2) << endl;

  return 0;
}