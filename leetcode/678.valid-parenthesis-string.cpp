/*
 * [678] Valid Parenthesis String
 *
 * https://leetcode.com/problems/valid-parenthesis-string/description/
 *
 * algorithms
 * Medium (30.13%)
 * Total Accepted:    16.3K
 * Total Submissions: 54.1K
 * Testcase Example:  '"()"'
 *
 *
 * Given a string containing only three types of characters: '(', ')' and '*',
 * write a function to check whether this string is valid. We define the
 * validity of a string by these rules:
 *
 * Any left parenthesis '(' must have a corresponding right parenthesis ')'.
 * Any right parenthesis ')' must have a corresponding left parenthesis '('.
 * Left parenthesis '(' must go before the corresponding right parenthesis ')'.
 * '*' could be treated as a single right parenthesis ')' or a single left
 * parenthesis '(' or an empty string.
 * An empty string is also valid.
 *
 *
 *
 * Example 1:
 *
 * Input: "()"
 * Output: True
 *
 *
 *
 * Example 2:
 *
 * Input: "(*)"
 * Output: True
 *
 *
 *
 * Example 3:
 *
 * Input: "(*))"
 * Output: True
 *
 *
 *
 * Note:
 *
 * The string size will be in the range [1, 100].
 *
 *
 */
class Solution {
public:
  bool checkValidString(string s) {
    int lower = 0;
    int upper = 0;
    for (char ch : s) {
      switch (ch) {
      case '(':
        lower++;
        upper++;

        break;
      case ')':
        lower--;
        upper--;

        break;
      case '*':
        lower--;
        upper++;

        break;
      }

      lower = max(lower, 0);
      if (upper < 0) {
        return false;
      }
    }
    return lower == 0;
  }
};
