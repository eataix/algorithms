#include <algorithm>
#include <string>
using namespace std;
/*
 * [151] Reverse Words in a String
 *
 * https://leetcode.com/problems/reverse-words-in-a-string/description/
 *
 * algorithms
 * Medium (15.62%)
 * Total Accepted:    195.5K
 * Total Submissions: 1.3M
 * Testcase Example:  '""'
 *
 *
 * Given an input string, reverse the string word by word.
 *
 *
 *
 * For example,
 * Given s = "the sky is blue",
 * return "blue is sky the".
 *
 *
 *
 * Update (2015-02-12):
 * For C programmers: Try to solve it in-place in O(1) space.
 *
 *
 * click to show clarification.
 *
 * Clarification:
 *
 *
 *
 * What constitutes a word?
 * A sequence of non-space characters constitutes a word.
 * Could the input string contain leading or trailing spaces?
 * Yes. However, your reversed string should not contain leading or trailing
 * spaces.
 * How about multiple spaces between two words?
 * Reduce them to a single space in the reversed string.
 *
 *
 *
 */
class Solution {
public:
  void reverseWords(string &s) {
    int endIdx = 0;
    reverse(s.begin(), s.end());

    for (int i = 0; i < s.size(); ++i) {
      if (s[i] != ' ') {
        if (endIdx > 0) {
          s[endIdx] = ' ';
          endIdx += 1;
        }
        int j = i;
        while (j < s.size() && s[j] != ' ') {
          s[endIdx] = s[j];
          endIdx += 1;
          j += 1;
        }
        reverse(s.begin() + endIdx - (j - i), s.begin() + endIdx);
        i = j;
      }
    }
    s.resize(endIdx);
  }

  void reverseWords1(string &s) {
    istringstream in{s};

    string str;
    stack<string> st;
    while (in >> str) {
      st.push(str);
    }

    string res;
    while (!st.empty()) {
      res += st.top();
      st.pop();
      if (!st.empty()) {
        res += ' ';
      }
    }
    s = res;
  }
};
