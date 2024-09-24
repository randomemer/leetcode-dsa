#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
 public:
  int findMinDifference(vector<string>& timePoints) {
    int n = timePoints.size();
    vector<int> times(n, 0);

    for (int i = 0; i < n; i++) {
      stringstream ss(timePoints[i]);

      int h, m;
      char dummy;

      ss >> h;
      ss >> dummy;
      ss >> m;

      times[i] = (h * 60) + m;
      cout << times[i] << " - " << h << ":" << m << endl;
    }

    sort(times.begin(), times.end());

    int m = INT_MAX;

    for (int i = 1; i < n; i++) {
      m = min(m, abs(times[i] - times[i - 1]));
    }

    m = min(m, 1440 - times[n - 1] + times[0]);

    return m;
  }
};

int main() {
  Solution sol;

  vector<string> timepoints = {"00:00", "23:59", "00:00"};

  int res = sol.findMinDifference(timepoints);
  std::cout << "res : " << res << endl;

  timepoints = {"00:00", "23:59"};
  res = sol.findMinDifference(timepoints);
  std::cout << "res : " << res << endl;

  timepoints = {"01:01", "02:01", "03:00"};
  res = sol.findMinDifference(timepoints);
  std::cout << "res : " << res << endl;

  return 0;
}