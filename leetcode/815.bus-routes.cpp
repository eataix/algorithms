#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
/*
 * [833] Bus Routes
 *
 * https://leetcode.com/problems/bus-routes/description/
 *
 * algorithms
 * Hard (32.68%)
 * Total Accepted:    5.3K
 * Total Submissions: 16.2K
 * Testcase Example:  '[[1,2,7],[3,6,7]]\n1\n6'
 *
 * We have a list of bus routes. Each routes[i] is a bus route that the i-th
 * bus repeats forever. For example if routes[0] = [1, 5, 7], this means that
 * the first bus (0-th indexed) travels in the sequence
 * 1->5->7->1->5->7->1->... forever.
 *
 * We start at bus stop S (initially not on a bus), and we want to go to bus
 * stop T. Travelling by buses only, what is the least number of buses we must
 * take to reach our destination? Return -1 if it is not possible.
 *
 *
 * Example:
 * Input:
 * routes = [[1, 2, 7], [3, 6, 7]]
 * S = 1
 * T = 6
 * Output: 2
 * Explanation:
 * The best strategy is take the first bus to the bus stop 7, then take the
 * second bus to the bus stop 6.
 *
 *
 * Note:
 *
 *
 * 1 <= routes.length <= 500.
 * 1 <= routes[i].length <= 500.
 * 0 <= routes[i][j] < 10 ^ 6.
 *
 */
class Solution {
public:
  int numBusesToDestination(vector<vector<int>> &routes, int S, int T) {
    unordered_map<int, unordered_set<int>> stopsAt;

    for (int i = 0; i < routes.size(); ++i) {
      for (auto const &stop : routes[i]) {
        stopsAt[stop].insert(i);
      }
    }

    queue<pair<int, int>> q;
    q.push({S, 0});
    unordered_set<int> seen{S};
    while (!q.empty()) {
      auto stop = q.front().first;
      auto dist = q.front().second;
      q.pop();
      if (stop == T) {
        return dist;
      }
      for (auto &bus : stopsAt[stop]) {
        for (auto &next_stop : routes[bus]) {
          if (!seen.count(next_stop)) {
            seen.insert(next_stop);
            q.push({next_stop, dist + 1});
          }
        }
        routes[bus].clear();
      }
    }
    return -1;
  }
};
