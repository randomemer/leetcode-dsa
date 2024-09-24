#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int nthUglyNumber(int n) {
    vector<int> res(n, 0);
    res[0] = 1;
    int a = 0, b = 0, c = 0;

    for (int i = 1; i < n; i++) {
      int two = res[a] * 2, three = res[b] * 3, five = res[c] * 5;
      int m = min({two, three, five});

      if (m == two) a++;
      if (m == three) b++;
      if (m == five) c++;

      res[i] = m;
    }

    return res[n - 1];
  }
};

int main() { return 0; }