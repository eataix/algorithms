#include <algorithm>
#include <vector>
using namespace std;
/*
 * [169] Majority Element
 *
 * https://leetcode.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (48.07%)
 * Total Accepted:    259.1K
 * Total Submissions: 538.7K
 * Testcase Example:  '[1]'
 *
 * Given an array of size n, find the majority element. The majority element is
 * the element that appears more than ⌊ n/2 ⌋ times.
 *
 * You may assume that the array is non-empty and the majority element always
 * exist in the array.
 *
 * Example 1:
 *
 *
 * Input: [3,2,3]
 * Output: 3
 *
 * Example 2:
 *
 *
 * Input: [2,2,1,1,1,2,2]
 * Output: 2
 *
 * Credits:
 * Special thanks to @ts for adding this problem and creating all test cases.
 *
 */
class Solution {
public:
  int majorityElement(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    return nums[nums.size() / 2];
  }
};
