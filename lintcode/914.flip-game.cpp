class Solution {
public:
  /**
   * @param s: the given string
   * @return: all the possible states of the string after one valid move
   */
  vector<string> generatePossibleNextMoves(string &s) {
    if (s.empty()) {
      return {};
    }
    string str{s};
    vector<string> res;
    for (int i = 0; i < str.size() - 1; ++i) {
      if (str[i] == '+' && str[i + 1] == '+') {
        res.push_back(str);
        res.back()[i] = res.back()[i + 1] = '-';
      }
    }
    return res;
  }
};
