#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  /**
   * @param s: A string
   * @param p: A string includes "?" and "*"
   * @return: is Match?
   */
  bool isMatch(const string &str, const string &pattern) {
    vector<vector<bool>> dp(str.size() + 1,
                            vector<bool>(pattern.size() + 1, false));

    dp[0][0] = true;

    for (int j = 1; j <= pattern.size(); ++j) {
      if (pattern[j - 1] == '*') {
        dp[0][j] = dp[0][j - 1];
      }
    }

    for (int i = 1; i <= str.size(); ++i) {
      for (int j = 1; j <= pattern.size(); ++j) {
        char sc = str[i - 1];
        char pc = pattern[j - 1];
        if (sc == pc || pc == '?') {
          dp[i][j] = dp[i - 1][j - 1];
        } else if (pc == '*') {
          dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
        }
      }
    }
    return dp[str.size()][pattern.size()];
  }
};

#ifdef DEBUG
int main() {
  Solution sol;
  cout << sol.isMatch("aa", "a") << endl;
  cout << sol.isMatch("aa", "aa") << endl;
  cout << sol.isMatch("aaa", "aa") << endl;
  cout << sol.isMatch("aa", "*") << endl;
  cout << sol.isMatch("aa", "a*") << endl;
  cout << sol.isMatch("ab", "?*") << endl;
  cout << sol.isMatch("aab", "c*a*b") << endl;
}
#endif
