#include <climits>
#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/increasing-triplet-subsequence/

class Solution {
public:
  bool increasingTriplet(vector<int> &nums) {
    int smallest = INT_MAX; // Smallest number of all
    int smaller =
        INT_MAX; // Smallest number which has a smaller number before it

    for (auto num : nums) {
      // update global min
      if (num <= smallest) {
        smallest = num;
      }
      // Just check if nums[i] is greater than s(smallest number till now).
      else if (num <= smaller) {
        smaller = num;
      }
      // if a number is greater than second smallest num, then its a triplet
      else {
        return true;
      }
    }

    return false;
  }
};

int main() {
  Solution sol;

  vector<int> nums;
  bool res;

  cout << boolalpha;

  nums = {2, 1, 5, 0, 4, 6};
  res = sol.increasingTriplet(nums);
  cout << res << endl;

  nums = {2, 1, 5, 0, 6};
  res = sol.increasingTriplet(nums);
  cout << res << endl;
}