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

static inline int lowBit(int i) { return i & -i; }

class NumArray {
  vector<int> nums_;
  int n_;
  vector<int> BIT_;

  void init(int i, int val) {
    i += 1;
    while (i <= n_) {
      BIT_[i] += val;
      i += lowBit(i);
    }
  }

  int getSum(int i) {
    int sum = 0;
    i += 1;

    while (i > 0) {
      sum += BIT_[i];
      i -= lowBit(i);
    }
    return sum;
  }

public:
  NumArray(vector<int> nums) : nums_(nums), n_(nums_.size()), BIT_(n_ + 1, 0) {
    for (int i = 0; i < n_; ++i) {
      init(i, nums_[i]);
    }
  }

  void update(int i, int val) {
    int diff = val - nums_[i];
    nums_[i] = val;
    init(i, diff);
  }

  int sumRange(int i, int j) { return getSum(j) - getSum(i - 1); }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */

#ifdef DEBUG
int main() { NumArray array{{0, 9, 5, 7, 3}}; }
#endif
