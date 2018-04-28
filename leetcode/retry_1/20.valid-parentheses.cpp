#include <stack>
#include <string>
using namespace std;
/*
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (33.99%)
 * Total Accepted:    323.4K
 * Total Submissions: 951.6K
 * Testcase Example:  '"["'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 *
 * The brackets must close in the correct order, "()" and "()[]{}" are all
 * valid but "(]" and "([)]" are not.
 *
 */
class Solution {
public:
  bool isValid(string s) {
    stack<char> st;
    for (const char &ch : s) {
      switch (ch) {
      case '(':
      case '{':
      case '[':
        st.push(ch);
        break;
      case ')':
        if (st.empty() || st.top() != '(') {
          return false;
        } else {
          st.pop();
        }
        break;
      case '}':
        if (st.empty() || st.top() != '{') {
          return false;
        } else {
          st.pop();
        }
        break;
      case ']':
        if (st.empty() || st.top() != '[') {
          return false;
        } else {
          st.pop();
        }
        break;
      }
    }
    return st.empty();
  }
};
