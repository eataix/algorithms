/*
 * [188] Best Time to Buy and Sell Stock IV
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/
 *
 * algorithms
 * Hard (25.10%)
 * Total Accepted:    64.4K
 * Total Submissions: 256.4K
 * Testcase Example:  '2\n[2,4,1]'
 *
 * Say you have an array for which the ith element is the price of a given
 * stock on day i.
 *
 * Design an algorithm to find the maximum profit. You may complete at most k
 * transactions.
 *
 * Note:
 * You may not engage in multiple transactions at the same time (ie, you must
 * sell the stock before you buy again).
 *
 * Example 1:
 *
 *
 * Input: [2,4,1], k = 2
 * Output: 2
 * Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit
 * = 4-2 = 2.
 *
 *
 * Example 2:
 *
 *
 * Input: [3,2,6,5,0,3], k = 2
 * Output: 7
 * Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit
 * = 6-2 = 4.
 * Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 =
 * 3.
 *
 *
 */

class Solution {
public:
  int maxProfit(int k, vector<int> &prices) {
    if (prices.size() <= 1 || k <= 0) {
      return 0;
    }

    if (k >= (prices.size() >> 1)) {
      int bought = -prices[0];
      int sold = 0;

      for (int i = 1; i < prices.size(); ++i) {
        sold = max(sold, bought + prices[i]);
        bought = max(bought, sold - prices[i]);
      }

      return sold;
    }

    vector<int> bought(k + 1);
    vector<int> sold(k + 1);

    for (int j = 0; j <= k; ++j) {
      sold[j] = 0; // no transaction.
      bought[j] = -prices[0];
    }

    for (int i = 1; i < prices.size(); ++i) {
      for (int j = k; j >= 1; --j) {
        sold[j] = max(sold[j], bought[j] + prices[i]);
        bought[j] =
            max(bought[j], j - 1 >= 0 ? sold[j - 1] - prices[i] : -prices[i]);
      }
    }
    return sold.back();
  }
};
