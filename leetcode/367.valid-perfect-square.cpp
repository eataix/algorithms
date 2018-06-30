/*
 * [367] Valid Perfect Square
 *
 * https://leetcode.com/problems/valid-perfect-square/description/
 *
 * algorithms
 * Easy (38.77%)
 * Total Accepted:    76.7K
 * Total Submissions: 197.8K
 * Testcase Example:  '16'
 *
 * Given a positive integer num, write a function which returns True if num is
 * a perfect square else False.
 *
 *
 * Note: Do not use any built-in library function such as sqrt.
 *
 *
 * Example 1:
 *
 * Input: 16
 * Returns: True
 *
 *
 *
 * Example 2:
 *
 * Input: 14
 * Returns: False
 *
 *
 *
 * Credits:Special thanks to @elmirap for adding this problem and creating all
 * test cases.
 */
class Solution {
public:
  bool isPerfectSquare(int num) {
    long long r = num;
    while (r * r > num) {
      r = (r + num / r) >> 1;
    }

    return r * r == num;
  }
};
