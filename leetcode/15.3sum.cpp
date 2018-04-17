#include <iostream>
#include <set>
#include <vector>
using namespace std;
/*
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (21.78%)
 * Total Accepted:    314.3K
 * Total Submissions: 1.4M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array S of n integers, are there elements a, b, c in S such that a
 * + b + c = 0? Find all unique triplets in the array which gives the sum of
 * zero.
 *
 * Note: The solution set must not contain duplicate triplets.
 *
 *
 * For example, given array S = [-1, 0, 1, 2, -1, -4],
 *
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 *
 */
class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    set<int> uniqueNumSet;
    for (int num : nums) {
      uniqueNumSet.insert(num);
    }

    vector<vector<int>> ret;
    for (int i = 0; i < nums.size(); ++i) {
      int a = nums[i];
      for (int j = i + 1; j < nums.size(); ++j) {
        int b = nums[j];
        int target = 0 - a - b;
        if (target != a && target != b &&
            uniqueNumSet.find(target) != uniqueNumSet.cend()) {
          vector<int> r;
          r.push_back(a);
          r.push_back(b);
          r.push_back(target);
          cout << a << " " << b << " " << target << endl;
          ret.push_back(r);
        }
      }
    }
    return ret;
  }
};
