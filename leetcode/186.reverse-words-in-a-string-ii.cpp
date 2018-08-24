#include <algorithm>
#include <string>
#include <vector>
using namespace std;
/*
 * [186] Reverse Words in a String II
 *
 * https://leetcode.com/problems/reverse-words-in-a-string-ii/description/
 *
 * algorithms
 * Medium (32.72%)
 * Total Accepted:    48.2K
 * Total Submissions: 147.4K
 * Testcase Example:  '["t","h","e"," ","s","k","y"," ","i","s","
 * ","b","l","u","e"]'
 *
 * Given an input string , reverse the string word by word. 
 *
 * Example:
 *
 *
 * Input:  ["t","h","e"," ","s","k","y"," ","i","s"," ","b","l","u","e"]
 * Output: ["b","l","u","e"," ","i","s"," ","s","k","y"," ","t","h","e"]
 *
 * Note: 
 *
 *
 * A word is defined as a sequence of non-space characters.
 * The input string does not contain leading or trailing spaces.
 * The words are always separated by a single space.
 *
 *
 * Follow up: Could you do it in-place without allocating extra space?
 *
 */

class Solution {
public:
  void reverseWords(vector<char> &str) {
    reverse(str.begin(), str.end());

    for (int l = 0, r = 0; l < str.size(); l = r + 1) {
      r = l;
      while (r < str.size() && !isblank(str[r])) {
        r += 1;
      }

      reverse(str.begin() + l, str.begin() + r);
    }
  }
};
