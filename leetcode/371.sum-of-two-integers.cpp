/*
 * [371] Sum of Two Integers
 *
 * https://leetcode.com/problems/sum-of-two-integers/description/
 *
 * algorithms
 * Easy (50.90%)
 * Total Accepted:    95.5K
 * Total Submissions: 187.7K
 * Testcase Example:  '1\n2'
 *
 * Calculate the sum of two integers a and b, but you are not allowed to use
 * the operator + and -.
 *
 * Example:
 * Given a = 1 and b = 2, return 3.
 *
 *
 * Credits:Special thanks to @fujiaozhu for adding this problem and creating
 * all test cases.
 */
class Solution {
public:
  int getSum(int a, int b) {
    if (b == 0) {
      return a;
    }
    if (a == 0) {
      return b;
    }

    int sum = a ^ b;
    int carry = (a & b) << 1;
    return getSum(sum, carry);
  }
};
