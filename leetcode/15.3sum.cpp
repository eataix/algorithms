#include <algorithm>
#include <iostream>
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
  vector<vector<int>> threeSum(const vector<int> &nums) {
    if (nums.size() < 3) {
      return {};
    }

    int target = 0;
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    for (int i = 0; i < nums.size() - 2; ++i) {
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }

      int firstNum = nums[i];

      int j = i + 1;
      int k = nums.size() - 1;

      while (j < k) {
        int secondNum = nums[j];
        int thirdNum = nums[k];

        int sum = firstNum + secondNum + thirdNum;

        if (sum > target) {
          k -= 1;
        } else if (sum < target) {
          j += 1;
        } else {
          res.push_back({firstNum, secondNum, thirdNum});
          while (j < k && nums[j] == secondNum) {
            j += 1;
          }
          while (j < k && nums[k] == thirdNum) {
            k -= 1;
          }
        }
      }
    }
    return res;
  }
};
