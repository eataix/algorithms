#include <deque>
#include <string>
using namespace std;
/*
 * [785] Basic Calculator III
 *
 * https://leetcode.com/problems/basic-calculator-iii/description/
 *
 * algorithms
 * Hard (40.37%)
 * Total Accepted:    4K
 * Total Submissions: 9.9K
 * Testcase Example:  '"1 + 1"'
 *
 * Implement a basic calculator to evaluate a simple expression string.
 *
 * The expression string may contain open ( and closing parentheses ), the plus
 * + or minus sign -, non-negative integers and empty spaces  .
 *
 * The expression string contains only non-negative integers, +, -, *, /
 * operators , open ( and closing parentheses ) and empty spaces  . The integer
 * division should truncate toward zero.
 *
 * You may assume that the given expression is always valid. All intermediate
 * results will be in the range of [-2147483648, 2147483647].
 *
 * Some examples:
 *
 *
 * "1 + 1" = 2
 * " 6-4 / 2 " = 4
 * "2*(5+5*2)/3+(6/2+8)" = 21
 * "(2+6* 3+5- (3*14/7+2)*5)+3"=-12
 *
 *
 *
 *
 * Note: Do not use the eval built-in library function.
 *
 */

class Solution {
public:
  int calculate(string s) {
    int l1 = 0, o1 = 1;
    int l2 = 1, o2 = 1;
    int n = s.size();
    deque<int> dq_s;

    for (int i = 0; i < n; ++i) {
      char c = s[i];
      if (isdigit(c)) {
        int num = c - '0';

        while (i + 1 < n && isdigit(s[i + 1]))
          num = num * 10 + (s[++i] - '0');

        l2 = (o2 == 1 ? l2 * num : l2 / num);

      } else if (c == '(') {
        dq_s.push_front(l1);
        dq_s.push_front(o1);
        dq_s.push_front(l2);
        dq_s.push_front(o2);

        l1 = 0;
        o1 = 1;
        l2 = 1;
        o2 = 1;
      } else if (c == ')') {
        int num = l1 + o1 * l2;

        o2 = dq_s.front();
        dq_s.pop_front();
        l2 = dq_s.front();
        dq_s.pop_front();
        o1 = dq_s.front();
        dq_s.pop_front();
        l1 = dq_s.front();
        dq_s.pop_front();

        l2 = (o2 == 1 ? l2 * num : l2 / num);

      } else if (c == '*' || c == '/') {
        o2 = (c == '*' ? 1 : -1);
      } else if (c == '+' || c == '-') {
        l1 = l1 + o1 * l2;
        o1 = (c == '+' ? 1 : -1);

        l2 = 1;
        o2 = 1;
      }
    }
    return (l1 + o1 * l2);
  }
};
