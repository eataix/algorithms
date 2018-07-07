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
    string res = "";
    string t = "";
    stack<int> s_num;
    stack<string> s_str;

    int cnt = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (isdigit(s[i])) {
        cnt = 10 * cnt + s[i] - '0';
      } else if (s[i] == '[') {
        s_num.push(cnt);
        s_str.push(t);
        cnt = 0;
        t.clear();
      } else if (s[i] == ']') {
        int k = s_num.top();
        s_num.pop();

        for (int j = 0; j < k; ++j) {
          s_str.top() += t;
        }

        t = s_str.top();
        s_str.pop();
      } else {
        t += s[i];
      }
    }

    return s_str.empty() ? t : s_str.top();
  }
};
