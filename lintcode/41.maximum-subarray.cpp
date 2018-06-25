class Solution {
public:
  /**
   * @param nums: A list of integers
   * @return: A integer indicate the sum of max subarray
   */
  int maxSubArray(vector<int> &nums) {

    if (nums.empty()) {
      return 0;
    }
    if (nums.size() == 1) {
      return nums[0];
    }

    vector<int> dp(nums.size(), 0);

    dp[0] = nums[0];

    for (int i = 1; i < nums.size(); ++i) {
      dp[i] = max(nums[i], nums[i] + dp[i - 1]);
    }

    int maxValue = numeric_limits<int>::min();

    for (int v : dp) {
      maxValue = max(maxValue, v);
    }

    return maxValue;
  }
};
