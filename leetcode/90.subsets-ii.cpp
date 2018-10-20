#include <vector>
using namespace std;
/*
 * [90] Subsets II
 *
 * https://leetcode.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (39.93%)
 * Total Accepted:    168.4K
 * Total Submissions: 421.6K
 * Testcase Example:  '[1,2,2]'
 *
 * Given a collection of integers that might contain duplicates, nums, return
 * all possible subsets (the power set).
 *
 * Note: The solution set must not contain duplicate subsets.
 *
 * Example:
 *
 *
 * Input: [1,2,2]
 * Output:
 * [
 * ⁠ [2],
 * ⁠ [1],
 * ⁠ [1,2,2],
 * ⁠ [2,2],
 * ⁠ [1,2],
 * ⁠ []
 * ]
 *
 *
 */
class Solution {
public:
  vector<vector<int>> subsetsWithDup(vector<int> &S) {
    if (S.empty())
      return {};
    vector<vector<int>> res;
    vector<int> out;
    sort(S.begin(), S.end());
    dfs(S, 0, out, res);
    return res;
  }

  void dfs(const vector<int> &S, int pos, vector<int> &out,
           vector<vector<int>> &res) {
    res.push_back(out);
    for (int i = pos; i < S.size(); ++i) {
      out.push_back(S[i]);
      dfs(S, i + 1, out, res);
      out.pop_back();
      while (i + 1 < S.size() && S[i] == S[i + 1]) {
        ++i;
      }
    }
  }
};
