#include <vector>
using namespace std;
/*
 * [259] 3Sum Smaller
 *
 * https://leetcode.com/problems/3sum-smaller/description/
 *
 * algorithms
 * Medium (42.42%)
 * Total Accepted:    38.6K
 * Total Submissions: 91.1K
 * Testcase Example:  '[-2,0,1,3]\n2'
 *
 * Given an array of n integers nums and a target, find the number of index
 * triplets i, j, k with 0 <= i < j < k < n that satisfy the condition nums[i]
 * + nums[j] + nums[k] < target.
 *
 * Example:
 *
 *
 * Input: nums = [-2,0,1,3], and target = 2
 * Output: 2
 * Explanation: Because there are two triplets which sums are less than
 * 2:
 * [-2,0,1]
 * ⁠            [-2,0,3]
 *
 *
 * Follow up: Could you solve it in O(n2) runtime?
 *
 */
class Solution {
public:
  int threeSumSmaller(vector<int> &nums, int target) {
    if (nums.size() < 3) {
      return 0;
    }
    sort(nums.begin(), nums.end());
    int sum = 0;
    for (int i = 0; i < nums.size() - 2; ++i) {
      int currTarget = target - nums[i];

      int left = i + 1;
      int right = nums.size() - 1;

      while (left < right) {
        if (nums[left] + nums[right] < currTarget) {
          sum += right - left;
          left += 1;
        } else {
          right -= 1;
        }
      }
    }
    return sum;
  }
};
