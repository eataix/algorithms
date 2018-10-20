/*
 * [493] Reverse Pairs
 *
 * https://leetcode.com/problems/reverse-pairs/description/
 *
 * algorithms
 * Hard (21.30%)
 * Total Accepted:    16.6K
 * Total Submissions: 78.1K
 * Testcase Example:  '[1,3,2,3,1]'
 *
 * Given an array nums, we call (i, j) an important reverse pair if i < j and
 * nums[i] > 2*nums[j].
 *
 * You need to return the number of important reverse pairs in the given
 * array.
 *
 * Example1:
 *
 * Input: [1,3,2,3,1]
 * Output: 2
 *
 *
 * Example2:
 *
 * Input: [2,4,3,5,1]
 * Output: 3
 *
 *
 * Note:
 *
 * The length of the given array will not exceed 50,000.
 * All the numbers in the input array are in the range of 32-bit integer.
 *
 *
 */
void update(vector<int> &BIT, int index, int val) {
  while (index > 0) {
    BIT[index] += val;
    index -= index & (-index);
  }
}

int query(const vector<int> &BIT, int index) {
  int sum = 0;
  while (index < BIT.size()) {
    sum += BIT[index];
    index += index & (-index);
  }
  return sum;
}

class Solution {
public:
  int reversePairs(vector<int> &nums) {
    int n = nums.size();
    vector<int> nums_copy(nums);

    sort(nums_copy.begin(), nums_copy.end());

    vector<int> BITS(n + 1, 0);
    int count = 0;
    for (int i = 0; i < n; i++) {
      count += query(BITS, lower_bound(nums_copy.begin(), nums_copy.end(),
                                       2LL * nums[i] + 1) -
                               nums_copy.begin() + 1);
      update(BITS,
             lower_bound(nums_copy.begin(), nums_copy.end(), nums[i]) -
                 nums_copy.begin() + 1,
             1);
    }
    return count;
  }
};
