#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
/*
 * [1] Two Sum
 *
 * https://leetcode.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (38.00%)
 * Total Accepted:    873.8K
 * Total Submissions: 2.3M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers, return indices of the two numbers such that they
 * add up to a specific target.
 *
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 *
 * Example:
 *
 *
 * Given nums = [2, 7, 11, 15], target = 9,
 *
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 *
 *
 *
 *
 */
class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    vector<int> res(2);
    unordered_map<int, int> m;

    for (int i = 0; i < nums.size(); ++i) {
      int com = target - nums[i];

      if (m.find(com) != m.cend()) {
        res[0] = m[com];
        res[1] = i;
        return res;
      }

      m[nums[i]] = i;
    }
    return res;
  }
};

#ifdef DEBUG
int main() {
  Solution sol;
  vector<int> nums{2, 7, 11, 15};
  sol.twoSum(nums, 9);
}
#endif
