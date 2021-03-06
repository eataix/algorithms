#include <utility>
#include <vector>
using namespace std;
/*
 * [261] Graph Valid Tree
 *
 * https://leetcode.com/problems/graph-valid-tree/description/
 *
 * algorithms
 * Medium (38.53%)
 * Total Accepted:    61.6K
 * Total Submissions: 159.8K
 * Testcase Example:  '5\n[[0,1],[0,2],[0,3],[1,4]]'
 *
 * Given n nodes labeled from 0 to n-1 and a list of undirected edges (each
 * edge is a pair of nodes), write a function to check whether these edges make
 * up a valid tree.
 *
 * Example 1:
 *
 *
 * Input: n = 5, and edges = [[0,1], [0,2], [0,3], [1,4]]
 * Output: true
 *
 * Example 2:
 *
 *
 * Input: n = 5, and edges = [[0,1], [1,2], [2,3], [1,3], [1,4]]
 * Output: false
 *
 * Note: you can assume that no duplicate edges will appear in edges. Since all
 * edges are undirected, [0,1] is the same as [1,0] and thus will not appear
 * together in edges.
 *
 */
class Solution {
  int findId(const vector<int> &parents, int v) {
    if (parents[v] == v) {
      return v;
    } else {
      return findId(parents, parents[v]);
    }
  }

public:
  bool validTree(int n, vector<pair<int, int>> &edges) {
    vector<int> parents(n);

    for (int i = 0; i < n; ++i) {
      parents[i] = i;
    }

    for (auto const &edge : edges) {
      auto u = edge.first;
      auto v = edge.second;

      u = findId(parents, u);
      v = findId(parents, v);

      if (u == v) {
        return false;
      }

      parents[u] = v;
    }

    return edges.size() == n - 1;
  }
};
