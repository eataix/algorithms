#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  /**
   * @param nums: A list of integer
   * @return: An integer, maximum coins
   */
  int maxCoins(vector<int> &nums) {
    int oldN = nums.size();
    nums.insert(nums.begin(), 1);
    nums.push_back(1);

    vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));

    for (int len = 1; len <= oldN; ++len) {
      for (int start = 1; start <= oldN; ++start) {
        int end = start + len - 1;
        if (end > oldN) {
          break;
        }
        for (int k = start; k <= end; ++k) {
          dp[start][end] =
              max(dp[start][end],
                  dp[start][k - 1] + nums[k] * nums[start - 1] * nums[end + 1] +
                      dp[k + 1][end]);
        }
      }
    }
    return dp[1][oldN];
  }
};
