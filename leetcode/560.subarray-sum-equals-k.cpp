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
    int cnt = 0;
    int sum = 0;
    unordered_map<int, int> m;

    m[0] = 1;
    for (int i = 0; i < nums.size(); ++i) {
      sum += nums[i];
      if (m.count(sum - k)) {
        cnt += m[sum - k];
      }
      m[sum] += 1;
    }
    return cnt;
  }

  int subarraySum1(vector<int> &nums, int k) {
    int count = 0;
    for (int start = 0; start < nums.size(); ++start) {
      int sum = 0;
      for (int end = start; end < nums.size(); ++end) {
        sum += nums[end];
        if (sum == k) {
          count += 1;
        }
      }
    }
    return count;
  }
};
