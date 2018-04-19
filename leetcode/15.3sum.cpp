#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
/*
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (21.78%)
 * Total Accepted:    314.3K
 * Total Submissions: 1.4M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array S of n integers, are there elements a, b, c in S such that a
 * + b + c = 0? Find all unique triplets in the array which gives the sum of
 * zero.
 *
 * Note: The solution set must not contain duplicate triplets.
 *
 *
 * For example, given array S = [-1, 0, 1, 2, -1, -4],
 *
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 *
 */
class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> res;
    if (nums.size() < 3) {
      return res;
    }

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 2; ++i) {
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      int currTarget = -nums[i];
      int left = i + 1;
      int right = nums.size() - 1;
      while (left < right) {
        int currSum = nums[left] + nums[right];
        if (currSum == currTarget) {
          vector<int> sol = {nums[i], nums[left], nums[right]};
          left += 1;
          right -= 1;
          while (nums[left] == nums[left - 1]) {
            left += 1;
          }
          while (nums[right] == nums[right + 1]) {
            right -= 1;
          }
          res.push_back(sol);
        } else if (currSum < currTarget) {
          left += 1;
        } else {
          right -= 1;
        }
      }
    }
    return res;
  }
};
