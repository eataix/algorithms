#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;
/*
 * [169] Majority Element
 *
 * https://leetcode.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (48.08%)
 * Total Accepted:    258.9K
 * Total Submissions: 538.5K
 * Testcase Example:  '[1]'
 *
 * Given an array of size n, find the majority element. The majority element is
 * the element that appears more than ⌊ n/2 ⌋ times.
 *
 * You may assume that the array is non-empty and the majority element always
 * exist in the array.
 *
 * Credits:Special thanks to @ts for adding this problem and creating all test
 * cases.
 */
class Solution {
public:
  int majorityElement(vector<int> &nums) {
    int res = 0;
    int count = 0;
    for (int num : nums) {
      if (count == 0) {
        res = num;
      }
      count += (num == res) ? 1 : -1;
    }
    return res;
  }

  int majorityElement1(vector<int> &nums) {
    unordered_map<int, int> count;

    for (int i : nums) {
      if (++count[i] > nums.size() / 2) {
        return i;
      }
    }
  }

  int majorityElement2(vector<int> &nums) {
    nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());
    return nums[nums.size() / 2];
  }
};
