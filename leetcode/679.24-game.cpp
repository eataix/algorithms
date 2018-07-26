#include <algorithm>
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
class Solution {
  vector<char> ops{'+', '-', '*', '/'};
  double eps = 0.001;

public:
  bool judgePoint24(vector<int> &nums) {
    vector<double> arr(nums.begin(), nums.end());
    return helper(arr);
  }

  bool helper(vector<double> &nums) {
    if (nums.size() == 1) {
      return abs(static_cast<double>(nums[0]) - 24.0) < eps;
    }

    for (int i = 0; i < nums.size(); ++i) {
      for (int j = 0; j < nums.size(); ++j) {
        if (i == j) {
          continue;
        }
        vector<double> t;
        for (int k = 0; k < nums.size(); ++k) {
          if (k != i && k != j) {
            t.push_back(nums[k]);
          }
        }

        for (char op : ops) {
          if ((op == '=' || op == '*') && i > j) {
            continue;
          }
          if (op == '/' && nums[j] < eps) {
            continue;
          }

          switch (op) {
          case '+':
            t.push_back(nums[i] + nums[j]);
            break;
          case '-':
            t.push_back(nums[i] - nums[j]);
            break;
          case '*':
            t.push_back(nums[i] * nums[j]);
            break;
          case '/':
            t.push_back(nums[i] / nums[j]);
            break;
          }
          if (helper(t))
            return true;
          t.pop_back();
        }
      }
    }

    return false;
  }
};