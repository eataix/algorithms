#include <algorithm>
#include <vector>
using namespace std;
/*
 * [31] Next Permutation
 *
 * https://leetcode.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (29.08%)
 * Total Accepted:    150.4K
 * Total Submissions: 517.3K
 * Testcase Example:  '[1,2,3]'
 *
 * Implement next permutation, which rearranges numbers into the
 * lexicographically next greater permutation of numbers.
 *
 * If such arrangement is not possible, it must rearrange it as the lowest
 * possible order (ie, sorted in ascending order).
 *
 * The replacement must be in-place and use only constant extra memory.
 *
 * Here are some examples. Inputs are in the left-hand column and its
 * corresponding outputs are in the right-hand column.
 *
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 *
 * https://leetcode.com/problems/next-permutation/discuss/13867/A-simple-algorithm-from-Wikipedia-with-C++-implementation-(can-be-used-in-Permutations-and-Permutations-II)
 */
class Solution {
public:
  void nextPermutation(vector<int> &nums) {
    int k = -1;
    for (int i = nums.size() - 2; i >= 0; --i) {
      if (nums[i] < nums[i + 1]) {
        k = i;
        break;
      }
    }

    if (k == -1) {
      reverse(begin(nums), end(nums));
      return;
    } else {
      int l = -1;

      for (int i = nums.size() - 1; i > k; --i) {
        if (nums[i] > nums[k]) {
          l = i;
          break;
        }
      }
      swap(nums[k], nums[l]);
      reverse(begin(nums) + k + 1, end(nums));
    }
  }
};
