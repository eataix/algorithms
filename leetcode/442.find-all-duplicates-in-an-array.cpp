#include <vector>
using namespace std;
/*
 * [442] Find All Duplicates in an Array
 *
 * https://leetcode.com/problems/find-all-duplicates-in-an-array/description/
 *
 * algorithms
 * Medium (57.48%)
 * Total Accepted:    62.6K
 * Total Submissions: 108.9K
 * Testcase Example:  '[4,3,2,7,8,2,3,1]'
 *
 * Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements
 * appear twice and others appear once.
 *
 * Find all the elements that appear twice in this array.
 *
 * Could you do it without extra space and in O(n) runtime?
 *
 * Example:
 *
 * Input:
 * [4,3,2,7,8,2,3,1]
 *
 * Output:
 * [2,3]
 *
 */
class Solution {
public:
  vector<int> findDuplicates(vector<int> &nums) {
    vector<int> res;

    for (int num : nums) {
      int idx = abs(num) - 1;
      if (nums[idx] > 0) {
        nums[idx] *= -1;
      } else {
        res.push_back(abs(num));
      }
    }

    return res;
  }
};
