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
    int i = S.size() - 1;
    int j = T.size() - 1;
    int skipS = 0;
    int skipT = 0;
    while (i >= 0 || j >= 0) {
      while (i >= 0) {
        if (S[i] == '#') {
          skipS += 1;
          i -= 1;
        } else if (skipS > 0) {
          skipS -= 1;
          i -= 1;
        } else {
          break;
        }
      }

      while (j >= 0) {
        if (T[j] == '#') {
          skipT += 1;
          j -= 1;
        } else if (skipT > 0) {
          skipT -= 1;
          j -= 1;
        } else {
          break;
        }
      }

      if (i >= 0 && j >= 0 && S[i] != T[j]) {
        return false;
      }

      if ((i >= 0) != (j >= 0)) {
        return false;
      }

      i -= 1;
      j -= 1;
    }
    return true;
  }
};

#ifdef DEBUG
int main() {
  Solution sol;
  // cout << sol.backspaceCompare("ab#c", "ad#c") << endl;
  // cout << sol.backspaceCompare("ab##", "c#d#") << endl;
  // cout << sol.backspaceCompare("a##c", "#a#c") << endl;
  // cout << sol.backspaceCompare("a#c", "b") << endl;
  // cout << sol.backspaceCompare("xywrrmp", "xywrrmu#p") << endl;
  // cout << sol.backspaceCompare("bxj##tw", "bxj###tw") << endl;
  cout << sol.backspaceCompare("nzp#o#g", "b#nzp#o#g") << endl;
  cout << endl;
  cout << sol.backspaceCompare("bbbextm", "bbb#extm") << endl;
}
#endif
