/*
 * [136] Single Number
 *
 * https://leetcode.com/problems/single-number/description/
 *
 * algorithms
 * Easy (55.48%)
 * Total Accepted:    296.1K
 * Total Submissions: 533.7K
 * Testcase Example:  '[2,2,1]'
 *
 * Given a non-empty array of integers, every element appears twice except for
 * one. Find that single one.
 *
 * Note:
 *
 * Your algorithm should have a linear runtime complexity. Could you implement
 * it without using extra memory?
 *
 * Example 1:
 *
 *
 * Input: [2,2,1]
 * Output: 1
 *
 *
 * Example 2:
 *
 *
 * Input: [4,1,2,1,2]
 * Output: 4
 *
 *
 */
class Solution {
public:
  int singleNumber(vector<int> &nums) {
    int ret = 0;
    for (auto &num : nums) {
      ret ^= num;
    }
    return ret;
  }
};
