class Solution {
public:
  /**
   * @param s: input string
   * @return: the longest palindromic substring
   */
  string longestPalindrome(string &s) {
    int maxLen = 0;
    int start = -1;
    for (int i = 0; i < s.size(); ++i) {
      int lenA = expandAroundCenters(s, i, i);
      int lenB = expandAroundCenters(s, i, i + 1);

      int len = max(lenA, lenB);

      if (len > maxLen) {
        start = i - (len - 1) / 2;
        maxLen = len;
      }
    }

    return start == -1 ? "" : s.substr(start, maxLen);
  }

  int expandAroundCenters(const string &s, int c1, int c2) {
    while (c1 >= 0 && c2 < s.size() && s[c1] == s[c2]) {
      c1 -= 1;
      c2 += 1;
    }

    return c2 - c1 - 1;
  }
};
