#include <algorithm>
#include <string>
using namespace std;
/*
 * [557] Reverse Words in a String III
 *
 * https://leetcode.com/problems/reverse-words-in-a-string-iii/description/
 *
 * algorithms
 * Easy (61.08%)
 * Total Accepted:    84.5K
 * Total Submissions: 137.9K
 * Testcase Example:  '"Let\'s take LeetCode contest"'
 *
 * Given a string, you need to reverse the order of characters in each word
 * within a sentence while still preserving whitespace and initial word order.
 *
 * Example 1:
 *
 * Input: "Let's take LeetCode contest"
 * Output: "s'teL ekat edoCteeL tsetnoc"
 *
 *
 *
 * Note:
 * In the string, each word is separated by single space and there will not be
 * any extra space in the string.
 *
 */
class Solution {
public:
  string reverseWords(string s) {

    for (int l = 0, r = 0; l < s.size(); l = r + 1) {
      r = l;
      while (r < s.size() && !isblank(s[r])) {
        r += 1;
      }

      reverse(s.begin() + l, s.begin() + r);
    }
    return s;
  }
};
