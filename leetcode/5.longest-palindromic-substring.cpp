#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (25.30%)
 * Total Accepted:    308.5K
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
  string longestPalindrome(string s) {
	  int minStart =-1;
	  int maxLen = 0;
	  for (int i = 0; i < s.size(); ++i) {
		  int len1 = expandAroundCenters(s, i, i);
		  int len2 = expandAroundCenters(s, i, i + 1);
		  int len = max(len1, len2);
		  if (len > maxLen) {
			  minStart = i - (len - 1) / 2;
			  maxLen = len;
		  }
	  }
	  return minStart == -1? "" : s.substr(minStart, maxLen);
  }
  int expandAroundCenters(const string &s, int left, int right) {
	  int l = left;
	   int r = right;

	   while (l >= 0 && r < s.size() && s[l] == s[r]) {
		   l += 1;
		   r += 1;
	   }
	   return r - l - 1;
  }

  string removePaddings(string s) {
    if (s.empty()) {
      return "";
    }

    string s2((s.size() - 1) / 2, ' ');
    for (int i = 0; i < s2.size(); ++i) {
      s2[i] = s[i * 2 + 1];
    }
    return s2;
  }

  string addPaddings(string s) {
    if (s.empty()) {
      return "||";
    }
    string s2(s.size() * 2 + 1, ' ');
    for (int i = 0; i < s.size() * 2 + 1; i += 2) {
      s2[i] = '|';
      s2[i + 1] = s[i / 2];
    }
    s2[s2.size() - 1] = '|';
    return s2;
  }

  string longestPalindrome2(string s) {
    if (s.size() == 0) {
      return "";
    }

    string s2 = addPaddings(s);
    vector<int> p(s2.size());

    int c = 0, r = 0;
    int m = 0, n = 0;

    for (int i = 1; i < s2.size(); ++i) {
      if (i > r) {
        p[i] = 0;
        m = i - 1;
        n = i + 1;
      } else {
        int i2 = c * 2 - i;
        if (p[i2] < r - i - 1) {
          p[i] = p[i2];
          m = -1;
        } else {
          p[i] = r - i;
          n = r + 1;
          m = i * 2 - n;
        }
      }
      while (m >= 0 && n < s2.size() && s2[m] == s2[n]) {
        p[i] += 1;
        m--;
        n++;
      }
      if (i + p[i] > r) {
        c = i;
        r = i + p[i];
      }
    }
    int len = 0;
    c = 0;
    for (int i = 1; i < s2.size(); ++i) {
      if (len < p[i]) {
        len = p[i];
        c = i;
      }
    }

    return removePaddings(
        string(s2.cbegin() + c - len, s2.cbegin() + c + len + 1));
  }
};

#ifdef DEBUG
int main() {
  Solution sol;
  cout << sol.longestPalindrome("ABBC") << endl;
}
#endif
