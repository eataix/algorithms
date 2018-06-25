class Solution {
public:
  /**
   * @param prices: Given an integer array
   * @return: Maximum profit
   */
  int maxProfit(vector<int> &prices) {
    int total = 0;

    for (int i = 1; i < prices.size(); ++i) {
      total += max(0, prices[i] - prices[i - 1]);
    }
    return total;
  }
};
