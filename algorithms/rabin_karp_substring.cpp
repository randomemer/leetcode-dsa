#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
  int M = 1e9 + 7;
  int p = 31;

public:
  int strStr(string haystack, string needle) {
    if (needle.empty())
      return 0;

    int n = haystack.length();
    int m = needle.length();

    vector<long long> p_pow(max(m, n));
    p_pow[0] = 1;

    for (int i = 1; i < (int)p_pow.size(); i++) {
      p_pow[i] = (p_pow[i - 1] * p) % M;
    }

    vector<long long> h(n + 1, 0);
    for (int i = 0; i < n; i++) {
      h[i + 1] = (h[i] + (haystack[i] - 'a' + 1) * p_pow[i]) % M;
    }

    long long h_s = 0;
    for (int i = 0; i < m; i++) {
      h_s = (h_s + (needle[i] - 'a' + 1) * p_pow[i]) % M;
    }

    for (int i = 0; i + m - 1 < n; i++) {
      long long cur_h = (h[i + m] + M - h[i]) % M;

      if (cur_h == h_s * p_pow[i] % M) {
        return i;
      }
    }

    return -1;
  }
};

int main() {
  Solution sol{};
  int res;

  res = sol.strStr("sabbutsad", "sad");
  cout << "Index : " << res << endl;
}