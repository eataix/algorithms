#include <climits>
#include <cstddef>
#include <iostream>
#include <string>
using namespace std;
/*
 * [8] String to Integer (atoi)
 *
 * https://leetcode.com/problems/string-to-integer-atoi/description/
 *
 * algorithms
 * Medium (14.10%)
 * Total Accepted:    226.8K
 * Total Submissions: 1.6M
 * Testcase Example:  '"42"'
 *
 * Implement atoi which converts a string to an integer.
 *
 * The function first discards as many whitespace characters as necessary until
 * the first non-whitespace character is found. Then, starting from this
 * character, takes an optional initial plus or minus sign followed by as many
 * numerical digits as possible, and interprets them as a numerical value.
 *
 * The string can contain additional characters after those that form the
 * integral number, which are ignored and have no effect on the behavior of
 * this function.
 *
 * If the first sequence of non-whitespace characters in str is not a valid
 * integral number, or if no such sequence exists because either str is empty
 * or it contains only whitespace characters, no conversion is performed.
 *
 * If no valid conversion could be performed, a zero value is returned.
 *
 * Note:
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−231,  231 − 1]. If the numerical
 * value is out of the range of representable values, INT_MAX (231 − 1) or
 * INT_MIN (−231) is returned.
 *
 * Example 1:
 *
 *
 * Input: "42"
 * Output: 42
 *
 *
 * Example 2:
 *
 *
 * Input: "   -42"
 * Output: -42
 * Explanation: The first non-whitespace character is '-', which is the minus
 * sign.
 * Then take as many numerical digits as possible, which gets 42.
 *
 *
 * Example 3:
 *
 *
 * Input: "4193 with words"
 * Output: 4193
 * Explanation: Conversion stops at digit '3' as the next character is not a
 * numerical digit.
 *
 *
 * Example 4:
 *
 *
 * Input: "words and 987"
 * Output: 0
 * Explanation: The first non-whitespace character is 'w', which is not a
 * numerical
 * digit or a +/- sign. Therefore no valid conversion could be performed.
 *
 * Example 5:
 *
 *
 * Input: "-91283472332"
 * Output: -2147483648
 * Explanation: The number "-91283472332" is out of the range of a 32-bit
 * signed integer.
 * Thefore INT_MIN (−231) is returned.
 *
 */
class Solution {
public:
  int myAtoi(string str) {
    if (str.empty()) {
      return 0;
    }

    int i = 0;
    while (i < str.size() && str[i] == ' ') {
      i += 1;
    }

    bool isNeg = false;
    if (i < str.size() && (str[i] < '0' || str[i] > '9')) {
      if (str[i] == '+') {
        isNeg = false;
        i += 1;
      } else if (str[i] == '-') {
        isNeg = true;
        i += 1;
      }
    }

    int res = 0;
    int prev = res;
    while (i < str.size() && str[i] >= '0' && str[i] <= '9') {
      res *= 10;
      if (isNeg) {
        res -= str[i] - '0';
      } else {
        res += str[i] - '0';
      }

      if (res / 10 != prev) {
        return isNeg ? INT_MIN : INT_MAX;
      }
      prev = res;
      i += 1;
    }

    return res;
  }
};

#ifdef DEBUG
int main() {
  Solution sol;
  cout << sol.myAtoi(string{"42"}) << endl;
  cout << sol.myAtoi(string{"    -42"}) << endl;
  cout << sol.myAtoi(string{"4193 with words"}) << endl;
  cout << sol.myAtoi(string{"words and 987"}) << endl;
  cout << sol.myAtoi(string{"-91283472332"}) << endl;
}
#endif
