#include <algorithm>
#include <limits>
#include <vector>
using namespace std;
/*
 * [122] Best Time to Buy and Sell Stock II
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/
 *
 * algorithms
 * Easy (47.73%)
 * Total Accepted:    201.9K
 * Total Submissions: 422.9K
 * Testcase Example:  '[7,1,5,3,6,4]'
 *
 * Say you have an array for which the ith element is the price of a given
 * stock on day i.
 *
 * Design an algorithm to find the maximum profit. You may complete as many
 * transactions as you like (i.e., buy one and sell one share of the stock
 * multiple times).
 *
 * Note: You may not engage in multiple transactions at the same time (i.e.,
 * you must sell the stock before you buy again).
 *
 * Example 1:
 *
 *
 * Input: [7,1,5,3,6,4]
 * Output: 7
 * Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit
 * = 5-1 = 4.
 * Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 =
 * 3.
 *
 *
 * Example 2:
 *
 *
 * Input: [1,2,3,4,5]
 * Output: 4
 * Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit
 * = 5-1 = 4.
 * Note that you cannot buy on day 1, buy on day 2 and sell them later, as you
 * are
 * engaging multiple transactions at the same time. You must sell before buying
 * again.
 *
 *
 * Example 3:
 *
 *
 * Input: [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transaction is done, i.e. max profit = 0.
 *
 */
class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int n = prices.size();
    if (n <= 1) {
      return 0;
    }
    vector<int> sell(prices.size());
    vector<int> buy(prices.size());

    sell[0] = 0;
    buy[0] = -prices[0];

    for (int i = 1; i < prices.size(); ++i) {
      sell[i] = max(sell[i - 1], buy[i - 1] + prices[i]);
      buy[i] = max(buy[i - 1], sell[i - 1] - prices[i]);
    }

    return sell.back();
  }

  int maxProfit1(vector<int> &prices) {
    if (prices.size() <= 1) {
      return 0;
    }
    int profit = 0;
    for (int i = 1; i < prices.size(); ++i) {
      profit += max(0, prices[i] - prices[i - 1]);
    }
    return profit;
  }
};
