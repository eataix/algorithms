#include <vector>
using namespace std;

class Solution {
public:
  /**
   * @param nums: an integer array and all positive numbers, no duplicates
   * @param target: An integer
   * @return: An integer
   */
  int backPackVI(vector<int> &nums, int target) {
    vector<int> dp(target + 1, 0);

    dp[0] = 1;

    for (int i = 1; i <= target; ++i) {
      for (int num : nums) {
        if (i - num >= 0) {
          dp[i] += dp[i - num];
        }
      }
    }
    return dp[target];
  }
};
