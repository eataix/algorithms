#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;
/*
 * [217] Contains Duplicate
 *
 * https://leetcode.com/problems/contains-duplicate/description/
 *
 * algorithms
 * Easy (47.18%)
 * Total Accepted:    214.6K
 * Total Submissions: 454.7K
 * Testcase Example:  '[]'
 *
 *
 * Given an array of integers, find if the array contains any duplicates. Your
 * function should return true if any value appears at least twice in the
 * array, and it should return false if every element is distinct.
 *
 */
class Solution {
public:
  bool containsDuplicate(vector<int> &nums) {
    if (nums.size() <= 1) {
      return false;
    }
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 1; ++i) {
      if (nums[i] == nums[i + 1]) {
        return true;
      }
    }
    return false;
  }
  bool containsDuplicate2(vector<int> &nums) {
    if (nums.size() <= 1) {
      return false;
    }
    unordered_set<int> seen;
    for (int num : nums) {
      if (seen.find(num) != seen.cend()) {
        return true;
      } else {
        seen.insert(num);
      }
    }
    return false;
  }
  bool containsDuplicate3(vector<int> &nums) {
    if (nums.size() <= 1) {
      return false;
    }
    unordered_set<int> seen(nums.cbegin(), nums.cend());
    return nums.size() != seen.size();
  }
};
