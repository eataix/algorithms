#include <unordered_map>
#include <vector>
using namespace std;
/*
 * [325] Maximum Size Subarray Sum Equals k
 *
 * https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/description/
 *
 * algorithms
 * Medium (43.28%)
 * Total Accepted:    57.4K
 * Total Submissions: 132.7K
 * Testcase Example:  '[1,-1,5,-2,3]\n3'
 *
 * Given an array nums and a target value k, find the maximum length of a
 * subarray that sums to k. If there isn't one, return 0 instead.
 *
 * Note:
 * The sum of the entire nums array is guaranteed to fit within the 32-bit
 * signed integer range.
 *
 * Example 1:
 *
 *
 * Input: nums = [1, -1, 5, -2, 3], k = 3
 * Output: 4
 * Explanation: The subarray [1, -1, 5, -2] sums to 3 and is the longest.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [-2, -1, 2, 1], k = 1
 * Output: 2
 * Explanation: The subarray [-1, 2] sums to 1 and is the longest.
 *
 * Follow Up:
 * Can you do it in O(n) time?
 *
 */
class Solution {
public:
  int maxSubArrayLen(vector<int> &nums, int k) {
    unordered_map<int, int> m;

    int total = 0;
    int res = 0;
    for (int i = 0; i < nums.size(); ++i) {
      total += nums[i];

      if (total == k) {
        res = i + 1;
      } else if (m.count(total - k)) {
        res = max(res, i - m[total - k]);
      }

      if (!m.count(total)) {
        m[total] = i;
      }
    }
    return res;
  }
};
