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
    vector<int> output;
    sort(candidates.begin(), candidates.end());
    combinationSum2DFS(candidates, target, 0, res, output);
    return res;
  }

  void combinationSum2DFS(const vector<int> &candidates, int target,
                          int startIdx, vector<vector<int>> &res,
                          vector<int> &output) {
    if (target == 0) {
      res.push_back(output);
    } else if (target < 0) {
      return;
    } else {
      for (int i = startIdx; i < candidates.size(); ++i) {
        if (i > startIdx && candidates[i] == candidates[i - 1]) {
          continue;
        }
        output.push_back(candidates[i]);
        combinationSum2DFS(candidates, target - candidates[i], i + 1, res,
                           output);
        output.pop_back();
      }
    }
  }
};
