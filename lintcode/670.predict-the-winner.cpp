class Solution {
public:
  /**
   * @param nums: nums an array of scores
   * @return: check if player 1 will win
   */
  bool PredictTheWinner(vector<int> &nums) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int len = 1; len <= n; ++len) {
      for (int start = 0; start < n; ++start) {
        int end = start + len - 1;
        if (end >= nums.size()) {
          break;
        }
        dp[start][end] =
            max(nums[start] - (start + 1 <= end ? dp[start + 1][end] : 0),
                nums[end] - (start <= end - 1 ? dp[start][end - 1] : 0));
      }
    }
    return dp[0][n - 1] > 0;
  }
};
