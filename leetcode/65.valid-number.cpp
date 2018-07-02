#include <string>
using namespace std;
/*
 * [65] Valid Number
 *
 * https://leetcode.com/problems/valid-number/description/
 *
 * algorithms
 * Hard (12.97%)
 * Total Accepted:    89.4K
 * Total Submissions: 689.8K
 * Testcase Example:  '"0"'
 *
 * Validate if a given string is numeric.
 *
 * Some examples:
 * "0" => true
 * " 0.1 " => true
 * "abc" => false
 * "1 a" => false
 * "2e10" => true
 *
 * Note: It is intended for the problem statement to be ambiguous. You should
 * gather all requirements up front before implementing one.
 *
 * Update (2015-02-10):
 * The signature of the C++ function had been updated. If you still see your
 * function signature accepts a const char * argument, please click the reload
 * button to reset your code definition.
 *
 */
class Solution {
public:
  bool isNumber(string s) {
    while (s.size() && s[0] == ' ') {
      s.erase(s.begin());
    }

    while (s.size() && s.back() == ' ') {
      s.erase(s.end() - 1);
    }

    if (s.empty()) {
      return false;
    }

    int state = 0;
    for (char ch : s) {
      if (ch == '-' || ch == '+') {
        if (state == 0 || state == 3) {
          state++;
        } else {
          return false;
        }
      } else if (ch == '.') {
        if (state == 2) {
          state = 7;
        } else if (state == 0 || state == 1) {
          state = 6;
        } else {
          return false;
        }

      } else if (ch >= '0' && ch <= '9') {
        if (state == 1 || state == 4 || state == 6) {
          state++;
        } else if (state == 0 || state == 3) {
          state = state + 2;
        }
      } else if (ch == 'e' || ch == 'E') {
        if (state == 2 || state == 7) {
          state = 3;
        } else {
          return false;
        }
      } else {
        return false;
      }
    }

    if (state == 2 || state == 7 || state == 5) {
      return true;
    }
    return false;
  }
};
