#include <vector>
using namespace std;
/*
 * [153] Find Minimum in Rotated Sorted Array
 *
 * https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (40.89%)
 * Total Accepted:    193.3K
 * Total Submissions: 472.6K
 * Testcase Example:  '[1]'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 *
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 *
 * Find the minimum element.
 *
 * You may assume no duplicate exists in the array.
 */
class Solution {
public:
  int findMin(vector<int> &nums) {
    int start = 0;
    int end = nums.size() - 1;

    while (start < end) {
      if (nums[start] < nums[end]) {
        return nums[start];
      }
      int mid = (start + end) / 2;
      if (nums[start] > nums[mid]) {
        end = mid;
      } else {
        start = mid + 1;
      }
    }

    return nums[start];
  }
};
