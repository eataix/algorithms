#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
/*
 * [198] House Robber
 *
 * https://leetcode.com/problems/house-robber/description/
 *
 * algorithms
 * Easy (39.97%)
 * Total Accepted:    195.9K
 * Total Submissions: 490.1K
 * Testcase Example:  '[]'
 *
 * You are a professional robber planning to rob houses along a street. Each
 * house has a certain amount of money stashed, the only constraint stopping
 * you from robbing each of them is that adjacent houses have security system
 * connected and it will automatically contact the police if two adjacent
 * houses were broken into on the same night.
 *
 * Given a list of non-negative integers representing the amount of money of
 * each house, determine the maximum amount of money you can rob tonight
 * without alerting the police.
 *
 * Credits:Special thanks to @ifanchu for adding this problem and creating all
 * test cases. Also thanks to @ts for adding additional test cases.
 */
class Solution {
public:
  int rob(vector<int> &nums) {
    if (nums.empty()) {
      return 0;
    }

    if (nums.size() == 1) {
      return nums[0];
    }

    int minusTwo = 0;
    int minusOne = nums[0];

    for (int i = 1; i < nums.size(); ++i) {
      int curr = max(minusTwo + nums[i], minusOne);

      minusTwo = minusOne;
      minusOne = curr;
    }
    return minusOne;
  }

  int rob1(vector<int> &nums) {
    if (nums.empty()) {
      return 0;
    } else if (nums.size() == 1) {
      return nums[0];
    }

    vector<int> dp(nums.size() + 1, 0);
    dp[1] = nums[0];

    for (int i = 2; i <= nums.size(); ++i) {
      dp[i] = max(nums[i - 1] + dp[i - 2], dp[i - 1]);
    }

#ifdef DEBUG
    for (int i = 0; i < dp.size(); ++i) {
      cout << "dp[" << i << "] = " << dp[i] << endl;
    }
#endif
    return dp[nums.size()];
  }
};

#ifdef DEBUG
int main() {
  Solution sol;
  vector<int> v1{1, 2, 3, 4, 5};
  cout << sol.rob(v1) << endl;
}
#endif
