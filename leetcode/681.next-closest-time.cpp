#include <string>
#include <vector>
using namespace std;
/*
 * [681] Next Closest Time
 *
 * https://leetcode.com/problems/next-closest-time/description/
 *
 * algorithms
 * Medium (41.51%)
 * Total Accepted:    17.7K
 * Total Submissions: 42.6K
 * Testcase Example:  '"19:34"'
 *
 * Given a time represented in the format "HH:MM", form the next closest time
 * by reusing the current digits. There is no limit on how many times a digit
 * can be reused.
 *
 * You may assume the given input string is always valid. For example, "01:34",
 * "12:09" are all valid. "1:34", "12:9" are all invalid.
 *
 * Example 1:
 *
 * Input: "19:34"
 * Output: "19:39"
 * Explanation: The next closest time choosing from digits 1, 9, 3, 4, is
 * 19:39, which occurs 5 minutes later.  It is not 19:33, because this occurs
 * 23 hours and 59 minutes later.
 *
 *
 *
 * Example 2:
 *
 * Input: "23:59"
 * Output: "22:22"
 * Explanation: The next closest time choosing from digits 2, 3, 5, 9, is
 * 22:22. It may be assumed that the returned time is next day's time since it
 * is smaller than the input time numerically.
 *
 *
 */

static inline int toMinutes(int h, int m) { return h * 60 + m; }

static inline bool isValid(const vector<int> &time) {
  int h = time[0] * 10 + time[1];
  int m = time[2] * 10 + time[3];
  return h <= 23 && m <= 59;
}

static inline int toMinute(const vector<int> &time) {
  int h = time[0] * 10 + time[1];
  int m = time[2] * 10 + time[3];
  return toMinutes(h, m);
}

static inline int timeDiff(int t1, int t2) {
  if (t1 == t2) {
    return numeric_limits<int>::max();
  }
  return (t1 - t2 + 1440) % 1440;
}

static inline int timeDiff(const vector<int> &t1, const vector<int> &t2) {
  return timeDiff(toMinute(t1), toMinute(t2));
}

static inline string toStr(const vector<int> &time) {
  return to_string(time[0]) + to_string(time[1]) + ":" + to_string(time[2]) +
         to_string(time[3]);
}

class Solution {
  void dfs(vector<int> &out, const vector<int> &digits, vector<int> &best,
           const vector<int> &target) {
    if (out.size() == 4) {
      if (isValid(out) && timeDiff(out, target) < timeDiff(best, target)) {
        best = out;
      }
      return;
    }

    for (int d : digits) {
      out.push_back(d);
      dfs(out, digits, best, target);
      out.pop_back();
    }
  }

public:
  string nextClosestTime(string time) {
    vector<int> digits{time[0] - '0', time[1] - '0', time[3] - '0',
                       time[4] - '0'};
    vector<int> out;
    vector<int> now = digits;
    vector<int> best = now;

    dfs(out, digits, best, now);

    return toStr(best);
  }
};
