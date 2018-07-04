#include <vector>
using namespace std;
/*
 * [34] Search for a Range
 *
 * https://leetcode.com/problems/search-for-a-range/description/
 *
 * algorithms
 * Medium (31.62%)
 * Total Accepted:    189.2K
 * Total Submissions: 598.5K
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * Given an array of integers nums sorted in ascending order, find the starting
 * and ending position of a given target value.
 *
 * Your algorithm's runtime complexity must be in the order of O(log n).
 *
 * If the target is not found in the array, return [-1, -1].
 *
 * Example 1:
 *
 *
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 *
 * Example 2:
 *
 *
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 *
 */
class Solution {
public:
  vector<int> searchRange(vector<int> &nums, int target) {
    if (nums.empty()) {
      return {-1, -1};
    }
    vector<int> res(2, -1);
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] < target) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }

    if (nums[right] != target) {
      return res;
    }

    res[0] = right;

    right = nums.size();
    while (left < right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] <= target) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }

    res[1] = left - 1;
    return res;
  }
};
