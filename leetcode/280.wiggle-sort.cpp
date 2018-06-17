#include <algorithm>
#include <vector>
using namespace std;
/*
 * [280] Wiggle Sort
 *
 * https://leetcode.com/problems/wiggle-sort/description/
 *
 * algorithms
 * Medium (58.85%)
 * Total Accepted:    44.4K
 * Total Submissions: 75.5K
 * Testcase Example:  '[3,5,2,1,6,4]'
 *
 * Given an unsorted array nums, reorder it in-place such that nums[0] <=
 * nums[1] >= nums[2] <= nums[3]....
 *
 * Example:
 *
 *
 * Input: nums = [3,5,2,1,6,4]
 * Output: One possible answer is [3,5,1,6,2,4]
 *
 */
class Solution {
public:
  void wiggleSort(vector<int> &nums) {
    bool LT = true;

    for (int i = 0; i < nums.size() - 1; ++i) {
      if (LT && nums[i] > nums[i + 1]) {
        swap(nums[i], nums[i + 1]);
      } else if (!LT && nums[i] < nums[i + 1]) {
        swap(nums[i], nums[i + 1]);
      }
      LT = !LT;
    }
  }

  void wiggleSort2(vector<int> &nums) {
    sort(nums.begin(), nums.end());

    for (int i = 1; i < nums.size() - 1; i += 2) {
      swap(nums[i], nums[i + 1]);
    }
  }
};
