#include <cstdint>
using namespace std;
/*
 * [190] Reverse Bits
 *
 * https://leetcode.com/problems/reverse-bits/description/
 *
 * algorithms
 * Easy (29.38%)
 * Total Accepted:    133.1K
 * Total Submissions: 452.9K
 * Testcase Example:  '           0 (00000000000000000000000000000000)'
 *
 * Reverse bits of a given 32 bits unsigned integer.
 *
 * Example:
 *
 *
 * Input: 43261596
 * Output: 964176192
 * Explanation: 43261596 represented in binary as
 * 00000010100101000001111010011100,
 * return 964176192 represented in binary as
 * 00111001011110000010100101000000.
 *
 *
 * Follow up:
 * If this function is called many times, how would you optimize it?
 *
 * Credits:
 * Special thanks to @ts for adding this problem and creating all test cases.
 *
 */
class Solution {
public:
  uint32_t reverseBits(uint32_t n) {
    uint32_t res{0};
    for (int i = 0; i < 32; ++i) {
      res = (res << 1) + (n & 1);
      n >>= 1;
    }
    return res;
  }
};
