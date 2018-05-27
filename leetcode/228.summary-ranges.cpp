#include <string>
#include <vector>
using namespace std;
/*
 * [228] Summary Ranges
 *
 * https://leetcode.com/problems/summary-ranges/description/
 *
 * algorithms
 * Medium (32.45%)
 * Total Accepted:    100.8K
 * Total Submissions: 310.5K
 * Testcase Example:  '[0,1,2,4,5,7]'
 *
 * Given a sorted integer array without duplicates, return the summary of its
 * ranges.
 *
 * Example 1:
 *
 *
 * Input:  [0,1,2,4,5,7]
 * Output: ["0->2","4->5","7"]
 * Explanation: 0,1,2 form a continuous range; 4,5 form a continuous range.
 *
 *
 * Example 2:
 *
 *
 * Input:  [0,2,3,4,6,8,9]
 * Output: ["0","2->4","6","8->9"]
 * Explanation: 2,3,4 form a continuous range; 8,9 form a continuous range.
 *
 *
 *
 *
 */
class Solution {
public:
  vector<string> summaryRanges(vector<int> &nums) {
    vector<string> res;
    int start = 0;
    int n = nums.size();

    while (start < n) {
      int len = 1;
      while (start + len < n && nums[start + len] == nums[start] + len) {
        len += 1;
      }

      if (len == 1) {
        res.push_back(to_string(nums[start]));
      } else {
        res.push_back(to_string(nums[start]) + "->" +
                      to_string(nums[start + len - 1]));
      }
      start += len;
    }
    return res;
  }
};
