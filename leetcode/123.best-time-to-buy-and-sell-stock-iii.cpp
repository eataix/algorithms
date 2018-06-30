#include <algorithm>
#include <limits>
#include <vector>
using namespace std;
/*
 * [123] Best Time to Buy and Sell Stock III
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/
 *
 * algorithms
 * Hard (30.76%)
 * Total Accepted:    112.1K
 * Total Submissions: 364.2K
 * Testcase Example:  '[3,3,5,0,0,3,1,4]'
 *
 * Say you have an array for which the ith element is the price of a given
 * stock on day i.
 *
 * Design an algorithm to find the maximum profit. You may complete at most two
 * transactions.
 *
 * Note: You may not engage in multiple transactions at the same time (i.e.,
 * you must sell the stock before you buy again).
 *
 * Example 1:
 *
 *
 * Input: [3,3,5,0,0,3,1,4]
 * Output: 6
 * Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit
 * = 3-0 = 3.
 * Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 =
 * 3.
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
      return false;
    }

    vector<int> sold1(prices.size());
    vector<int> sold2(prices.size());
    vector<int> bought1(prices.size());
    vector<int> bought2(prices.size());

    sold1[0] = sold2[0] = 0;
    bought1[0] = bought2[0] = -prices[0];

    for (int i = 1; i < prices.size(); ++i) {
      sold2[i] = max(sold2[i - 1], bought2[i - 1] + prices[i]);
      bought2[i] = max(bought2[i - 1], sold1[i - 1] - prices[i]);

      sold1[i] = max(sold1[i - 1], bought1[i - 1] + prices[i]);
      bought1[i] = max(bought1[i - 1], -prices[i]);
    }

    return sold2.back();
  }
};
