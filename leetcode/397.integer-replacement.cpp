/*
 * [397] Integer Replacement
 *
 * https://leetcode.com/problems/integer-replacement/description/
 *
 * algorithms
 * Medium (30.59%)
 * Total Accepted:    31.6K
 * Total Submissions: 103.3K
 * Testcase Example:  '8'
 *
 *
 * Given a positive integer n and you can do operations as follow:
 *
 *
 *
 *
 * If n is even, replace n with n/2.
 * If n is odd, you can replace n with either n + 1 or n - 1.
 *
 *
 *
 *
 * What is the minimum number of replacements needed for n to become 1?
 *
 *
 *
 *
 * Example 1:
 *
 * Input:
 * 8
 *
 * Output:
 * 3
 *
 * Explanation:
 * 8 -> 4 -> 2 -> 1
 *
 *
 *
 * Example 2:
 *
 * Input:
 * 7
 *
 * Output:
 * 4
 *
 * Explanation:
 * 7 -> 8 -> 4 -> 2 -> 1
 * or
 * 7 -> 6 -> 3 -> 2 -> 1
 *
 *
 */
class Solution {
public:
  int integerReplacement(int n) {
    long long t = n;
    int cnt = 0;
    while (t > 1) {
      ++cnt;
      if (t & 1) {
        if ((t & 2) && (t != 3)) {
          ++t;
        } else {
          --t;
        }
      } else {
        t >>= 1;
      }
    }
    return cnt;
  }
};
