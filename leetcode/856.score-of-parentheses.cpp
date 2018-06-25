#include <iostream>
#include <string>
using namespace std;
/*
 * [886] Score of Parentheses
 *
 * https://leetcode.com/problems/score-of-parentheses/description/
 *
 * algorithms
 * Medium (53.11%)
 * Total Accepted:    1.7K
 * Total Submissions: 3.2K
 * Testcase Example:  '"()"'
 *
 * Given a balanced parentheses string S, compute the score of the string based
 * on the following rule:
 *
 *
 * () has score 1
 * AB has score A + B, where A and B are balanced parentheses strings.
 * (A) has score 2 * A, where A is a balanced parentheses string.
 *
 *
 *
 *
 *
 * Example 1:
 *
 *
 * Input: "()"
 * Output: 1
 *
 *
 *
 * Example 2:
 *
 *
 * Input: "(())"
 * Output: 2
 *
 *
 *
 * Example 3:
 *
 *
 * Input: "()()"
 * Output: 2
 *
 *
 *
 * Example 4:
 *
 *
 * Input: "(()(()))"
 * Output: 6
 *
 *
 *
 *
 * Note:
 *
 *
 * S is a balanced parentheses string, containing only ( and ).
 * 2 <= S.length <= 50
 *
 *
 *
 *
 *
 *
 */
class Solution {
public:
  int scoreOfParentheses(string S) {
    int res{0};

    int nestedDepth{0};
    for (int i = 0; i < S.size(); ++i) {
      if (S[i] == '(') {
        nestedDepth += 1;
      } else {
        nestedDepth -= 1;
      }

      if (S[i] == '(' && S[i + 1] == ')') {
        res += 1 << (nestedDepth - 1);
      }
    }
    return res;
  }
};

#ifdef DEBUG
int main() {
  Solution sol;

  cout << sol.scoreOfParentheses("()") << endl;
  cout << sol.scoreOfParentheses("(())") << endl;
  cout << sol.scoreOfParentheses("()()") << endl;
  cout << sol.scoreOfParentheses("(()(()))") << endl;
}
#endif
