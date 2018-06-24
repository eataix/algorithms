#include <vector>
using namespace std;

class Solution {
public:
  /**
   * @param stones: a list of stones' positions in sorted ascending order
   * @return: true if the frog is able to cross the river or false
   */
  bool canCross(vector<int> &stones) {
    unordered_map<int, unordered_set<int>> powers;
    powers[0].insert(0);

    for (int stone : stones) {
      for (int power : powers[stone]) {
        for (int k = power - 1; k <= power + 1; ++k) {
          if (k > 0) {
            powers[stone + k].insert(k);
          }
        }
      }
    }
    return !powers[stones.back()].empty();
  }
};
