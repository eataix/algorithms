#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <set>
#include <utility>
#include <vector>
using namespace std;

/*
 * [803] Cheapest Flights Within K Stops
 *
 * https://leetcode.com/problems/cheapest-flights-within-k-stops/description/
 *
 * algorithms
 * Medium (29.88%)
 * Total Accepted:    4.9K
 * Total Submissions: 16.3K
 * Testcase Example:  '3\n[[0,1,100],[1,2,100],[0,2,500]]\n0\n2\n1'
 *
 * There are n cities connected by m flights. Each fight starts from city u and
 * arrives at v with a price w.
 *
 * Now given all the cities and fights, together with starting city src and the
 * destination dst, your task is to find the cheapest price from src to dst
 * with up to k stops. If there is no such route, output -1.
 *
 *
 * Example 1:
 * Input:
 * n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
 * src = 0, dst = 2, k = 1
 * Output: 200
 * Explanation:
 * The graph looks like this:
 *
 *
 * The cheapest price from city 0 to city 2 with at most 1 stop costs 200, as
 * marked red in the picture.
 *
 *
 * Example 2:
 * Input:
 * n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
 * src = 0, dst = 2, k = 0
 * Output: 500
 * Explanation:
 * The graph looks like this:
 *
 *
 * The cheapest price from city 0 to city 2 with at most 0 stop costs 500, as
 * marked blue in the picture.
 *
 * Note:
 *
 *
 * The number of nodes n will be in range [1, 100], with nodes labeled from 0
 * to n - 1.
 * The size of flights will be in range [0, n * (n - 1) / 2].
 * The format of each flight will be (src, dst, price).
 * The price of each flight will be in the range [1, 10000].
 * k is in the range of [0, n - 1].
 * There will not be any duplicated flights or self cycles.
 *
 */

class Solution {
public:
  int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst,
                        int K) {
    const int maxDistance = 10000 * 100 + 1;
    vector<vector<int>> fromSrc(n, vector<int>(K + 2, maxDistance));

    for (int i = 0; i < K + 2; ++i) {
      fromSrc[src][i] = 0;
    }

    for (int i = 1; i < K + 2; ++i) {
      for (auto flight : flights) {
        int u = flight[0];
        int v = flight[1];
        int w = flight[2];
        fromSrc[v][i] = min(fromSrc[v][i], fromSrc[u][i - 1] + w);
      }
    }

    int minV = fromSrc[dst][K + 1];
    return minV == maxDistance ? -1 : minV;
  }
};

#ifdef DEBUG
int main() {
  Solution sol;
  {
    int n = 3;
    vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
    int src = 0;
    int dst = 2;
    int k = 1;

    cout << sol.findCheapestPrice(n, flights, src, dst, k) << endl;
  }

  {
    int n = 3;
    vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
    int src = 0;
    int dst = 2;
    int k = 0;
    cout << sol.findCheapestPrice(n, flights, src, dst, k) << endl;
  }

  {
    int n = 4;
    vector<vector<int>> flights = {{0, 1, 1}, {0, 2, 5}, {1, 2, 1}, {2, 3, 1}};
    int src = 0;
    int dst = 3;
    int k = 1;
    cout << sol.findCheapestPrice(n, flights, src, dst, k) << endl;
  }
}
#endif