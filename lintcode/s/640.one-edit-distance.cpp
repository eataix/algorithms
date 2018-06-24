class Solution {
public:
  /**
   * @param s: a string
   * @param t: a string
   * @return: true if they are both one edit distance apart or false
   */
  bool isOneEditDistance(string &s, string &t) {
    for (int i = 0; i < min(s.size(), t.size()); ++i) {
      if (s[i] != t[i]) {
        return s.substr(i + 1) == t.substr(i + 1) ||
               s.substr(i) == t.substr(i + 1) || s.substr(i + 1) == t.substr(i);
      }
    }
    return abs(static_cast<int>(s.size()) - static_cast<int>(t.size())) == 1;
  }
};
