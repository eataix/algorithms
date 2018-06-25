class Solution {
public:
  /**
   * @param s: A string
   * @param p: A string includes "." and "*"
   * @return: A boolean
   */
  bool isMatch(string &s, string &p) {
    vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));

    dp[0][0] = true;

    for (int i = 1; i <= p.size(); ++i) {
      dp[0][i] = p[i - 1] == '*' && dp[0][i - 2];
    }

    for (int i = 1; i <= s.size(); ++i) {
      for (int j = 1; j < p.size(); ++j) {
        if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
          dp[i][j] = dp[i - 1][j - 1];
        } else if (p[j - 1] == '*') {
          dp[i][j] = dp[i][j - 2]; // zero time

          if (p[j - 2] == '.' || p[j - 2] == s[i - 1]) {
            dp[i][j] = dp[i][j] || dp[i - 1][j];
          }
        }
      }
    }
    return dp.back().back();
  }
};

class Solution {
public:
  bool isMatch(string s, string p) {
    vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));

    dp[0][0] = true;
    for (int i = 1; i <= p.size(); ++i) {
      dp[0][i] = p[i - 1] == '*' && dp[0][i - 2];
    }

    for (int i = 1; i <= s.size(); ++i) {
      for (int j = 1; j <= p.size(); ++j) {
        if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
          dp[i][j] = dp[i - 1][j - 1];
        } else if (p[j - 1] == '*') {
          dp[i][j] = dp[i][j - 2];

          if (p[j - 2] == '.' || p[j - 2] == s[i - 1]) {
            dp[i][j] = dp[i][j] || dp[i - 1][j];
          }
        }
      }
    }
    return dp.back().back();
  }
};
