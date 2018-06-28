class Solution {
public:
  /*
   * @param s: A string
   * @param dict: A dictionary of words dict
   * @return: A boolean
   */
  bool wordBreak(string &s, unordered_set<string> &dict) {

    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;

    for (int len = 1; len <= s.size(); ++len) {
      for (int prefixLen = 0; prefixLen < len; ++prefixLen) {
        dp[len] =
            dp[prefixLen] && dict.count(s.substr(prefixLen, len - prefixLen));
        if (dp[len]) {
          break;
        }
      }
    }

    return dp.back();
  }
};
