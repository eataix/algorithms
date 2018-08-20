#include <string>
#include <unordered_map>
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

unordered_map<char, int> m{{'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
                           {'C', 100}, {'D', 500}, {'M', 1000}};

class Solution {
public:
  int romanToInt(string s) {
    int res = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (i + 1 < s.size() && m[s[i]] < m[s[i + 1]]) {
        res += m[s[i + 1]] - m[s[i]];
        i += 1;
      } else {
        res += m[s[i]];
      }
    }
    return res;
  }
};
