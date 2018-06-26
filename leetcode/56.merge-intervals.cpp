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

class Solution {
public:
  vector<Interval> merge(vector<Interval> &intervals) {
    sort(intervals.begin(), intervals.end(),
         [](const Interval &i1, const Interval &i2) {
           return i1.start < i2.start;
         });

    vector<Interval> res;

    for (int i = 0; i < intervals.size(); ++i) {
      if (!res.empty() && intervals[i].start <= res.back().end) {
        res.back().end = max(res.back().end, intervals[i].end);
      } else {
        res.push_back(intervals[i]);
      }
    }
    return res;
  }

  vector<Interval> merge2(vector<Interval> &intervals) {
    if (intervals.size() <= 1) {
      return intervals;
    }
    vector<Interval> res;
    sort(intervals.begin(), intervals.end(), comp);

    int prevStart = intervals[0].start;
    int prevEnd = intervals[0].end;
    for (int i = 1; i < intervals.size(); ++i) {
      Interval curr = intervals[i];
      if (curr.start > prevEnd) {
        res.emplace_back(prevStart, prevEnd);
        prevStart = curr.start;
        prevEnd = curr.end;
      } else {
        prevEnd = max(prevEnd, curr.end);
      }
    }
    res.emplace_back(prevStart, prevEnd);
    return res;
  }
};
