#include <vector>
using namespace std;
/*
 * [81] Search in Rotated Sorted Array II
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/
 *
 * algorithms
 * Medium (32.54%)
 * Total Accepted:    129.2K
 * Total Submissions: 397K
 * Testcase Example:  '[2,5,6,0,0,1,2]\n0'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 *
 * (i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).
 *
 * You are given a target value to search. If found in the array return true,
 * otherwise return false.
 *
 * Example 1:
 *
 *
 * Input: nums = [2,5,6,0,0,1,2], target = 0
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [2,5,6,0,0,1,2], target = 3
 * Output: false
 *
 * Follow up:
 *
 *
 * This is a follow up problem to Search in Rotated Sorted Array, where nums
 * may contain duplicates.
 * Would this affect the run-time complexity? How and why?
 *
 *
 */
class Solution {
public:
  bool search(vector<int> &nums, int target) {
    int n = nums.size();
    if (n == 0) {
      return false;
    }

    int left = 0;
    int right = n - 1;

    while (left <= right) {
      int mid = left + (right - left) / 2;

      if (nums[mid] == target) {
        return true;
      } else if (nums[mid] < nums[right]) {
        if (nums[mid] < target && nums[right] >= target) {
          left = mid + 1;
        } else {
          right = mid - 1;
        }
      } else if (nums[mid] > nums[right]) {
        if (nums[left] <= target && nums[mid] > target) {
          right = mid - 1;
        } else {
          left = mid + 1;
        }
      } else {
        right -= 1;
      }
    }

    return false;
  }
};
