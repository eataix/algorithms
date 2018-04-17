using namespace std;
/*
 * [172] Factorial Trailing Zeroes
 *
 * https://leetcode.com/problems/factorial-trailing-zeroes/description/
 *
 * algorithms
 * Easy (36.99%)
 * Total Accepted:    115.6K
 * Total Submissions: 312.5K
 * Testcase Example:  '0'
 *
 * Given an integer n, return the number of trailing zeroes in n!.
 *
 * Note: Your solution should be in logarithmic time complexity.
 *
 * Credits:Special thanks to @ts for adding this problem and creating all test
 * cases.
 */
class Solution {
public:
  int trailingZeroes(int n) {
    int count = 0;
    while (n > 0) {
      count += n / 5;
      n /= 5;
    }
    return count;
  }
};
