#include <string>
#include <vector>
using namespace std;
/*
 * [301] Remove Invalid Parentheses
 *
 * https://leetcode.com/problems/remove-invalid-parentheses/description/
 *
 * algorithms
 * Hard (36.00%)
 * Total Accepted:    72.7K
 * Total Submissions: 201.9K
 * Testcase Example:  '"()())()"'
 *
 * Remove the minimum number of invalid parentheses in order to make the input
 * string valid. Return all possible results.
 *
 * Note: The input string may contain letters other than the parentheses ( and
 * ).
 *
 * Example 1:
 *
 *
 * Input: "()())()"
 * Output: ["()()()", "(())()"]
 *
 *
 * Example 2:
 *
 *
 * Input: "(a)())()"
 * Output: ["(a)()()", "(a())()"]
 *
 *
 * Example 3:
 *
 *
 * Input: ")("
 * Output: [""]
 *
 *
 */
class Solution {
  void dfs(const string &s, vector<string> &res, int last_i, int last_j,
           const vector<char> &p) {
    int stack = 0;
    for (int i = last_i; i < s.size(); ++i) {
      if (s[i] == p[0]) {
        stack += 1;
      }

      if (s[i] == p[1]) {
        stack -= 1;
      }

      if (stack >= 0) {
        continue;
      }

      for (int j = last_j; j <= i; ++j) {
        if (s[j] == p[1] && (j == last_j || s[j - 1] != s[j])) {
          dfs(s.substr(0, j) + s.substr(j + 1), res, i, j, p);
        }
      }
      return;
    }

    string rev = string{s.crbegin(), s.crend()};
    if (p[0] == '(') {
      dfs(rev, res, 0, 0, {')', '('});
    } else {
      res.push_back(rev);
    }
  }

public:
  vector<string> removeInvalidParentheses(string s) {
    vector<string> res;
    dfs(s, res, 0, 0, {'(', ')'});
    return res;
  }
};
