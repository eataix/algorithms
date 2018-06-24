class Solution {
public:
  /**
   * @param s: A string
   * @param p: A string includes "?" and "*"
   * @return: is Match?
   */
  bool isMatch(string &s, string &p) {
    vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));

    dp[0][0] = true;
    for (int i = 1; i <= p.size(); ++i) {
      dp[0][i] = dp[0][i - 1] && p[i - 1] == '*';
    }

    for (int i = 1; i <= s.size(); ++i) {
      for (int j = 1; j <= p.size(); ++j) {
        if (p[j - 1] == '*') {
          dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
        } else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1];
        }
      }
    }

    return dp.back().back();
  }
};
