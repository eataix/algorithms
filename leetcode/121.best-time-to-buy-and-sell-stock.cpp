#include <vector>
#include <algorithm>
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
class Solution
{
  public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.empty())
        {
            return 0;
        }
        int minSoFar = prices.front();
        int ret = 0;
        for (auto i : prices)
        {
            if (i < minSoFar)
            {
                minSoFar = i;
            }
            ret = max(ret, i - minSoFar);
        }
        return ret;
    }
};