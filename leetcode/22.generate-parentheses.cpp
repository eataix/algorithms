#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (48.09%)
 * Total Accepted:    206.6K
 * Total Submissions: 429.7K
 * Testcase Example:  '3'
 *
 *
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 *
 *
 *
 * For example, given n = 3, a solution set is:
 *
 *
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 *
 */
class Solution {
public:
  vector<string> generateParenthesis(int n) {
    vector<string> res;
    dfs(res, "", 0, 0, n);
#ifdef DEBUG
    for (auto str : res) {
      cout << str << endl;
    }
#endif
    return res;
  }

  void dfs(vector<string> &res, const string &str, const int left,
           const int right, const int limit) {
    if (left < right) {
      return;
    }

    if (left == limit && right == limit) {
      res.push_back(str);
      return;
    }

    if (left < limit) {
      dfs(res, str + "(", left + 1, right, limit);
    }

    if (right < limit) {
      dfs(res, str + ")", left, right + 1, limit);
    }
  }
};

#ifdef DEBUG
int main() {
  Solution sol;
  sol.generateParenthesis(3);
}
#endif