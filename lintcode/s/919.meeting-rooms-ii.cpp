#include <queue>
#include <stack>
#include <vector>
using namespace std;
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

#ifdef DEBUG
struct Interval {
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
   * @param intervals: an array of meeting time intervals
   * @return: the minimum number of conference rooms required
   */
  int minMeetingRooms(vector<Interval> &intervals) {
    sort(intervals.begin(), intervals.end(),
         [](const Interval &i1, const Interval &i2) {
           return i1.start < i2.start;
         });

    auto cmp = [](const Interval &i1, const Interval &i2) {
      return i1.end > i2.end;
    };
    priority_queue<Interval, vector<Interval>, decltype(cmp)> q{cmp};

    for (auto const &interval : intervals) {
      if (!q.empty() && q.top().end <= interval.start) {
        q.pop();
      }

      q.push(interval);
    }

    return q.size();
  }
};
