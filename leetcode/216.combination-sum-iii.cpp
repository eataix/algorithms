#include <vector>
using namespace std;
/*
 * [216] Combination Sum III
 *
 * https://leetcode.com/problems/combination-sum-iii/description/
 *
 * algorithms
 * Medium (48.30%)
 * Total Accepted:    96.4K
 * Total Submissions: 199.6K
 * Testcase Example:  '3\n7'
 *
 *
 * Find all possible combinations of k numbers that add up to a number n, given
 * that only numbers from 1 to 9 can be used and each combination should be a
 * unique set of numbers.
 *
 * Note:
 *
 *
 * All numbers will be positive integers.
 * The solution set must not contain duplicate combinations.
 *
 *
 * Example 1:
 *
 *
 * Input: k = 3, n = 7
 * Output: [[1,2,4]]
 *
 *
 * Example 2:
 *
 *
 * Input: k = 3, n = 9
 * Output: [[1,2,6], [1,3,5], [2,3,4]]
 *
 *
 *
 */
class Solution {
  void dfs(int k, int n, int last, vector<int> &out, vector<vector<int>> &res) {
    if (k == 0 || n < 0) {
      if (k == 0 && n == 0) {
        res.push_back(out);
      }
      return;
    }

    for (int i = last + 1; i <= 9; ++i) {
      out.push_back(i);
      dfs(k - 1, n - i, i, out, res);
      out.pop_back();
    }
  }

public:
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<int> out;
    vector<vector<int>> res;
    dfs(k, n, 0, out, res);
    return res;
  }
};

#ifdef DEBUG
int main() {
  Solution sol;
  sol.combinationSum3(3, 7);
}
#endif