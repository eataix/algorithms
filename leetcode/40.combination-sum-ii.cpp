#include <algorithm>
#include <vector>
using namespace std;
/*
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (36.10%)
 * Total Accepted:    154.1K
 * Total Submissions: 423.7K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * Given a collection of candidate numbers (candidates) and a target number
 * (target), find all unique combinations in candidates where the candidate
 * numbers sums to target.
 *
 * Each number in candidates may only be used once in the combination.
 *
 * Note:
 *
 *
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 *
 *
 * Example 1:
 *
 *
 * Input: candidates = [10,1,2,7,6,1,5], target = 8,
 * A solution set is:
 * [
 * ⁠ [1, 7],
 * ⁠ [1, 2, 5],
 * ⁠ [2, 6],
 * ⁠ [1, 1, 6]
 * ]
 *
 *
 * Example 2:
 *
 *
 * Input: candidates = [2,5,2,1,2], target = 5,
 * A solution set is:
 * [
 * [1,2,2],
 * [5]
 * ]
 *
 *
 */
class Solution {
public:
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    vector<vector<int>> res;
    sort(candidates.begin(), candidates.end());
    vector<int> out;
    combinationSum2(candidates, target, 0, out, res);
    return res;
  }

  void combinationSum2(const vector<int> &candidates, int target, int start,
                       vector<int> &out, vector<vector<int>> &res) {
    if (target < 0) {
      return;
    } else if (target == 0) {
      res.push_back(out);
    } else {
      for (int i = start; i < candidates.size(); ++i) {
        if (i > start && candidates[i] == candidates[i - 1]) {
          continue;
        }

        out.push_back(candidates[i]);
        combinationSum2(candidates, target - candidates[i], i + 1, out, res);
        out.pop_back();
      }
    }
  }
};
