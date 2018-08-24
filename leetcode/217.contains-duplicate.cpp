#include <unordered_set>
#include <vector>
using namespace std;
/*
 * [217] Contains Duplicate
 *
 * https://leetcode.com/problems/contains-duplicate/description/
 *
 * algorithms
 * Easy (47.08%)
 * Total Accepted:    211.3K
 * Total Submissions: 448.7K
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
    return unordered_set<int>{nums.cbegin(), nums.cend()}.size() < nums.size();
  }
};
