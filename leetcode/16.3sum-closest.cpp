#include <algorithm>
#include <vector>
using namespace std;
/*
 * [16] 3Sum Closest
 *
 * https://leetcode.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (31.71%)
 * Total Accepted:    174.5K
 * Total Submissions: 550.2K
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * Given an array nums of n integers and an integer target, find three integers
 * in nums such that the sum is closest to target. Return the sum of the three
 * integers. You may assume that each input would have exactly one solution.
 *
 * Example:
 *
 *
 * Given array nums = [-1, 2, 1, -4], and target = 1.
 *
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 *
 *
 */
class Solution {
public:
  int threeSumClosest(vector<int> &nums, int target) {
    if (nums.size() <= 2) {
      return -1;
    }

    int closest = nums[0] + nums[1] + nums[2];
    int diff = abs(closest - target);
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 2; ++i) {
      int left = i + 1;
      int right = nums.size() - 1;
      while (left < right) {
        int sum = nums[i] + nums[left] + nums[right];
        int newDiff = abs(sum - target);
        if (diff > newDiff) {
          diff = newDiff;
          closest = sum;
        }
        if (sum < target) {
          left += 1;
        } else {
          right -= 1;
        }
      }
    }
    return closest;
  }
};
