class Solution {
public:
  /**
   * @param s: the given string
   * @return: if the starting player can guarantee a win
   */
  bool canWin(const string &s) {
    for (int i = 1; i < s.size(); ++i) {
      if (s[i] == '+' && s[i - 1] == '+' &&
          !canWin(s.substr(0, i - 1) + "--" + s.substr(i + 1))) {
        return true;
      }
    }
    return false;
  }
};
