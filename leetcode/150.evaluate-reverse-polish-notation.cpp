#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
/*
 * [150] Evaluate Reverse Polish Notation
 *
 * https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
 *
 * algorithms
 * Medium (28.52%)
 * Total Accepted:    114.9K
 * Total Submissions: 403K
 * Testcase Example:  '["2","1","+","3","*"]'
 *
 * Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 *
 * Valid operators are +, -, *, /. Each operand may be an integer or another
 * expression.
 *
 * Note:
 *
 *
 * Division between two integers should truncate toward zero.
 * The given RPN expression is always valid. That means the expression would
 * always evaluate to a result and there won't be any divide by zero
 * operation.
 *
 *
 * Example 1:
 *
 *
 * Input: ["2", "1", "+", "3", "*"]
 * Output: 9
 * Explanation: ((2 + 1) * 3) = 9
 *
 *
 * Example 2:
 *
 *
 * Input: ["4", "13", "5", "/", "+"]
 * Output: 6
 * Explanation: (4 + (13 / 5)) = 6
 *
 *
 * Example 3:
 *
 *
 * Input: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
 * Output: 22
 * Explanation:
 * ⁠ ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
 * = ((10 * (6 / (12 * -11))) + 17) + 5
 * = ((10 * (6 / -132)) + 17) + 5
 * = ((10 * 0) + 17) + 5
 * = (0 + 17) + 5
 * = 17 + 5
 * = 22
 *
 *
 */
class Solution {
public:
  int evalRPN(vector<string> &tokens) {
    stack<int> values;

    for (auto &token : tokens) {
      if (token == "+") {
        int v1 = values.top();
        values.pop();
        int v2 = values.top();
        values.pop();
        values.push(v2 + v1);
      } else if (token == "-") {
        int v1 = values.top();
        values.pop();
        int v2 = values.top();
        values.pop();
        values.push(v2 - v1);
      } else if (token == "*") {
        int v1 = values.top();
        values.pop();
        int v2 = values.top();
        values.pop();
        values.push(v2 * v1);
      } else if (token == "/") {
        int v1 = values.top();
        values.pop();
        int v2 = values.top();
        values.pop();
        values.push(v2 / v1);
      } else {
        int val = stoi(token);
#ifdef DEBUG
        cout << "val: " << val << endl;
#endif
        values.push(val);
      }
    }

    return values.top();
  }
};

#ifdef DEBUG
int main() {
  Solution sol;
  vector<string> v1{"2", "1", "+", "3", "*"};
  vector<string> v2{"4", "13", "5", "/", "+"};
  vector<string> v3{"10", "6", "9",  "3", "+", "-11", "*",
                    "/",  "*", "17", "+", "5", "+"};
  cout << sol.evalRPN(v1) << endl;
  cout << sol.evalRPN(v2) << endl;
  cout << sol.evalRPN(v3) << endl;
}
#endif
