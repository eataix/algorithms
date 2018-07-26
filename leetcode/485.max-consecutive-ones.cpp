/*
 * [485] Max Consecutive Ones
 *
 * https://leetcode.com/problems/max-consecutive-ones/description/
 *
 * algorithms
 * Easy (53.74%)
 * Total Accepted:    94.2K
 * Total Submissions: 175.3K
 * Testcase Example:  '[1,0,1,1,0,1]'
 *
 * Given a binary array, find the maximum number of consecutive 1s in this
 * array.
 *
 * Example 1:
 *
 * Input: [1,1,0,1,1,1]
 * Output: 3
 * Explanation: The first two digits or the last three digits are consecutive
 * 1s.
 * ⁠   The maximum number of consecutive 1s is 3.
 *
 *
 *
 * Note:
 *
 * The input array will only contain 0 and 1.
 * The length of input array is a positive integer and will not exceed 10,000
 *
 *
 */
class Solution {
public:
  int findMaxConsecutiveOnes(vector<int> &nums) {
    int maxHere = 0;
    int res = 0;

    for (int num : nums) {
      if (num == 0) {
        maxHere = 0;
      } else {
        maxHere += 1;
      }

      res = max(res, maxHere);
    }
    return res;
  }
};
