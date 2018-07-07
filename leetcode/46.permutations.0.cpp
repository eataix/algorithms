#include <unordered_set>
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
  void dfs(const vector<int> &nums, vector<vector<int>> &res, vector<int> &out,
           unordered_set<int> &included) {
    if (included.size() == nums.size()) {
      res.push_back(out);
      return;
    }

    for (int num : nums) {
      if (!included.count(num)) {
        out.push_back(num);
        included.insert(num);
        dfs(nums, res, out, included);
        included.erase(num);
        out.pop_back();
      }
    }
  }

public:
  vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> res;
    vector<int> out;
    unordered_set<int> included;
    dfs(nums, res, out, included);
    return res;
  }
};
