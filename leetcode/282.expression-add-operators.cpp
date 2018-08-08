#include <string>
#include <vector>
using namespace std;
/*
 * [282] Expression Add Operators
 *
 * https://leetcode.com/problems/expression-add-operators/description/
 *
 * algorithms
 * Hard (30.78%)
 * Total Accepted:    50.3K
 * Total Submissions: 163.5K
 * Testcase Example:  '"123"\n6'
 *
 * Given a string that contains only digits 0-9 and a target value, return all
 * possibilities to add binary operators (not unary) +, -, or * between the
 * digits so they evaluate to the target value.
 *
 * Example 1:
 *
 *
 * Input: num = "123", target = 6
 * Output: ["1+2+3", "1*2*3"]
 *
 *
 * Example 2:
 *
 *
 * Input: num = "232", target = 8
 * Output: ["2*3+2", "2+3*2"]
 *
 * Example 3:
 *
 *
 * Input: num = "105", target = 5
 * Output: ["1*0+5","10-5"]
 *
 * Example 4:
 *
 *
 * Input: num = "00", target = 0
 * Output: ["0+0", "0-0", "0*0"]
 *
 *
 * Example 5:
 *
 *
 * Input: num = "3456237490", target = 9191
 * Output: []
 *
 *
 */
class Solution {
  void helper(const string &num, int target, long long diff, long long currNum,
              const string &out, vector<string> &res) {
    if (num.empty()) {
      if (currNum == target) {
        res.push_back(out);
      }
      return;
    }

    for (int len = 1; len <= num.size(); len++) {
      string curr = num.substr(0, len);
      if (curr.size() > 1 && curr[0] == '0') {
        return;
      }
      string next = num.substr(len);

      if (!out.empty()) {
        helper(next, target, stoll(curr), currNum + stoll(curr),
               out + "+" + curr, res);
        helper(next, target, -stoll(curr), currNum - stoll(curr),
               out + "-" + curr, res);
        helper(next, target, diff * stoll(curr),
               (currNum - diff) + diff * stoll(curr), out + "*" + curr, res);
      } else {
        helper(next, target, stoll(curr), stoll(curr), curr, res);
      }
    }
  }

public:
  vector<string> addOperators(string num, int target) {
    vector<string> res;
    if (num.empty()) {
      return res;
    }

    helper(num, target, 0, 0, "", res);

    return res;
  }
};
