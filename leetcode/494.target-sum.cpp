#include <unordered_map>
#include <vector>
using namespace std;
/*
 * [494] Target Sum
 *
 * https://leetcode.com/problems/target-sum/description/
 *
 * algorithms
 * Medium (43.84%)
 * Total Accepted:    51.1K
 * Total Submissions: 116.5K
 * Testcase Example:  '[1,1,1,1,1]\n3'
 *
 *
 * You are given a list of non-negative integers, a1, a2, ..., an, and a
 * target, S. Now you have 2 symbols + and -. For each integer, you should
 * choose one from + and - as its new symbol.
 * ⁠
 *
 * Find out how many ways to assign symbols to make sum of integers equal to
 * target S.
 *
 *
 * Example 1:
 *
 * Input: nums is [1, 1, 1, 1, 1], S is 3.
 * Output: 5
 * Explanation:
 *
 * -1+1+1+1+1 = 3
 * +1-1+1+1+1 = 3
 * +1+1-1+1+1 = 3
 * +1+1+1-1+1 = 3
 * +1+1+1+1-1 = 3
 *
 * There are 5 ways to assign symbols to make the sum of nums be target 3.
 *
 *
 *
 * Note:
 *
 * The length of the given array is positive and will not exceed 20.
 * The sum of elements in the given array will not exceed 1000.
 * Your output answer is guaranteed to be fitted in a 32-bit integer.
 *
 *
 */
class Solution {
public:
  int findTargetSumWays(vector<int> &nums, int S) {
    unordered_map<int, int> dp;
    dp[0] = 1;
    for (int num : nums) {
      unordered_map<int, int> m;
      for (auto a : dp) {
        auto sum = a.first;
        auto cnt = a.second;
        m[sum + num] += cnt;
        m[sum - num] += cnt;
      }
      dp = m;
    }
    return dp[S];
  }

  int findTargetSumWays2(vector<int> &nums, int S) {
    int n = nums.size();
    vector<unordered_map<int, int>> dp(n + 1);

    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
      for (auto const &kv : dp[i]) {
        auto sum = kv.first;
        auto cnt = kv.second;

        dp[i + 1][sum + nums[i]] += cnt;
        dp[i + 1][sum - nums[i]] += cnt;
      }
    }

    return dp[n][S];
  }

  int findTargetSumWays1(vector<int> &nums, int S) {
    vector<unordered_map<int, int>> dp(nums.size());
    return helper(nums, S, 0, dp);
  }

  int helper(const vector<int> &nums, int sum, int start,
             vector<unordered_map<int, int>> &dp) {
    if (start == nums.size()) {
      return sum == 0;
    }

    if (dp[start].count(sum)) {
      return dp[start][sum];
    }

    int cnt1 = helper(nums, sum - nums[start], start + 1, dp);
    int cnt2 = helper(nums, sum + nums[start], start + 1, dp);

    return dp[start][sum] = cnt1 + cnt2;
  }
};
