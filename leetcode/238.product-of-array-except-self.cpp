#include <vector>
using namespace std;
/*
 * [238] Product of Array Except Self
 *
 * https://leetcode.com/problems/product-of-array-except-self/description/
 *
 * algorithms
 * Medium (50.28%)
 * Total Accepted:    146.5K
 * Total Submissions: 291.3K
 * Testcase Example:  '[1,2,3,4]'
 *
 *
 * Given an array of n integers where n > 1, nums, return an array output such
 * that output[i] is equal to the product of all the elements of nums except
 * nums[i].
 *
 * Solve it without division and in O(n).
 *
 * For example, given [1,2,3,4], return [24,12,8,6].
 *
 * Follow up:
 * Could you solve it with constant space complexity? (Note: The output array
 * does not count as extra space for the purpose of space complexity analysis.)
 */
class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    vector<int> left(nums.size(), 1);
    vector<int> right(nums.size(), 1);

    for (int i = 0; i < nums.size(); ++i) {
      if (i > 0) {
        left[i] = left[i - 1] * nums[i - 1];
      }
    }

    for (int i = nums.size() - 1; i >= 0; --i) {
      if (i < nums.size() - 1) {
        right[i] = right[i + 1] * nums[i + 1];
      }
    }

    vector<int> res(nums.size());
    for (int i = 0; i < nums.size(); ++i) {
      res[i] = left[i] * right[i];
    }
    return res;
  }
};
