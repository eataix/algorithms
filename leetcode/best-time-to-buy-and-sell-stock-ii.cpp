#include <vector>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int p = 0;
    for (int i = 1; i < prices.size(); ++i) {
      int d = prices[i] - prices[i - 1];
      if (d > 0) {
        p += d;
      }
    }
    return p;
  }
};
