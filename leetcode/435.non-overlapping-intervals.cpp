#include <algorithm>
#include <vector>
using namespace std;
/*
 * [435] Non-overlapping Intervals
 *
 * https://leetcode.com/problems/non-overlapping-intervals/description/
 *
 * algorithms
 * Medium (41.13%)
 * Total Accepted:    24.7K
 * Total Submissions: 60K
 * Testcase Example:  '[[1,2]]'
 *
 *
 * Given a collection of intervals, find the minimum number of intervals you
 * need to remove to make the rest of the intervals non-overlapping.
 *
 *
 * Note:
 *
 * You may assume the interval's end point is always bigger than its start
 * point.
 * Intervals like [1,2] and [2,3] have borders "touching" but they don't
 * overlap each other.
 *
 *
 *
 * Example 1:
 *
 * Input: [ [1,2], [2,3], [3,4], [1,3] ]
 *
 * Output: 1
 *
 * Explanation: [1,3] can be removed and the rest of intervals are
 * non-overlapping.
 *
 *
 *
 * Example 2:
 *
 * Input: [ [1,2], [1,2], [1,2] ]
 *
 * Output: 2
 *
 * Explanation: You need to remove two [1,2] to make the rest of intervals
 * non-overlapping.
 *
 *
 *
 * Example 3:
 *
 * Input: [ [1,2], [2,3] ]
 *
 * Output: 0
 *
 * Explanation: You don't need to remove any of the intervals since they're
 * already non-overlapping.
 *
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
  int eraseOverlapIntervals(vector<Interval> &intervals) {
    sort(intervals.begin(), intervals.end(),
         [](const Interval &i1, const Interval &i2) {
           return i1.start < i2.start;
         });

    int cnt = 0;

    vector<Interval> res;
    for (auto const &interval : intervals) {
      if (!res.empty() && interval.start < res.back().end) {
        cnt += 1;
        res.back().end = min(res.back().end, interval.end);
      } else {
        res.push_back(interval);
      }
    }
    return cnt;
  }
};
