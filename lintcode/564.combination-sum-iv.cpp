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

    for (int k = 1; k <= target; ++k) {
      for (int num : nums) {
        if (k - num >= 0) {

          dp[k] += dp[k - num];
        }
      }
    }
    return dp.back();
  }
};
