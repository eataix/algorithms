/*
 * [252] Meeting Rooms
 *
 * https://leetcode.com/problems/meeting-rooms/description/
 *
 * algorithms
 * Easy (49.26%)
 * Total Accepted:    52.8K
 * Total Submissions: 107.3K
 * Testcase Example:  '[[0,30],[5,10],[15,20]]'
 *
 * Given an array of meeting time intervals consisting of start and end times
 * [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all
 * meetings.
 *
 * Example 1:
 *
 *
 * Input: [[0,30],[5,10],[15,20]]
 * Output: false
 *
 *
 * Example 2:
 *
 *
 * Input: [[7,10],[2,4]]
 * Output: true
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
  bool canAttendMeetings(vector<Interval> &intervals) {
    if (intervals.size() <= 1) {
      return true;
    }
    sort(intervals.begin(), intervals.end(),
         [](const Interval &i1, const Interval &i2) {
           return i1.start < i2.start;
         });

    int previousEnd = intervals[0].end;
    for (int i = 1; i < intervals.size(); ++i) {
      if (intervals[i].start < previousEnd) {
        return false;
      }
      previousEnd = max(previousEnd, intervals[i].end);
    }

    return true;
  }
};
