#include <string>
using namespace std;
/*
 * [13] Roman to Integer
 *
 * https://leetcode.com/problems/roman-to-integer/description/
 *
 * algorithms
 * Easy (48.07%)
 * Total Accepted:    224.5K
 * Total Submissions: 467K
 * Testcase Example:  '"DCXXI"'
 *
 * Given a roman numeral, convert it to an integer.
 *
 * Input is guaranteed to be within the range from 1 to 3999.
 */
class Solution {
private:
  int value(char ch) {
    switch (ch) {
    case 'I':
      return 1;
    case 'V':
      return 5;
    case 'X':
      return 10;
    case 'L':
      return 50;
    case 'C':
      return 100;
    case 'D':
      return 500;
    case 'M':
      return 1000;
    default:
      return -1;
    }
  }

public:
  int romanToInt(string s) {
    int res = 0;
    for (int i = 0; i < s.size(); ++i) {
      int c1 = value(s[i]);
      if (i + 1 < s.size()) {
        int c2 = value(s[i + 1]);
        if (c1 >= c2) {
          res += c1;
        } else {
          res += c2 - c1;
          i += 1;
        }
      } else {
        res += c1;
      }
    }
    return res;
  }
};
