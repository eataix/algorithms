#include <algorithm>
using namespace std;
/*
 * [233] Number of Digit One
 *
 * https://leetcode.com/problems/number-of-digit-one/description/
 *
 * algorithms
 * Hard (29.12%)
 * Total Accepted:    34.7K
 * Total Submissions: 119.1K
 * Testcase Example:  '13'
 *
 * Given an integer n, count the total number of digit 1 appearing in all
 * non-negative integers less than or equal to n.
 *
 * Example:
 *
 *
 * Input: 13
 * Output: 6
 * Explanation: Digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.
 *
 *
 */
class Solution {
public:
  int countDigitOne(int n) {
    int res = 0;
    for (long long i = 1; i <= n; i *= 10) {
      long long div = i * 10;
      res += (n / div) * i + min(max(n % div - i + 1, 0LL), i);
    }
    return res;
  }
};
