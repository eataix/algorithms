#include <algorithm>
#include <vector>
using namespace std;
/*
 * [324] Wiggle Sort II
 *
 * https://leetcode.com/problems/wiggle-sort-ii/description/
 *
 * algorithms
 * Medium (26.52%)
 * Total Accepted:    41.6K
 * Total Submissions: 156.9K
 * Testcase Example:  '[1,5,1,1,6,4]'
 *
 * Given an unsorted array nums, reorder it such that nums[0] < nums[1] >
 * nums[2] < nums[3]....
 *
 * Example 1:
 *
 *
 * Input: nums = [1, 5, 1, 1, 6, 4]
 * Output: One possible answer is [1, 4, 1, 5, 1, 6].
 *
 * Example 2:
 *
 *
 * Input: nums = [1, 3, 2, 2, 3, 1]
 * Output: One possible answer is [2, 3, 1, 3, 1, 2].
 *
 * Note:
 * You may assume all input has valid answer.
 *
 * Follow Up:
 * Can you do it in O(n) time and/or in-place with O(1) extra space?
 *
 */
class Solution {
public:
  void wiggleSort(vector<int> &nums) {
    int n = nums.size();
    auto midPtr = nums.begin() + n / 2;

    nth_element(nums.begin(), midPtr, nums.end());

    int mid = *midPtr;

#define A(i) nums[(1 + 2 * (i)) % (n | 1)]

    int i = 0;
    int j = 0;
    int k = n - 1;
    while (j <= k) {
      if (A(j) > mid) {
        swap(A(i), A(j));
        i += 1;
        j += 1;
      } else if (A(j) < mid) {
        swap(A(j), A(k));
        k -= 1;
      } else {
        j += 1;
      }
    }
  }
};
