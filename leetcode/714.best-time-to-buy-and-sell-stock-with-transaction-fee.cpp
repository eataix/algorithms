#include <vector>
using namespace std;
/*
 * [714] Best Time to Buy and Sell Stock with Transaction Fee
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/
 *
 * algorithms
 * Medium (46.76%)
 * Total Accepted:    19.2K
 * Total Submissions: 41K
 * Testcase Example:  '[1,3,2,8,4,9]\n2'
 *
 * Your are given an array of integers prices, for which the i-th element is
 * the price of a given stock on day i; and a non-negative integer fee
 * representing a transaction fee.
 * You may complete as many transactions as you like, but you need to pay the
 * transaction fee for each transaction.  You may not buy more than 1 share of
 * a stock at a time (ie. you must sell the stock share before you buy again.)
 * Return the maximum profit you can make.
 *
 * Example 1:
 *
 * Input: prices = [1, 3, 2, 8, 4, 9], fee = 2
 * Output: 8
 * Explanation: The maximum profit can be achieved by:
 * Buying at prices[0] = 1Selling at prices[3] = 8Buying at prices[4] =
 * 4Selling at prices[5] = 9The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) =
 * 8.
 *
 *
 *
 * Note:
 * 0 < prices.length .
 * 0 < prices[i] < 50000.
 * 0 .
 *
 */
class Solution {
public:
  int maxProfit(vector<int> &prices, int fee) {
    int n = prices.size();

    if (n <= 1) {
      return 0;
    }

    vector<int> sold(prices.size());
    vector<int> bought(prices.size());

    sold[0] = 0;
    bought[0] = -prices[0];

    for (int i = 1; i < prices.size(); ++i) {
      sold[i] = max(sold[i - 1], bought[i - 1] + prices[i] - fee);
      bought[i] = max(bought[i - 1], sold[i - 1] - prices[i]);
    }

    return sold.back();
  }

  int maxProfit1(vector<int> &prices, int fee) {
    if (prices.size() <= 1) {
      return 0;
    }
    vector<int> sell(prices.size());
    vector<int> buy(prices.size());

    sell[0] = 0;
    buy[0] = -prices[0];

    for (int i = 1; i < prices.size(); ++i) {
      sell[i] = max(sell[i - 1], buy[i - 1] + prices[i] - fee);
      buy[i] = max(buy[i - 1], sell[i - 1] - prices[i]);
    }

    return sell.back();
  }
};
