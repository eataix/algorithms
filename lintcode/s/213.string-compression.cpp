class Solution {
public:
  /**
   * @param str: a string
   * @return: a compressed string
   */
  string compress(string &str) {
    if (str.size() <= 1) {
      return str;
    }

    char lastCh = str[0];
    string res(1, lastCh);
    int count = 1;

    for (int i = 1; i < str.size(); ++i) {
      if (str[i] == lastCh) {
        count += 1;
      } else {
        res += to_string(count);

        lastCh = str[i];
        res += lastCh;
        count = 1;
      }
    }

    res += to_string(count);

    return res.size() < str.size() ? res : str;
  }
};
