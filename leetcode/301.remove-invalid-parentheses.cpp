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
  void dfs(const string &s, vector<int> &res, int last_i, int last_j,
           const vector<char> &p) {}

public:
  vector<string> removeInvalidParentheses(string s) {
    vector<string> res;
    dfs(s, res, 0, 0, {'(', ')'});
    return res;
  }
};
