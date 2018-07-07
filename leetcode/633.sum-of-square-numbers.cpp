/*
 * [633] Sum of Square Numbers
 *
 * https://leetcode.com/problems/sum-of-square-numbers/description/
 *
 * algorithms
 * Easy (32.47%)
 * Total Accepted:    26.9K
 * Total Submissions: 82.8K
 * Testcase Example:  '5'
 *
 *
 * Given a non-negative integer c, your task is to decide whether there're two
 * integers a and b such that a2 + b2 = c.
 *
 *
 * Example 1:
 *
 * Input: 5
 * Output: True
 * Explanation: 1 * 1 + 2 * 2 = 5
 *
 *
 *
 *
 * Example 2:
 *
 * Input: 3
 * Output: False
 *
 *
 *
 */
class Solution {
public:
  bool judgeSquareSum(int c) {
    for (int i = 2; i * i <= c; ++i) {
      int cnt = 0;
      if (c % i == 0) {
        while (c % i == 0) {
          cnt += 1;
          c /= i;
        }

        if (i % 4 == 3 && cnt % 2 != 0) {
          return false;
        }
      }
    }

    return c % 4 != 3;
  }
};
