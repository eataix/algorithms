#include <vector>
using namespace std;
/*
 * [260] Single Number III
 *
 * https://leetcode.com/problems/single-number-iii/description/
 *
 * algorithms
 * Medium (53.50%)
 * Total Accepted:    83K
 * Total Submissions: 155.2K
 * Testcase Example:  '[1,2,1,3,2,5]'
 *
 * Given an array of numbers nums, in which exactly two elements appear only
 * once and all the other elements appear exactly twice. Find the two elements
 * that appear only once.
 *
 * Example:
 *
 *
 * Input:  [1,2,1,3,2,5]
 * Output: [3,5]
 *
 * Note:
 *
 *
 * The order of the result is not important. So in the above example, [5, 3] is
 * also correct.
 * Your algorithm should run in linear runtime complexity. Could you implement
 * it using only constant space complexity?
 *
 *
 */
class Solution {
public:
  vector<int> singleNumber(vector<int> &nums) {
    int diff = 0;
    for (int num : nums) {
      diff ^= num;
    }
    diff &= -diff;

    vector<int> res(2, 0);

    for (int num : nums) {
      if (num & diff) {
        res[0] ^= num;
      } else {
        res[1] ^= num;
      }
    }
    return res;
  }
};
