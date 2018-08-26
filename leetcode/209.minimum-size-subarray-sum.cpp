#include <vector>
using namespace std;

/*
 * [209] Minimum Size Subarray Sum
 *
 * https://leetcode.com/problems/minimum-size-subarray-sum/description/
 *
 * algorithms
 * Medium (32.80%)
 * Total Accepted:    131.1K
 * Total Submissions: 398.8K
 * Testcase Example:  '7\n[2,3,1,2,4,3]'
 *
 * Given an array of n positive integers and a positive integer s, find the
 * minimal length of a contiguous subarray of which the sum ≥ s. If there isn't
 * one, return 0 instead.
 *
 * Example: 
 *
 *
 * Input: s = 7, nums = [2,3,1,2,4,3]
 * Output: 2
 * Explanation: the subarray [4,3] has the minimal length under the problem
 * constraint.
 *
 * Follow up:
 *
 * If you have figured out the O(n) solution, try coding another solution of
 * which the time complexity is O(n log n). 
 *
 */
class Solution {
public:
  int minSubArrayLen(int s, vector<int> &nums) {
    int sum = 0;
    int left = 0;
    int minLen = nums.size() + 1;
    for (int right = 0; right < nums.size(); ++right) {
      sum += nums[right];
      while (sum >= s) {
        int currLen = right - left + 1;
        minLen = min(minLen, currLen);

        sum -= nums[left];
        left += 1;
      }
    }

    return minLen > nums.size() ? 0 : minLen;
  }
};
