#include <stack>
#include <string>
using namespace std;
/*
 * [394] Decode String
 *
 * https://leetcode.com/problems/decode-string/description/
 *
 * algorithms
 * Medium (42.08%)
 * Total Accepted:    52.7K
 * Total Submissions: 125.3K
 * Testcase Example:  '"3[a]2[bc]"'
 *
 *
 * Given an encoded string, return it's decoded string.
 *
 *
 * The encoding rule is: k[encoded_string], where the encoded_string inside the
 * square brackets is being repeated exactly k times. Note that k is guaranteed
 * to be a positive integer.
 *
 *
 * You may assume that the input string is always valid; No extra white spaces,
 * square brackets are well-formed, etc.
 *
 * Furthermore, you may assume that the original data does not contain any
 * digits and that digits are only for those repeat numbers, k. For example,
 * there won't be input like 3a or 2[4].
 *
 *
 * Examples:
 *
 * s = "3[a]2[bc]", return "aaabcbc".
 * s = "3[a2[c]]", return "accaccacc".
 * s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
 *
 *
 */

class Solution {
public:
  string decodeString(string s) {
    stack<int> numS;
    stack<string> strS;

    int num = 0;
    string str;
    for (char ch : s) {
      if (isdigit(ch)) {
        num *= 10;
        num += ch - '0';
      } else if (ch == '[') {
        numS.push(num);
        num = 0;
        strS.push(str);
        str.clear();
      } else if (ch == ']') {
        int k = numS.top();
        numS.pop();
        string s;
        for (int j = 0; j < k; ++j) {
          s += str;
        }
        str = strS.top() + s;
        strS.pop();
      } else {
        str += ch;
      }
    }

    return str;
  }
};
