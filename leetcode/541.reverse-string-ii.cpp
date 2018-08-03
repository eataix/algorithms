#include <algorithm>
#include <string>
using namespace std;
/*
 * [541] Reverse String II
 *
 * https://leetcode.com/problems/reverse-string-ii/description/
 *
 * algorithms
 * Easy (44.11%)
 * Total Accepted:    43.7K
 * Total Submissions: 99.1K
 * Testcase Example:  '"abcdefg"\n2'
 *
 *
 * Given a string and an integer k, you need to reverse the first k characters
 * for every 2k characters counting from the start of the string. If there are
 * less than k characters left, reverse all of them. If there are less than 2k
 * but greater than or equal to k characters, then reverse the first k
 * characters and left the other as original.
 *
 *
 * Example:
 *
 * Input: s = "abcdefg", k = 2
 * Output: "bacdfeg"
 *
 *
 *
 * Restrictions:
 *
 * ⁠The string consists of lower English letters only.
 * ⁠Length of the given string and k will in the range [1, 10000]
 *
 */
class Solution {
public:
  string reverseStr(string s, int k) {
    for (int start = 0; start < s.size(); start += 2 * k) {
      for (int i = start, j = min(start + k - 1, (int)s.size() - 1); i < j;
           ++i, --j) {
        swap(s[i], s[j]);
      }
    }
    return s;
  }
};
