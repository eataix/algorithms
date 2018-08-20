#include <unordered_map>
#include <vector>
using namespace std;
/*
 * [560] Subarray Sum Equals K
 *
 * https://leetcode.com/problems/subarray-sum-equals-k/description/
 *
 * algorithms
 * Medium (39.93%)
 * Total Accepted:    34.4K
 * Total Submissions: 86K
 * Testcase Example:  '[1,1,1]\n2'
 *
 * Given an array of integers and an integer k, you need to find the total
 * number of continuous subarrays whose sum equals to k.
 *
 * Example 1:
 *
 * Input:nums = [1,1,1], k = 2
 * Output: 2
 *
 *
 *
 * Note:
 *
 * The length of the array is in range [1, 20,000].
 * The range of numbers in the array is [-1000, 1000] and the range of the
 * integer k is [-1e7, 1e7].
 *
 *
 */
class Solution {
public:
  int subarraySum(vector<int> &nums, int k) {
    int total = 0;
    unordered_map<int, int> m;
    m[0] = 1;
    int res = 0;
    for (int num : nums) {
      total += num;
      res += m[total - k];
      m[total] += 1;
    }
    return res;
  }
};
