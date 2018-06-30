#include <vector>
using namespace std;
/*
 * [309] Best Time to Buy and Sell Stock with Cooldown
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
 *
 * algorithms
 * Medium (42.06%)
 * Total Accepted:    60.7K
 * Total Submissions: 144.3K
 * Testcase Example:  '[1,2,3,0,2]'
 *
 * Say you have an array for which the ith element is the price of a given
 * stock on day i.
 *
 * Design an algorithm to find the maximum profit. You may complete as many
 * transactions as you like
 * (ie, buy one and sell one share of the stock multiple times) with the
 * following restrictions:
 *
 *
 * ⁠   You may not engage in multiple transactions at the same time (ie, you
 * must sell the stock before you buy again).
 * ⁠   After you sell your stock, you cannot buy stock on next day. (ie,
 * cooldown 1 day)
 *
 *
 * Example:
 *
 * prices = [1, 2, 3, 0, 2]
 * maxProfit = 3
 * transactions = [buy, sell, cooldown, buy, sell]
 *
 *
 * Credits:Special thanks to @dietpepsi for adding this problem and creating
 * all test cases.
 */
class Solution {
public:
  int maxProfit(vector<int> &prices) {
      int n = prices.size();
      if (n <= 1) {
          return 0;
      }
    vector<int> sold(prices.size());
    vector<int> bought(prices.size());

    sold[0] = 0;
    bought[0] = -prices[0];

    for (int i = 1; i < prices.size(); ++i) {
      sold[i] = max(sold[i - 1], bought[i - 1] + prices[i]);
      bought[i] = max(bought[i - 1], i - 2 >= 0 ? sold[i - 2] - prices[i]
                                                : -prices[i]);
    }

    return sold.back();
  }
};

