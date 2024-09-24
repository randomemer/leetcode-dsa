#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
  for (const auto& elem : vec) {
    os << elem << " ";
  }
  return os;
}

class Solution {
 public:
  int smallestDistancePair(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    cout << "sorted nums : " << nums << endl;

    int mx = nums.back();
    int mx_dist = mx * 2;

    vector<int> prefix(mx_dist, 0);
    unordered_map<int, int> counts;

    // Compute prefix counts
    int i = 0;
    for (int val = 0; val < mx_dist; val++) {
      while (i < nums.size() && nums[i] <= val) {
        i++;
      }
      prefix[val] = i;
    }
    cout << "prefix counts : " << prefix << endl;

    // Build counter
    for (auto it : nums) {
      counts[it]++;
    }

    // Binary search for k in prefix counts
    int lo = 0, hi = mx;
    while (lo < hi) {
      int mid = (lo + hi) / 2;

      int count = count_pairs(nums, prefix, counts, mid);

      if (count < k) {
        lo = mid + 1;
      } else {
        hi = mid;
      }
    }

    return lo;
  }

  int count_pairs(vector<int>& nums, vector<int>& prefix,
                  unordered_map<int, int>& counts, int mx_dist) {
    int count = 0;
    int i = 0;

    while (i < nums.size()) {
      int cur_val = nums[i];
      int cur_val_count = counts[cur_val];

      int pairs_with_larger_values =
          prefix[cur_val + mx_dist] - prefix[cur_val];

      int pairs_with_same_values = cur_val_count * (cur_val_count - 1) / 2;
      count +=
          (pairs_with_larger_values * cur_val_count) + pairs_with_same_values;

      while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
        i++;
      }
      i++;
    }

    return count;
  }
};

int main() {
  Solution sol;

  vector<int> tc1 = {1, 3, 1};
  vector<int> tc2 = {1, 6, 1};

  int res = sol.smallestDistancePair(tc1, 1);
  cout << "kth distance : " << res << endl;

  res = sol.smallestDistancePair(tc2, 3);
  cout << "kth distance : " << res << endl;

  return 0;
}