#include <algorithm>
#include <vector>
using namespace std;
/*
 * [121] Best Time to Buy and Sell Stock
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
 *
 * algorithms
 * Easy (42.92%)
 * Total Accepted:    284.8K
 * Total Submissions: 663.7K
 * Testcase Example:  '[7,1,5,3,6,4]'
 *
 * Say you have an array for which the ith element is the price of a given
 * stock on day i.
 *
 * If you were only permitted to complete at most one transaction (ie, buy one
 * and sell one share of the stock), design an algorithm to find the maximum
 * profit.
 *
 * Example 1:
 *
 * Input: [7, 1, 5, 3, 6, 4]
 * Output: 5
 *
 * max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger
 * than buying price)
 *
 *
 *
 * Example 2:
 *
 * Input: [7, 6, 4, 3, 1]
 * Output: 0
 *
 * In this case, no transaction is done, i.e. max profit = 0.
 *
 *
 */
class Solution {
public:
  int maxProfit(vector<int> &prices) {
    if (prices.size() <= 1) {
      return false;
    }

    vector<int> sell(prices.size());
    vector<int> buy(prices.size());

    buy[0] = -prices[0];
    sell[0] = 0;

    for (int i = 1; i < prices.size(); ++i) {
      sell[i] = max(sell[i - 1], buy[i - 1] + prices[i]);
      buy[i] = max(buy[i - 1], 0 - prices[i]);
    }

    return sell.back();
  }

  int maxProfit2(vector<int> &prices) {
    if (prices.size() <= 1) {
      return false;
    }

    vector<int> sell(prices.size() + 1);
    vector<int> buy(prices.size() + 1);

    sell[0] = 0;
    buy[0] = numeric_limits<int>::min();

    for (int i = 1; i <= prices.size(); ++i) {
      sell[i] = max(sell[i - 1], buy[i - 1] + prices[i - 1]);
      buy[i] = max(buy[i - 1], 0 - prices[i - 1]);
    }

    return sell.back();
  }

  int maxProfit2(vector<int> &prices) {
    if (prices.empty()) {
      return 0;
    }
    int minSoFar = prices[0];
    int ret = 0;
    for (auto &p : prices) {
      minSoFar = min(minSoFar, p);
      ret = max(ret, p - minSoFar);
    }
    return ret;
  }
};
