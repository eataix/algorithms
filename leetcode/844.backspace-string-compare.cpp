#include <iostream>
#include <string>
using namespace std;
/*
 * [874] Backspace String Compare
 *
 * https://leetcode.com/problems/backspace-string-compare/description/
 *
 * algorithms
 * Easy (47.55%)
 * Total Accepted:    6.4K
 * Total Submissions: 13.5K
 * Testcase Example:  '"ab#c"\n"ad#c"'
 *
 * Given two strings S and T, return if they are equal when both are typed into
 * empty text editors. # means a backspace character.
 *
 *
 * Example 1:
 *
 *
 * Input: S = "ab#c", T = "ad#c"
 * Output: true
 * Explanation: Both S and T become "ac".
 *
 *
 *
 * Example 2:
 *
 *
 * Input: S = "ab##", T = "c#d#"
 * Output: true
 * Explanation: Both S and T become "".
 *
 *
 *
 * Example 3:
 *
 *
 * Input: S = "a##c", T = "#a#c"
 * Output: true
 * Explanation: Both S and T become "c".
 *
 *
 *
 * Example 4:
 *
 *
 * Input: S = "a#c", T = "b"
 * Output: false
 * Explanation: S becomes "c" while T becomes "b".
 *
 *
 * Note:
 *
 *
 * 1 <= S.length <= 200
 * 1 <= T.length <= 200
 * S and T only contain lowercase letters and '#' characters.
 *
 *
 * Follow up:
 *
 *
 * Can you solve it in O(N) time and O(1) space?
 *
 *
 *
 *
 *
 */

class Solution {
public:
  bool backspaceCompare(string S, string T) {
    int c1 = 0;
    int c2 = 0;

    auto it1 = S.crbegin();
    auto it2 = T.crbegin();

    while (it1 != S.crend() || it2 != T.crend()) {
      while (it1 != S.crend() && (*it1 == '#' || c1 > 0)) {
        if (*it1 == '#') {
          c1 += 1;
        } else {
          c1 -= 1;
        }
        it1 += 1;
      }

      while (it2 != T.crend() && (*it2 == '#' || c2 > 0)) {
        if (*it2 == '#') {
          c2 += 1;
        } else {
          c2 -= 1;
        }
        it2 += 1;
      }

      if (it1 == S.crend() || it2 == T.crend()) {
        break;
      }

      if (*it1 != *it2) {
        return false;
      } else {
        it1 += 1;
        it2 += 1;
      }
    }

    return it1 == S.crend() && it2 == T.crend();
  }
};
