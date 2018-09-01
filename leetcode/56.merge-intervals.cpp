#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
 * [56] Merge Intervals
 *
 * https://leetcode.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (32.00%)
 * Total Accepted:    194.8K
 * Total Submissions: 608.6K
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * Given a collection of intervals, merge all overlapping intervals.
 *
 *
 * For example,
 * Given [1,3],[2,6],[8,10],[15,18],
 * return [1,6],[8,10],[15,18].
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

bool comp(const Interval &i1, const Interval &i2) {
  return i1.start < i2.start;
}

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
  vector<Interval> merge(vector<Interval> &intervals) {
    vector<Interval> res;

    sort(intervals.begin(), intervals.end(),
         [](auto const &i1, auto const &i2) {
           return i1.start < i2.start ||
                  (i1.start == i2.start && i1.end < i2.end);
         });

    for (auto const &i : intervals) {
      if (!res.empty() && res.back().end >= i.start) {
        res.back().end = max(res.back().end, i.end);
      } else {
        res.push_back(i);
      }
    }
    return res;
  }
};
