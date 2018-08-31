#include <vector>
using namespace std;
/*
 * [47] Permutations II
 *
 * https://leetcode.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (35.75%)
 * Total Accepted:    171.8K
 * Total Submissions: 479.9K
 * Testcase Example:  '[1,1,2]'
 *
 * Given a collection of numbers that might contain duplicates, return all
 * possible unique permutations.
 *
 * Example:
 *
 *
 * Input: [1,1,2]
 * Output:
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
 * ]
 *
 *
 */
class Solution {
  void dfs(const vector<int> &nums, int level, vector<vector<int>> &res,
           vector<int> &out, vector<bool> &used) {
    if (level >= nums.size()) {
      res.push_back(out);
      return;
    }

    for (int i = 0; i < nums.size(); ++i) {
      if (used[i]) {
        continue;
      }
      if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {
        continue;
      }
      used[i] = true;
      out.push_back(nums[i]);
      dfs(nums, level + 1, res, out, used);
      used[i] = false;
      out.pop_back();
    }
  }

public:
  vector<vector<int>> permuteUnique(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    vector<int> out;
    vector<bool> used(nums.size(), false);
    dfs(nums, 0, res, out, used);
    return res;
  }
};
