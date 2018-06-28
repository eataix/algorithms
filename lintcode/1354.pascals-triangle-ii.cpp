class Solution {
public:
  /**
   * @param rowIndex: a non-negative index
   * @return: the kth index row of the Pascal's triangle
   */
  vector<int> getRow(int rowIndex) {
    vector<int> dp(rowIndex + 1, 0);

    dp[0] = 1;

    for (int r = 1; r <= rowIndex; ++r) {
      for (int c = r; c >= 1; --c) {
        dp[c] = dp[c] + dp[c - 1];
      }
    }
    return dp;
  }
};
