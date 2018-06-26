#include <vector>
using namespace std;
/*
 * [137] Single Number II
 *
 * https://leetcode.com/problems/single-number-ii/description/
 *
 * algorithms
 * Medium (43.08%)
 * Total Accepted:    138.1K
 * Total Submissions: 320.5K
 * Testcase Example:  '[2,2,3,2]'
 *
 * Given a non-empty array of integers, every element appears three times
 * except for one, which appears exactly once. Find that single one.
 *
 * Note:
 *
 * Your algorithm should have a linear runtime complexity. Could you implement
 * it without using extra memory?
 *
 * Example 1:
 *
 *
 * Input: [2,2,3,2]
 * Output: 3
 *
 *
 * Example 2:
 *
 *
 * Input: [0,1,0,1,0,1,99]
 * Output: 99
 *
 */
class Solution {
public:
  int singleNumber(vector<int> &nums) {
    int b = 0;
    int a = 0;

    for (auto num : nums) {
      b = (b ^ num) & ~a;
      a = (a ^ num) & ~b;
    }
    return b;
  }

  int singleNumber2(vector<int> &nums) {
    int res = 0;
    for (int i = 0; i < 32; ++i) {
      int cnt = 0;
      for (auto num : nums) {
        cnt += (num >> i) & 1;
      }
      res |= (cnt % 3) << i;
    }
    return res;
  }
};
