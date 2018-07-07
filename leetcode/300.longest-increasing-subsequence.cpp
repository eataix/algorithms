#include <vector>
using namespace std;

/*
 * [300] Longest Increasing Subsequence
 *
 * https://leetcode.com/problems/longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (38.93%)
 * Total Accepted:    124.8K
 * Total Submissions: 320.6K
 * Testcase Example:  '[10,9,2,5,3,7,101,18]'
 *
 *
 * Given an unsorted array of integers, find the length of longest increasing
 * subsequence.
 *
 *
 * For example,
 * Given [10, 9, 2, 5, 3, 7, 101, 18],
 * The longest increasing subsequence is [2, 3, 7, 101], therefore the length
 * is 4. Note that there may be more than one LIS combination, it is only
 * necessary for you to return the length.
 *
 *
 * Your algorithm should run in O(n2) complexity.
 *
 *
 * Follow up: Could you improve it to O(n log n) time complexity?
 *
 * Credits:Special thanks to @pbrother for adding this problem and creating all
 * test cases.
 */
class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    vector<int> dp;
    for (int i = 0; i < nums.size(); ++i) {
      int left = 0;
      int right = dp.size();

      while (left < right) {
        int mid = left + (right - left) / 2;
        if (dp[mid] < nums[i]) {
          left = mid + 1;
        } else {
          right = mid;
        }
      }

      if (right >= dp.size()) {
        dp.push_back(nums[i]);
      } else {
        dp[right] = nums[i];
      }
    }

    return dp.size();
  }
};
