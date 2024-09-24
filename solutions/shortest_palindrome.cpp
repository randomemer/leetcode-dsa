#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
  int M = 1e9 + 7;
  int p = 31;

public:
  string shortestPalindrome(string s) {
    int n = s.length();

    long long f_hash = 0ll, b_hash = 0ll;
    long long p_pow = 1;

    int x = -1;

    for (int i = 0; i < s.length(); i++) {
      char ch = s[i];
      int k = ch - 'a' + 1;

      f_hash = (f_hash * p + k) % M;
      b_hash = (b_hash + p_pow * k) % M;

      p_pow = (p_pow * p) % M;

      if (f_hash == b_hash) {
        x = i;
      }
    }

    string rem = s.substr(x + 1);
    reverse(rem.begin(), rem.end());

    return rem + s;
  }
};

int main() {
  Solution sol;

  string res = sol.shortestPalindrome("aacecaaa");
  cout << "shortest p = " << res << endl;

  return 0;
}