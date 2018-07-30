#include <vector>
using namespace std;
/*
 * [368] Largest Divisible Subset
 *
 * https://leetcode.com/problems/largest-divisible-subset/description/
 *
 * algorithms
 * Medium (33.93%)
 * Total Accepted:    36.9K
 * Total Submissions: 108.8K
 * Testcase Example:  '[1,2,3]'
 *
 *
 * Given a set of distinct positive integers, find the largest subset such that
 * every pair (Si, Sj) of elements in this subset satisfies: Si % Sj = 0 or Sj
 * % Si = 0.
 *
 *
 * If there are multiple solutions, return any subset is fine.
 *
 *
 * Example 1:
 *
 * nums: [1,2,3]
 *
 * Result: [1,2] (of course, [1,3] will also be ok)
 *
 *
 *
 * Example 2:
 *
 * nums: [1,2,4,8]
 *
 * Result: [1,2,4,8]
 *
 *
 *
 * Credits:Special thanks to @Stomach_ache for adding this problem and creating
 * all test cases.
 */
class Solution {
public:
  vector<int> largestDivisibleSubset(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<int> dp(nums.size(), 1);
    vector<int> parent(nums.size(), -1);

    int maxV = 0;
    int index = -1;

    for (int i = 0; i < nums.size(); ++i) {
      for (int j = i - 1; j >= 0; --j) {
        if (nums[i] % nums[j] == 0 && 1 + dp[j] > dp[i]) {
          dp[i] = dp[j] + 1;
          parent[i] = j;
        }
      }
      if (dp[i] > maxV) {
        maxV = dp[i];
        index = i;
      }
    }
    vector<int> res;
    while (index != -1) {
      res.push_back(nums[index]);
      index = parent[index];
    }
    reverse(res.begin(), res.end());
    return res;
  }
};
