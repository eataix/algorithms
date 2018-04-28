#include <iostream>
#include <string>
using namespace std;
/*
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (25.31%)
 * Total Accepted:    309K
 * Total Submissions: 1.2M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 *
 * Example 1:
 *
 *
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 *
 *
 * Example 2:
 *
 *
 * Input: "cbbd"
 * Output: "bb"
 *
 *
 */
class Solution {
public:
  string addBoundaries(const string &s) {
    string newStr(s.size() * 2 + 1, '$');

    for (int i = 0; i < s.size(); ++i) {
      newStr[i * 2 + 1] = s[i];
    }
    return newStr;
  }

  string removeBoundaries(const string &s) {
    string newStr((s.size() - 1) / 2, ' ');

    for (int i = 0; i < newStr.size(); ++i) {
      newStr[i] = s[i * 2 + 1];
    }
    return newStr;
  }

  string longestPalindrome(string s) {
    if (s.empty()) {
      return string{""};
    }

    string newStr = addBoundaries(s);
    vector<int> res(newStr.size());

    int center = 0,
  }
};
