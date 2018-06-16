/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
  /**
   * @param intervals: interval list.
   * @return: A new interval list.
   */
  vector<Interval> merge(vector<Interval> &intervals) {
    auto cmp = [](const Interval &i1, const Interval &i2) {
      return i1.start == i2.start ? i1.end < i2.end : i1.start < i2.start;
    };

    sort(intervals.begin(), intervals.end(), cmp);

    vector<Interval> res;

    for (auto const &interval : intervals) {
      if (res.empty() || res.back().end < interval.start) {
        res.push_back(interval);
      } else {
        res.back().end = max(res.back().end, interval.end);
      }
    }
    return
  }
};
