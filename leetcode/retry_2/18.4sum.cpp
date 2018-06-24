#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
/*
 * [18] 4Sum
 *
 * https://leetcode.com/problems/4sum/description/
 *
 * algorithms
 * Medium (27.84%)
 * Total Accepted:    163.6K
 * Total Submissions: 587.4K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * Given an array nums of n integers and an integer target, are there elements
 * a, b, c, and d in nums such that a + b + c + d = target? Find all unique
 * quadruplets in the array which gives the sum of target.
 *
 * Note:
 *
 * The solution set must not contain duplicate quadruplets.
 *
 * Example:
 *
 *
 * Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
 *
 * A solution set is:
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
 *
 *
 */
class Solution {
public:
  vector<vector<int>> fourSum(vector<int> nums, int target) {
    if (nums.size() < 4) {
      return {};
    }
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    for (int i = 0; i < nums.size() - 3; ++i) {
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      for (int j = i + 1; j < nums.size() - 2; ++j) {
        if (j > i + 1 && nums[j] == nums[j - 1]) {
          continue;
        }
        int left = j + 1;
        int right = nums.size() - 1;

        while (left < right) {
          int currSum = nums[i] + nums[j] + nums[left] + nums[right];
          int currLeft = nums[left];
          int currRight = nums[right];

          if (currSum == target) {
            res.push_back({nums[i], nums[j], nums[left], nums[right]});

            while (left < right && nums[left] == currLeft) {
              left += 1;
            }
            while (left < right && nums[right] == currRight) {
              right -= 1;
            }
          }

          if (currSum < target) {
            left += 1;
          }

          if (currSum > target) {
            right -= 1;
          }
        }
      }
    }
    return res;
  }
};

#ifdef DEBUG
int main() {
  Solution sol;
  sol.fourSum({1, 0, -1, 0, -2, 2}, 0);
}
#endif
