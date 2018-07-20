#include <utility>
#include <vector>
using namespace std;
/*
 * [323] Number of Connected Components in an Undirected Graph
 *
 * https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/description/
 *
 * algorithms
 * Medium (49.25%)
 * Total Accepted:    40.1K
 * Total Submissions: 81.5K
 * Testcase Example:  '5\n[[0,1],[1,2],[3,4]]'
 *
 * Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each
 * edge is a pair of nodes), write a function to find the number of connected
 * components in an undirected graph.
 *
 * Example 1:
 *
 *
 * Input: n = 5 and edges = [[0, 1], [1, 2], [3, 4]]
 *
 * ⁠    0          3
 * ⁠    |          |
 * ⁠    1 --- 2    4
 *
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]]
 *
 * ⁠    0           4
 * ⁠    |           |
 * ⁠    1 --- 2 --- 3
 *
 * Output:  1
 *
 *
 * Note:
 * You can assume that no duplicate edges will appear in edges. Since all edges
 * are undirected, [0, 1] is the same as [1, 0] and thus will not appear
 * together in edges.
 *
 */
class Solution {
public:
  int countComponents(int n, vector<pair<int, int>> &edges) {
    vector<int> parents(n);
    iota(parents.begin(), parents.end(), 0);

    for (auto const &edge : edges) {
      int v = edge.first, w = edge.second;
      while (parents[v] != v)
        v = parents[v] = parents[parents[v]];
      while (parents[w] != w)
        w = parents[w] = parents[parents[w]];
      parents[v] = w;
      n -= v != w;
    }

    return n;
  }
};
