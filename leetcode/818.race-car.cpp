#include <cmath>
#include <vector>
using namespace std;
/*
 * [836] Race Car
 *
 * https://leetcode.com/problems/race-car/description/
 *
 * algorithms
 * Hard (28.05%)
 * Total Accepted:    3.2K
 * Total Submissions: 11.4K
 * Testcase Example:  '3'
 *
 * Your car starts at position 0 and speed +1 on an infinite number line.
 * (Your car can go into negative positions.)
 *
 * Your car drives automatically according to a sequence of instructions A
 * (accelerate) and R (reverse).
 *
 * When you get an instruction "A", your car does the following: position +=
 * speed, speed *= 2.
 *
 * When you get an instruction "R", your car does the following: if your speed
 * is positive then speed = -1 , otherwise speed = 1.  (Your position stays the
 * same.)
 *
 * For example, after commands "AAR", your car goes to positions 0->1->3->3,
 * and your speed goes to 1->2->4->-1.
 *
 * Now for some target position, say the length of the shortest sequence of
 * instructions to get there.
 *
 *
 * Example 1:
 * Input:
 * target = 3
 * Output: 2
 * Explanation:
 * The shortest instruction sequence is "AA".
 * Your position goes from 0->1->3.
 *
 *
 *
 * Example 2:
 * Input:
 * target = 6
 * Output: 5
 * Explanation:
 * The shortest instruction sequence is "AAARA".
 * Your position goes from 0->1->3->7->7->6.
 *
 *
 *
 *
 * Note:
 *
 *
 * 1 <= target <= 10000.
 *
 */
class Solution {
  int helper(vector<int> &dp, int t) {
    if (dp[t] > 0) {
      return dp[t];
    }

    int n = floor(log2(t)) + 1;
    if (1 << n == t + 1) {
      dp[t] = n;
    } else {
      dp[t] = helper(dp, (1 << n) - 1 - t) + n + 1;
      for (int m = 0; m < n - 1; ++m) {
        dp[t] =
            min(dp[t], helper(dp, t - (1 << (n - 1)) + (1 << m)) + n + m + 1);
      }
    }
    return dp[t];
  }

public:
  int racecar(int target) {
    vector<int> dp(10001, 0);
    return helper(dp, target);
  }
};
