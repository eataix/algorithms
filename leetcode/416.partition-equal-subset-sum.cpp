#include <vector>
using namespace std;
/*
 * [416] Partition Equal Subset Sum
 *
 * https://leetcode.com/problems/partition-equal-subset-sum/description/
 *
 * algorithms
 * Medium (38.88%)
 * Total Accepted:    42.6K
 * Total Submissions: 109.5K
 * Testcase Example:  '[1,5,11,5]'
 *
 * Given a non-empty array containing only positive integers, find if the array
 * can be partitioned into two subsets such that the sum of elements in both
 * subsets is equal.
 *
 *
 * Note:
 *
 * Each of the array element will not exceed 100.
 * The array size will not exceed 200.
 *
 *
 *
 * Example 1:
 *
 * Input: [1, 5, 11, 5]
 *
 * Output: true
 *
 * Explanation: The array can be partitioned as [1, 5, 5] and [11].
 *
 *
 *
 * Example 2:
 *
 * Input: [1, 2, 3, 5]
 *
 * Output: false
 *
 * Explanation: The array cannot be partitioned into equal sum subsets.
 *
 *
 */
class Solution {
public:
  bool canPartition(vector<int> &nums) {
    auto sum = accumulate(nums.cbegin(), nums.cend(), 0);

    if (sum & 1) {
      return false;
    }
    auto target = sum >> 1;

    vector<bool> dp(target + 1, false);
    dp[0] = true;
    for (int num : nums) {
      for (int i = target; i >= num; --i) {
        dp[i] = dp[i] || dp[i - num];
      }
    }
    return dp.back();
  }
};
