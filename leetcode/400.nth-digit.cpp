#include <string>
using namespace std;
/*
 * [400] Nth Digit
 *
 * https://leetcode.com/problems/nth-digit/description/
 *
 * algorithms
 * Easy (29.95%)
 * Total Accepted:    37.4K
 * Total Submissions: 125K
 * Testcase Example:  '3'
 *
 * Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8,
 * 9, 10, 11, ...
 *
 * Note:
 * n is positive and will fit within the range of a 32-bit signed integer (n <
 * 231).
 *
 *
 * Example 1:
 *
 * Input:
 * 3
 *
 * Output:
 * 3
 *
 *
 *
 * Example 2:
 *
 * Input:
 * 11
 *
 * Output:
 * 0
 *
 * Explanation:
 * The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a
 * 0, which is part of the number 10.
 *
 *
 */
class Solution {
public:
  int findNthDigit(int n) {
    long long len = 1;
    long long cnt = 9;
    long long start = 1;
    while (n > len * cnt) {
      n -= len * cnt;
      len += 1;
      cnt *= 10;
      start *= 10;
    }

    start += (n - 1) / len;
    auto t = to_string(start);
    return t[(n - 1) % len] - '0';
  }
};
