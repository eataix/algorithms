#include <iostream>
#include <vector>
using namespace std;
/*
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (40.35%)
 * Total Accepted:    307K
 * Total Submissions: 760.8K
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * Given an integer array nums, find the contiguous subarray (containing at
 * least one number) which has the largest sum and return its sum.
 *
 * Example:
 *
 *
 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 *
 *
 * Follow up:
 *
 * If you have figured out the O(n) solution, try coding another solution using
 * the divide and conquer approach, which is more subtle.
 *
 */
class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    if (nums.size() == 1) {
      return nums[0];
    }

    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    int best = nums[0];

    for (int i = 1; i < nums.size(); ++i) {
      dp[i] = max(dp[i - 1] + nums[i], nums[i]);
      best = max(best, dp[i]);
    }

    return best;
  }
};

#ifdef DEBUG
int main() {
  Solution sol;
  vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};
  cout << sol.maxSubArray(nums) << endl;
}
#endif
