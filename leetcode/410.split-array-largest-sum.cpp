#include <vector>
using namespace std;
/*
 * [410] Split Array Largest Sum
 *
 * https://leetcode.com/problems/split-array-largest-sum/description/
 *
 * algorithms
 * Hard (40.01%)
 * Total Accepted:    26.8K
 * Total Submissions: 67.1K
 * Testcase Example:  '[7,2,5,10,8]\n2'
 *
 * Given an array which consists of non-negative integers and an integer m, you
 * can split the array into m non-empty continuous subarrays. Write an
 * algorithm to minimize the largest sum among these m subarrays.
 *
 *
 * Note:
 * If n is the length of array, assume the following constraints are
 * satisfied:
 *
 * 1 ≤ n ≤ 1000
 * 1 ≤ m ≤ min(50, n)
 *
 *
 *
 * Examples:
 *
 * Input:
 * nums = [7,2,5,10,8]
 * m = 2
 *
 * Output:
 * 18
 *
 * Explanation:
 * There are four ways to split nums into two subarrays.
 * The best way is to split it into [7,2,5] and [10,8],
 * where the largest sum among the two subarrays is only 18.
 *
 *
 */
class Solution {
  bool can_split(vector<int> &nums, int m, int sum) {
    int cnt = 1;
    int currSum = 0;
    for (int i = 0; i < nums.size(); ++i) {
      currSum += nums[i];
      if (currSum > sum) {
        currSum = nums[i];
        cnt += 1;
        if (cnt > m) {
          return false;
        }
      }
    }
    return true;
  }

public:
  int splitArray(vector<int> &nums, int m) {
    long long left = 0;
    long long right = 0;

    for (int i = 0; i < nums.size(); ++i) {
      left = max(left, static_cast<long long>(nums[i]));
      right += nums[i];
    }

    while (left < right) {
      long long mid = left + (right - left) / 2;
      if (can_split(nums, m, mid)) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    return left;
  }

  int splitArray1(vector<int> &nums, int m) {
    int n = nums.size();
    vector<vector<int>> dp(n + 1,
                           vector<int>(m + 1, numeric_limits<int>::max()));
    dp[0][0] = 0;
    vector<int> sums(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
      sums[i] = sums[i - 1] + nums[i - 1];
    }

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        for (int k = 0; k < i; k++) {
          dp[i][j] = min(dp[i][j], max(dp[k][j - 1], sums[i] - sums[k]));
        }
      }
    }
    return dp.back().back();
  }
};
