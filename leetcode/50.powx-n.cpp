/*
 * [50] Pow(x, n)
 *
 * https://leetcode.com/problems/powx-n/description/
 *
 * algorithms
 * Medium (26.06%)
 * Total Accepted:    209.3K
 * Total Submissions: 803.4K
 * Testcase Example:  '2.00000\n10'
 *
 * Implement pow(x, n), which calculates x raised to the power n (xn).
 *
 * Example 1:
 *
 *
 * Input: 2.00000, 10
 * Output: 1024.00000
 *
 *
 * Example 2:
 *
 *
 * Input: 2.10000, 3
 * Output: 9.26100
 *
 *
 * Example 3:
 *
 *
 * Input: 2.00000, -2
 * Output: 0.25000
 * Explanation: 2-2 = 1/22 = 1/4 = 0.25
 *
 *
 * Note:
 *
 *
 * -100.0 < x < 100.0
 * n is a 32-bit signed integer, within the range [−231, 231 − 1]
 *
 *
 * https://www.cnblogs.com/grandyang/p/4383775.html
 *
 */
class Solution {
public:
  double myPow(double x, int n) {
    double res = 1.0;
    for (int i = n; i > 0; i /= 2) {
      if (i % 2 != 0) {
        res *= x;
      }
      x *= x;
    }

    return res;
  }
};
