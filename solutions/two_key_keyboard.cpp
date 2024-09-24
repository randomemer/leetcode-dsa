#include <iostream>
#include <vector>

using namespace std;

class Solution {
 private:
  int n;

 public:
  int minSteps(int n) {
    this->n = n;
    return this->recur(1, 0);
  }

  long long recur(int i, int copy) {
    if (i == this->n) return 0;

    // cout << i << ", " << copy << endl;

    long long copying = (i != copy) ? 1 + recur(i, i) : INT_MAX;
    long long pasting = ((copy > 0) && (i + copy <= this->n))
                            ? 1 + recur(i + copy, copy)
                            : INT_MAX;

    return min(copying, pasting);
  }
};

int main() {
  Solution sol;
  cout << sol.minSteps(3) << endl;
  cout << sol.minSteps(1) << endl;

  return 0;
}