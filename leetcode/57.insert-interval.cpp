#include <vector>
using namespace std;
/*
 * [57] Insert Interval
 *
 * https://leetcode.com/problems/insert-interval/description/
 *
 * algorithms
 * Hard (29.33%)
 * Total Accepted:    132.8K
 * Total Submissions: 452.6K
 * Testcase Example:  '[[1,3],[6,9]]\n[2,5]'
 *
 * Given a set of non-overlapping intervals, insert a new interval into the
 * intervals (merge if necessary).
 *
 * You may assume that the intervals were initially sorted according to their
 * start times.
 *
 * Example 1:
 *
 *
 * Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
 * Output: [[1,5],[6,9]]
 *
 *
 * Example 2:
 *
 *
 * Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
 * Output: [[1,2],[3,10],[12,16]]
 * Explanation: Because the new interval [4,8] overlaps with
 * [3,5],[6,7],[8,10].
 *
 */
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
#ifdef DEBUG
struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};
#endif

class Solution {
public:
  vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    vector<Interval> res;

    int idx = 0;
    for (; idx < intervals.size() && intervals[idx].end < newInterval.start;
         idx += 1) {
      res.push_back(intervals[idx]);
    }

    res.push_back(newInterval);

    for (; idx < intervals.size(); ++idx) {
      if (intervals[idx].start <= res.back().end) {
        res.back().start = min(res.back().start, intervals[idx].start);
        res.back().end = max(res.back().end, intervals[idx].end);
      } else {
        res.push_back(intervals[idx]);
      }
    }
    return res;
  }
};
