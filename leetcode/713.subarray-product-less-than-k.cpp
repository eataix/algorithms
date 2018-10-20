/*
 * [713] Subarray Product Less Than K
 *
 * https://leetcode.com/problems/subarray-product-less-than-k/description/
 *
 * algorithms
 * Medium (33.87%)
 * Total Accepted:    17.1K
 * Total Submissions: 50.6K
 * Testcase Example:  '[10,5,2,6]\n100'
 *
 * Your are given an array of positive integers nums.
 * Count and print the number of (contiguous) subarrays where the product of
 * all the elements in the subarray is less than k.
 *
 * Example 1:
 *
 * Input: nums = [10, 5, 2, 6], k = 100
 * Output: 8
 * Explanation: The 8 subarrays that have product less than 100 are: [10], [5],
 * [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6].
 * Note that [10, 5, 2] is not included as the product of 100 is not strictly
 * less than k.
 *
 *
 *
 * Note:
 * 0 < nums.length .
 * 0 < nums[i] < 1000.
 * 0 .
 *
 */
class Solution {
public:
  int numSubarrayProductLessThanK(vector<int> &nums, int k) {
    if (k == 0)
      return 0;
    int cnt = 0;
    int pro = 1;
    for (int i = 0, j = 0; j < nums.size(); j++) {
      pro *= nums[j];
      while (i <= j && pro >= k) {
        pro /= nums[i++];
      }
      cnt += j - i + 1;
    }
    return cnt;
  }
};