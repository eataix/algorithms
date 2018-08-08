#include <iostream>
#include <string>
#include <unordered_set>
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

class Solution {
  static inline int timeDiff(int t1, int t2) {
    if (t1 == t2) {
      return numeric_limits<int>::max();
    }

    return ((t2 - t1) + 1440) % 1440;
  }

  static inline int toTime(int h, int m) { return h * 60 + m; }

  void dfs(const vector<int> &digits, int included, string &out, int &best,
           const int target) {
    if (included == 4) {
      int curr_h = out[0] * 10 + out[1];
      int curr_m = out[2] * 10 + out[3];
      if (curr_h > 23 || curr_m > 59) {
        return;
      }
      int curr_time = toTime(curr_h, curr_m);
      if (timeDiff(target, curr_time) < timeDiff(target, best)) {
        best = curr_time;
      }
      return;
    }

    for (int digit : digits) {
      out.push_back(digit);
      dfs(digits, included + 1, out, best, target);
      out.pop_back();
    }
  }

public:
  string nextClosestTime(string time) {
    vector<int> digits{time[0] - '0', time[1] - '0', time[3] - '0',
                       time[4] - '0'};
    string out;
    vector<bool> included(4, false);

    int h = digits[0] * 10 + digits[1];
    int m = digits[2] * 10 + digits[3];

    int now = toTime(h, m);
    int best = now;

    dfs(digits, 0, out, best, now);

    int best_h = best / 60;
    int best_m = best % 60;

    char buff[5];
    sprintf(buff, "%02d:%02d", best / 60, best % 60);
    return string(buff);
  }
};
