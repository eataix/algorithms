#include <vector>
using namespace std;
/*
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (47.51%)
 * Total Accepted:    234.5K
 * Total Submissions: 493.5K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a collection of distinct integers, return all possible permutations.
 *
 * Example:
 *
 *
 * Input: [1,2,3]
 * Output:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 *
 *
 */
class Solution {
public:
  vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> res;
    vector<int> out;
    vector<bool> visited(nums.size(), false);
    permuteDFS(nums, 0, res, out, visited);
    return res;
  }

  void permuteDFS(const vector<int> &nums, int level, vector<vector<int>> &res,
                  vector<int> &out, vector<bool> &visited) {
    if (level == nums.size()) {
      res.push_back(out);
    }

    for (int i = 0; i < nums.size(); ++i) {
      if (visited[i]) {
        continue;
      }
      visited[i] = true;
      out.push_back(nums[i]);
      permuteDFS(nums, level + 1, res, out, visited);
      out.pop_back();
      visited[i] = false;
    }
  }
};
