class Solution {
public:
  /**
   * @param str: the origin string
   * @return: the start and end of every twitch words
   */
  vector<vector<int>> twitchWords(string &str) {
    vector<vector<int>> res;
    for (int start = 0; start < str.size();) {
      int len = 1;

      while (str[start + len] == str[start]) {
        len += 1;
      }

      if (len >= 3) {
        res.push_back({start, start + len - 1});
      }
      start += len;
    }
    return res;
  }
};
