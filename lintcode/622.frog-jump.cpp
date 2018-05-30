#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  /**
   * @param stones: a list of stones' positions in sorted ascending order
   * @return: true if the frog is able to cross the river or false
   */
  bool canCross(const vector<int> &stones) {
    unordered_set<int> d{stones.cbegin(), stones.cend()};
    unordered_map<int, unordered_set<int>> m;

    m[0].insert(0);

    for (int i = 0; i < stones.size(); ++i) {
      int stone = stones[i];

      for (int power : m[stone]) {
        for (int n = power - 1; n <= power + 1; ++n) {
          if (n > 0) {
            if (d.find(stone + n) != d.cend()) {
              m[stone + n].insert(n);
            }
          }
        }
      }
    }

    return !m[stones.back()].empty();
  }
};

#ifdef DEBUG
int main() {
  Solution sol;
  cout << sol.canCross(vector<int>{0, 1, 3, 5, 6, 8, 12, 17}) << endl;
  cout << sol.canCross(vector<int>{0, 1, 2, 3, 4, 8, 9, 11}) << endl;
}
#endif
