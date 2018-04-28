#include <iostream>
#include <vector>
using namespace std;
/*
 * [303] Range Sum Query - Immutable
 *
 * https://leetcode.com/problems/range-sum-query-immutable/description/
 *
 * algorithms
 * Easy (32.31%)
 * Total Accepted:    94.2K
 * Total Submissions: 291.4K
 * Testcase Example:
 * '["NumArray","sumRange","sumRange","sumRange"]\n[[[-2,0,3,-5,2,-1]],[0,2],[2,5],[0,5]]'
 *
 * Given an integer array nums, find the sum of the elements between indices i
 * and j (i ≤ j), inclusive.
 *
 * Example:
 *
 * Given nums = [-2, 0, 3, -5, 2, -1]
 *
 * sumRange(0, 2) -> 1
 * sumRange(2, 5) -> -1
 * sumRange(0, 5) -> -3
 *
 *
 *
 * Note:
 *
 * You may assume that the array does not change.
 * There are many calls to sumRange function.
 *
 *
 */
class NumArray {
private:
  vector<int> runningSum;

public:
  NumArray(vector<int> nums) {
    runningSum.resize(nums.size() + 1);
    runningSum[0] = 0;
    for (int i = 1; i < nums.size() + 1; ++i) {
      runningSum[i] = runningSum[i - 1] + nums[i - 1];
    }
  }

  int sumRange(int i, int j) { return runningSum[j + 1] - runningSum[i]; }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
#ifdef DEBUG
int main() {
  vector<int> v{-2, 0, 3, -5, 2, -1};
  NumArray ar{v};
  cout << ar.sumRange(0, 2) << endl;
  cout << ar.sumRange(2, 5) << endl;
  cout << ar.sumRange(0, 5) << endl;
}
#endif
