#include <iostream>
#include <set>
#include <utility>
#include <vector>

using namespace std;

class MyCalendarTwo {
public:
  set<pair<int, int>> times{};

  MyCalendarTwo() {}

  bool book(int start, int end) {
    auto event = times.upper_bound({start, end});

    // // End of this event should be lesser than or
    // // equal to start of next event
    // if (event != times.end() && !(end <= event->first)) {
    //   return false;
    // }

    // // Start of this event should be greater than or
    // // equal to end of previous event
    // if (event != times.begin()) {
    //   auto prev_event = prev(event);
    //   if (!(start >= prev_event->second))
    //     return false;
    // }

    times.insert({start, end});

    return true;
  }

  void print() {
    cout << "[";
    for (auto &[s, e] : times) {
      cout << "[" << s << ", " << e << "]";
      cout << ", ";
    }

    cout << "]";
  }
};

int main() {
  MyCalendarTwo *cal = new MyCalendarTwo();

  vector<pair<int, int>> bookings = {{10, 20}, {50, 60}, {10, 40},
                                     {5, 15},  {5, 10},  {25, 55}};

  for (auto [s, e] : bookings) {
    bool res = cal->book(s, e);

    cal->print();
    cout << " : " << res << endl;
  }

  auto b1 = cal->times.lower_bound({10, INT_MIN});
  auto b2 = cal->times.lower_bound({10, INT_MAX});

  b2--;

  cout << "b1 = " << b1->first << ", " << b1->second << endl;
  cout << "b2 = " << b2->first << ", " << b2->second << endl;

  return 0;
}