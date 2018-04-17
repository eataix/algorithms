#include <iostream>
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
    stack<char> seen;
    for (char ch : s) {
      switch (ch) {
      case '(':
        seen.push(ch);
        break;
      case ')':
        if (seen.empty() || seen.top() != '(') {

          return false;
        } else {
          seen.pop();
        }
        break;
      case '{':
        seen.push(ch);
        break;
      case '}':
        if (seen.empty() || seen.top() != '{') {

          return false;
        } else {
          seen.pop();
        }
        break;
      case '[':
        seen.push(ch);
        break;
      case ']':
        if (seen.empty() || seen.top() != '[') {

          return false;
        } else {
          seen.pop();
        }
        break;
      }
    }
    return seen.empty();
  }
};

#ifdef DEBUG
int main() {
  Solution sol;
  cout << sol.isValid("()") << endl;
}
#endif