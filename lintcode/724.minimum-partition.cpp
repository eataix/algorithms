class Solution {
public:
  /**
   * @param nums: the given array
   * @return: the minimum difference between their sums
   */
  int findMin(vector<int> &nums) {
    int sum = accumulate(nums.cbegin(), nums.cend(), 0);

    vector<bool> dp(sum + 1, false);

    dp[0] = true;

    int best = 0;
    for (int num : nums) {
      for (int n = sum; n >= num; --n) {
        dp[n] = dp[n] || dp[n - num];

        if (dp[n]) {
          if (abs(n - sum / 2) < abs(best - sum / 2)) {
            best = n;
          }
        }
      }
    }

    return abs((sum - best) - best);
  }
};
