#include <algorithm>
#include <climits>
using namespace std;
/*
 * [29] Divide Two Integers
 *
 * https://leetcode.com/problems/divide-two-integers/description/
 *
 * algorithms
 * Medium (15.73%)
 * Total Accepted:    132.3K
 * Total Submissions: 841.1K
 * Testcase Example:  '10\n3'
 *
 * Given two integers dividend and divisor, divide two integers without using
 * multiplication, division and mod operator.
 *
 * Return the quotient after dividing dividend by divisor.
 *
 * The integer division should truncate toward zero.
 *
 * Example 1:
 *
 *
 * Input: dividend = 10, divisor = 3
 * Output: 3
 *
 * Example 2:
 *
 *
 * Input: dividend = 7, divisor = -3
 * Output: -2
 *
 * Note:
 *
 *
 * Both dividend and divisor will be 32-bit signed integers.
 * The divisor will never be 0.
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of
 * this problem, assume that your function returns 231 − 1 when the division
 * result overflows.
 *
 *
 */
class Solution {
public:
  int divide(int dividend, int divisor) {
    long long m = abs(static_cast<long long>(dividend));
    long long n = abs(static_cast<long long>(divisor));
    long long res{0};

    if (m < n) {
      return 0;
    }

    while (m >= n) {
      long long t = n;
      long long p = 1;
      while (m > (t << 1)) {
        t <<= 1;
        p <<= 1;
      }
      res += p;
      m -= t;
    }
    if ((dividend < 0) ^ (divisor < 0)) {
      res = -res;
    }
    return static_cast<int>(min(res, static_cast<long long>(INT_MAX)));
  }
};
