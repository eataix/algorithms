#include <algoirthm>
#include <vector>
using namespace std;
/*
 * [322] Coin Change
 *
 * https://leetcode.com/problems/coin-change/description/
 *
 * algorithms
 * Medium (26.59%)
 * Total Accepted:    94.4K
 * Total Submissions: 355.1K
 * Testcase Example:  '[1]\n0'
 *
 *
 * You are given coins of different denominations and a total amount of money
 * amount. Write a function to compute the fewest number of coins that you need
 * to make up that amount. If that amount of money cannot be made up by any
 * combination of the coins, return -1.
 *
 *
 *
 * Example 1:
 * coins = [1, 2, 5], amount = 11
 * return 3 (11 = 5 + 5 + 1)
 *
 *
 *
 * Example 2:
 * coins = [2], amount = 3
 * return -1.
 *
 *
 *
 * Note:
 * You may assume that you have an infinite number of each kind of coin.
 *
 *
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and
 * creating all test cases.
 */
class Solution {
public:
  int coinChange(vector<int> &coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;

    for (int i = 1; i <= amount; ++i) {
      for (auto const &coin : coins) {
        if (coin <= i) {
          dp[i] = min(dp[i], dp[i - coin] + 1);
        }
      }
    }

    return dp[amount] > amount ? -1 : dp[amount];
  }
};
