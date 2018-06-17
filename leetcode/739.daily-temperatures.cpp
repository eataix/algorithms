#include <iostream>
#include <queue>
#include <stack>
#include <utility>
#include <vector>
using namespace std;
/*
 * [739] Daily Temperatures
 *
 * https://leetcode.com/problems/daily-temperatures/description/
 *
 * algorithms
 * Medium (53.17%)
 * Total Accepted:    16.4K
 * Total Submissions: 30.8K
 * Testcase Example:  '[73,74,75,71,69,72,76,73]'
 *
 *
 * Given a list of daily temperatures, produce a list that, for each day in the
 * input, tells you how many days you would have to wait until a warmer
 * temperature.  If there is no future day for which this is possible, put 0
 * instead.
 *
 * For example, given the list temperatures = [73, 74, 75, 71, 69, 72, 76, 73],
 * your output should be [1, 1, 4, 2, 1, 1, 0, 0].
 *
 *
 * Note:
 * The length of temperatures will be in the range [1, 30000].
 * Each temperature will be an integer in the range [30, 100].
 *
 */
class Solution {
public:
  vector<int> dailyTemperatures(const vector<int> &temperatures) {
    stack<pair<int, int>> s;

    vector<int> res(temperatures.size());
    for (int i = temperatures.size() - 1; i >= 0; --i) {
      while (!s.empty() && s.top().first <= temperatures[i]) {
        s.pop();
      }

      res[i] = s.empty() ? 0 : s.top().second - i;

      s.push({temperatures[i], i});
    }

    return res;
  }

  vector<int> dailyTemperatures2(const vector<int> &temperatures) {
    vector<int> res(temperatures.size(), 0);

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        s;

    for (int i = 0; i < temperatures.size(); ++i) {
      int t = temperatures[i];
      while (!s.empty() && s.top().first < t) {
        auto p = s.top();
        s.pop();

        res[p.second] = i - p.second;
      }
      s.push({temperatures[i], i});
    }

    return res;
  }
};

#ifdef DEBUG
int main() {
  Solution sol;
  auto res = sol.dailyTemperatures(vector<int>{73, 74, 75, 71, 69, 72, 76, 73});
  for (auto r : res) {
    cout << r << " " << endl;
  }
  cout << endl;
}
#endif
