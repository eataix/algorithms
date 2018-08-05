#include <vector>
using namespace std;
/*
 * [77] Combinations
 *
 * https://leetcode.com/problems/combinations/description/
 *
 * algorithms
 * Medium (42.70%)
 * Total Accepted:    155K
 * Total Submissions: 362.9K
 * Testcase Example:  '4\n2'
 *
 * Given two integers n and k, return all possible combinations of k numbers
 * out of 1 ... n.
 *
 * Example:
 *
 *
 * Input: n = 4, k = 2
 * Output:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 *
 *
 */
class Solution {
  void helper(int n, int k, int level, vector<int> &out,
              vector<vector<int>> &res, vector<bool> &used) {
    if (out.size() == k) {
      res.push_back(out);
      return;
    }

    for (int i = level; i <= n; ++i) {
      if (!used[i]) {
        out.push_back(i);
        used[i] = true;
        helper(n, k, i + 1, out, res, used);
        out.pop_back();
        used[i] = false;
      }
    }
  }

public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
    vector<int> out;
    vector<bool> used(n + 1, false);
    helper(n, k, 1, out, res, used);
    return res;
  }
};
