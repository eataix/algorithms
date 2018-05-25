#include <algorithm>
#include <vector>
using namespace std;
/*
 * [39] Combination Sum
 *
 * https://leetcode.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (41.61%)
 * Total Accepted:    218K
 * Total Submissions: 523.8K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * Given a set of candidate numbers (candidates) (without duplicates) and a
 * target number (target), find all unique combinations in candidates where the
 * candidate numbers sums to target.
 *
 * The same repeated number may be chosen from candidates unlimited number of
 * times.
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
 * Input: candidates = [2,3,6,7], target = 7,
 * A solution set is:
 * [
 * ⁠ [7],
 * ⁠ [2,2,3]
 * ]
 *
 *
 * Example 2:
 *
 *
 * Input: candidates = [2,3,5], target = 8,
 * A solution set is:
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
 * ]
 *
 *
 */
class Solution {
public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<vector<int>> res;
    vector<int> output;
    sort(candidates.begin(), candidates.end());
    combinationSumDFS(candidates, target, 0, output, res);
    return res;
  }

  void combinationSumDFS(const vector<int> &candidates, int target,
                         int startIdx, vector<int> &output,
                         vector<vector<int>> &res) {
    if (target == 0) {
      res.push_back(output);
    } else if (target < 0) {
      return;
    } else {
      for (int i = startIdx; i < candidates.size(); ++i) {
        output.push_back(candidates[i]);
        combinationSumDFS(candidates, target - candidates[i], i, output, res);
        output.pop_back();
      }
    }
  }
};
