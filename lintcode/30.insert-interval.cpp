#include <algorithm>
#include <vector>
using namespace std;
#ifdef DEBUG
classs Interval {
  int start, end;
  Interval(int start, int end) {
    this->start = start;
    this->end = end;
  }
};
#endif

class Solution {
public:
  /**
   * @param intervals: Sorted interval list.
   * @param newInterval: new interval.
   * @return: A new interval list.
   */
  vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    auto it = intervals.begin();

    while (it != intervals.end() && it->start < newInterval.start) {
      it += 1;
    }
    intervals.insert(it, newInterval);

    vector<Interval> res;

    for (const auto &interval : intervals) {
      if (res.empty() || interval.start > res.back().end) {
        res.push_back(interval);
      } else {
        res.back().end = max(res.back().end, interval.end);
      }
    }
    return res;
  }
};
