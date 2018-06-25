#include <cctype>
#include <stack>
#include <string>
using namespace std;
/*
 * [224] Basic Calculator
 *
 * https://leetcode.com/problems/basic-calculator/description/
 *
 * algorithms
 * Hard (29.10%)
 * Total Accepted:    69.4K
 * Total Submissions: 238.4K
 * Testcase Example:  '"1 + 1"'
 *
 * Implement a basic calculator to evaluate a simple expression string.
 *
 * The expression string may contain open ( and closing parentheses ), the plus
 * + or minus sign -, non-negative integers and empty spaces  .
 *
 * Example 1:
 *
 *
 * Input: "1 + 1"
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: " 2-1 + 2 "
 * Output: 3
 *
 * Example 3:
 *
 *
 * Input: "(1+(4+5+2)-3)+(6+8)"
 * Output: 23
 * Note:
 *
 *
 * You may assume that the given expression is always valid.
 * Do not use the eval built-in library function.
 *
 *
 */
class Solution {
public:
  int calculate(string s) {
    auto len{s.size()};
    int sign{1};
    int res{0};
    stack<int> st;

    for (int i = 0; i < len; ++i) {
      if (isdigit(s[i])) {
        int num = 0;
        while (i + 1 < len && isdigit(s[i + 1])) {
          num = 10 * num + s[i++] - '0';
        }
        res += num * sign;
      } else if (s[i] == '+') {
        sign = 1;
      } else if (s[i] == '-') {
        sign = -1;
      } else if (s[i] == '(') {
        st.push(res);
        st.push(sign);
        res = 0;
        sign = 1;
      } else if (s[i] == ')') {
        res *= st.top();
        st.pop();
        res += st.top();
        st.pop();
      }
    }
    return res;
  }
};
