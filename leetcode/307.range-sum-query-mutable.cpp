/*
 * [307] Range Sum Query - Mutable
 *
 * https://leetcode.com/problems/range-sum-query-mutable/description/
 *
 * algorithms
 * Medium (23.47%)
 * Total Accepted:    48.2K
 * Total Submissions: 205.2K
 * Testcase Example:
 * '["NumArray","sumRange","update","sumRange"]\n[[[1,3,5]],[0,2],[1,2],[0,2]]'
 *
 * Given an integer array nums, find the sum of the elements between indices i
 * and j (i ≤ j), inclusive.
 *
 * The update(i, val) function modifies nums by updating the element at index i
 * to val.
 *
 * Example:
 *
 *
 * Given nums = [1, 3, 5]
 *
 * sumRange(0, 2) -> 9
 * update(1, 2)
 * sumRange(0, 2) -> 8
 *
 *
 * Note:
 *
 *
 * The array is only modifiable by the update function.
 * You may assume the number of calls to update and sumRange function is
 * distributed evenly.
 *
 *
 */

class NumArray {
  vector<int> sums;

public:
  NumArray(vector<int> nums) : sums(nums.size() + 1, 0) {
    for (int i = 0; i < nums.size(); ++i) {
      sums[i + 1] = sums[i] + nums[i];
    }
  }

  void update(int i, int val) {
    int diff = val - (sums[i + 1] - sums[i]);
    for (int idx = i + 1; idx < sums.size(); ++idx) {
      sums[idx] += diff;
    }
  }

  int sumRange(int i, int j) { return sums[j + 1] - sums[i]; }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
