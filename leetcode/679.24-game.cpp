#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
/*
 * [679] 24 Game
 *
 * https://leetcode.com/problems/24-game/description/
 *
 * algorithms
 * Hard (39.02%)
 * Total Accepted:    9.4K
 * Total Submissions: 24.2K
 * Testcase Example:  '[4,1,8,7]'
 *
 *
 * You have 4 cards each containing a number from 1 to 9.  You need to judge
 * whether they could operated through *, /, +, -, (, ) to get the value of
 * 24.
 *
 *
 * Example 1:
 *
 * Input: [4, 1, 8, 7]
 * Output: True
 * Explanation: (8-4) * (7-1) = 24
 *
 *
 *
 * Example 2:
 *
 * Input: [1, 2, 1, 2]
 * Output: False
 *
 *
 *
 * Note:
 *
 * The division operator / represents real division, not integer division.  For
 * example, 4 / (1 - 2/3) = 12.
 * Every operation done is between two numbers.  In particular, we cannot use -
 * as a unary operator.  For example, with [1, 1, 1, 1] as input, the
 * expression -1 - 1 - 1 - 1 is not allowed.
 * You cannot concatenate numbers together.  For example, if the input is [1,
 * 2, 1, 2], we cannot write this as 12 + 12.
 *
 *
 *
 */

constexpr double epsilon = 1e-6;

static inline bool isZero(double x) { return x < epsilon; }

static inline bool doubleEqual(double x, double y) {
  return isZero(abs(x - y));
}

const string ops = "+-*/";

class Solution {
  bool dfs(const vector<double> &curr) {
    if (curr.size() == 1) {
      return doubleEqual(curr[0], 24.0);
    }

    for (int i = 0; i < curr.size(); ++i) {
      for (int j = 0; j < curr.size(); ++j) {
        if (i == j) {
          continue;
        }
        vector<double> next;
        for (int k = 0; k < curr.size(); ++k) {
          if (k != i && k != j) {
            next.push_back(curr[k]);
          }
        }

        for (char op : ops) {
          if ((op == '+' || op == '*') && i > j) {
            continue;
          }
          if (op == '/' && isZero(curr[j])) {
            continue;
          }

          switch (op) {
          case '+':
            next.push_back(curr[i] + curr[j]);
            break;
          case '-':
            next.push_back(curr[i] - curr[j]);
            break;
          case '*':
            next.push_back(curr[i] * curr[j]);
            break;
          case '/':
            next.push_back(curr[i] / curr[j]);
            break;
          }
          if (dfs(next)) {
            return true;
          }
          next.pop_back();
        }
      }
    }
    return false;
  }

public:
  bool judgePoint24(vector<int> &nums) {
    return dfs(vector<double>{nums.cbegin(), nums.cend()});
  }
};
