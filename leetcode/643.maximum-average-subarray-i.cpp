#include <algorithm>
#include <vector>
using namespace std;
/*
 * [643] Maximum Average Subarray I
 *
 * https://leetcode.com/problems/maximum-average-subarray-i/description/
 *
 * algorithms
 * Easy (37.85%)
 * Total Accepted:    33.8K
 * Total Submissions: 89.2K
 * Testcase Example:  '[1,12,-5,-6,50,3]\n4'
 *
 *
 * Given an array consisting of n integers, find the contiguous subarray of
 * given length k that has the maximum average value. And you need to output
 * the maximum average value.
 *
 *
 * Example 1:
 *
 * Input: [1,12,-5,-6,50,3], k = 4
 * Output: 12.75
 * Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75
 *
 *
 *
 * Note:
 *
 * 1 k n
 * Elements of the given array will be in the range [-10,000, 10,000].
 *
 *
 */

class Solution {
public:
  double findMaxAverage(vector<int> &nums, int k) {
    int total = 0;
    for (int i = 0; i < k; ++i) {
      total += nums[i];
    }

    double res = total;
    for (int i = k; i < nums.size(); ++i) {
      total += nums[i];
      total -= nums[i - k];
      res = max(res, static_cast<double>(total));
    }
    return res / k;
  }
};
