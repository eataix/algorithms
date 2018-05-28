#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
/*
 * [241] Different Ways to Add Parentheses
 *
 * https://leetcode.com/problems/different-ways-to-add-parentheses/description/
 *
 * algorithms
 * Medium (46.37%)
 * Total Accepted:    56.5K
 * Total Submissions: 121.8K
 * Testcase Example:  '"2-1-1"'
 *
 * Given a string of numbers and operators, return all possible results from
 * computing all the different possible ways to group numbers and operators.
 * The valid operators are +, - and *.
 *
 * Example 1:
 *
 *
 * Input: "2-1-1"
 * Output: [0, 2]
 * Explanation:
 * ((2-1)-1) = 0
 * (2-(1-1)) = 2
 *
 * Example 2:
 *
 *
 * Input: "2*3-4*5"
 * Output: [-34, -14, -10, -10, 10]
 * Explanation:
 * (2*(3-(4*5))) = -34
 * ((2*3)-(4*5)) = -14
 * ((2*(3-4))*5) = -10
 * (2*((3-4)*5)) = -10
 * (((2*3)-4)*5) = 10
 *
 *
 */
class Solution {
public:
  vector<int> diffWaysToCompute(const string &input) {
    unordered_map<string, vector<int>> m;
    return diffWaysToComputeRecursive(input, m);
  }

  vector<int>
  diffWaysToComputeRecursive(const string &input,
                             unordered_map<string, vector<int>> &m) {
    if (m.find(input) != cend(m)) {
      return m[input];
    }
    vector<int> res;

    for (int i = 0; i < input.size(); ++i) {
      char ch = input[i];
      if (ch == '-' || ch == '+' || ch == '*') {
        vector<int> left = diffWaysToComputeRecursive(input.substr(0, i), m);
        vector<int> right = diffWaysToComputeRecursive(input.substr(i + 1), m);
        for (int l : left) {
          for (int r : right) {
            if (ch == '+') {
              res.push_back(l + r);
            } else if (ch == '-') {
              res.push_back(l - r);
            } else if (ch == '*') {
              res.push_back(l * r);
            }
          }
        }
      }
    }
    if (res.empty()) {
      res.push_back(stoi(input));
    }

    m[input] = res;
    return res;
  }
};
