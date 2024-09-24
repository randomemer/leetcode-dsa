#include <iostream>
#include <regex>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string fractionAddition(string expression) {
    regex pattern("([+-]){0,1}(\\d+)\\/(\\d+)");

    sregex_iterator iter(expression.begin(), expression.end(), pattern);
    sregex_iterator end;

    int num = 0, dnum = 1;

    for (; iter != end; iter++) {
      smatch match = *iter;
      string s = match[1].str();
      int n = atoi(match[2].str().c_str());
      int d = atoi(match[3].str().c_str());

      int cd = lcm(dnum, d);

      if (s == "-") {
        num = (num * (cd / dnum)) - (n * (cd / d));
      } else {
        num = (num * (cd / dnum)) + (n * (cd / d));
      }

      dnum = cd;

      // cout << "(" << s << n << "/" << d << ")" << endl;
      // cout << num << "/" << dnum << endl;
    }

    int factor = abs(gcd(dnum, num));
    num /= factor;
    dnum /= factor;

    return to_string(num) + "/" + to_string(dnum);
  }

 private:
  int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
  }

  int lcm(int a, int b) { return a * b / gcd(a, b); }
};

int main() {
  Solution sol;

  string tc1 = "-1/2+1/2";
  string tc3 = "1/3-1/2";

  cout << endl;
  // cout << sol.fractionAddition(tc1) << endl;
  cout << sol.fractionAddition(tc3) << endl;

  return 0;
}