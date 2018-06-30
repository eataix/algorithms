/*
 * [227] Basic Calculator II
 *
 * https://leetcode.com/problems/basic-calculator-ii/description/
 *
 * algorithms
 * Medium (30.50%)
 * Total Accepted:    69.2K
 * Total Submissions: 226.7K
 * Testcase Example:  '"3+2*2"'
 *
 * Implement a basic calculator to evaluate a simple expression string.
 *
 * The expression string contains only non-negative integers, +, -, *, /
 * operators and empty spaces  . The integer division should truncate toward
 * zero.
 *
 * Example 1:
 *
 *
 * Input: "3+2*2"
 * Output: 7
 *
 *
 * Example 2:
 *
 *
 * Input: " 3/2 "
 * Output: 1
 *
 * Example 3:
 *
 *
 * Input: " 3+5 / 2 "
 * Output: 5
 *
 *
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
    istringstream in('+' + s + '+');
    long long total = 0, term = 0;
    char op;
    while (in >> op) {
      if (op == '+' || op == '-') {
        total += term;
        in >> term;
        term *= op == '+' ? 1 : -1;
      } else {
        int n;
        in >> n;
        if (op == '*')
          term *= n;
        else
          term /= n;
      }
    }
    return total;
  }
};
