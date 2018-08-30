#include <vector>
using namespace std;
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

static inline int low_bit(int i) { return i & -i; }

class BIT {
  vector<int> nums;

public:
  BIT(int n) : nums(n + 1, 0) {}

  int query(int i) {
    i += 1;
    int res = 0;
    while (i > 0) {
      res += nums[i];
      i -= low_bit(i);
    }
    return res;
  }

  void update(int i, int val) {
    i += 1;
    while (i < nums.size()) {
      nums[i] += val;
      i += low_bit(i);
    }
  }
};

class NumArray {
  vector<int> nums_;
  BIT bit;

public:
  NumArray(vector<int> nums) : bit(nums.size()), nums_(nums.size(), 0) {
    for (int i = 0; i < nums.size(); ++i) {
      update(i, nums[i]);
    }
  }

  void update(int i, int val) {
    int delta = val - nums_[i];
    nums_[i] = val;
    bit.update(i, delta);
  }

  int sumRange(int i, int j) { return bit.query(j) - bit.query(i - 1); }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
