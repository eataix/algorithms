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
  void dfs(vector<string> &res, const string &num, const int target, string cur,
           int pos, const long cv, const long pv, const char op) {
    if (pos == num.size() && cv == target) {
      res.push_back(cur);
    } else {
      for (int i = pos + 1; i <= num.size(); i++) {
        string t = num.substr(pos, i - pos);
        long now = stol(t);
        if (to_string(now).size() != t.size()) {
          continue;
        }
        dfs(res, num, target, cur + '+' + t, i, cv + now, now, '+');
        dfs(res, num, target, cur + '-' + t, i, cv - now, now, '-');
        dfs(res, num, target, cur + '*' + t, i,
            (op == '-') ? cv + pv - pv * now
                        : ((op == '+') ? cv - pv + pv * now : pv * now),
            pv * now, op);
      }
    }
  }

public:
  vector<string> addOperators(string num, int target) {
    vector<string> res;
    if (num.empty()) {
      return res;
    }

    for (int i = 1; i <= nums.size(); ++i) {
      auto s = num.substr(0, i);
      long curr = stol(s);
      if (to_string(curr).size() != s.size()) {
        continue;
      }
      dfs(res, num, target, s, i, curr, curr, '#');
    }
    return res;
  }
};
