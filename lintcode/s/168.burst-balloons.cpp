class Solution {
public:
  /**
   * @param nums: A list of integer
   * @return: An integer, maximum coins
   */
  int maxCoins(vector<int> &nums) {
    int n = nums.size();

    nums.push_back(1);
    nums.insert(begin(nums), 1);

    vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));
    for (int len = 1; len <= n; ++len) {
      for (int start = 1; start <= n; ++start) {
        int end = start + len - 1;
        if (end > n) {
          break;
        }

        for (int k = start; k <= end; ++k) {
          dp[start][end] =
              max(dp[start][end], nums[k] * nums[start - 1] * nums[end + 1] +
                                      dp[start][k - 1] + dp[k + 1][end]);
        }
      }
    }
    return dp[1][n];
  }
};
