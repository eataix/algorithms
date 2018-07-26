#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;
/*
 * [310] Minimum Height Trees
 *
 * https://leetcode.com/problems/minimum-height-trees/description/
 *
 * algorithms
 * Medium (29.04%)
 * Total Accepted:    47.3K
 * Total Submissions: 163K
 * Testcase Example:  '4\n[[1,0],[1,2],[1,3]]'
 *
 * For a undirected graph with tree characteristics, we can choose any node as
 * the root. The result graph is then a rooted tree. Among all possible rooted
 * trees, those with minimum height are called minimum height trees (MHTs).
 * Given such a graph, write a function to find all the MHTs and return a list
 * of their root labels.
 *
 * Format
 * The graph contains n nodes which are labeled from 0 to n - 1. You will be
 * given the number n and a list of undirected edges (each edge is a pair of
 * labels).
 *
 * You can assume that no duplicate edges will appear in edges. Since all edges
 * are undirected, [0, 1] is the same as [1, 0] and thus will not appear
 * together in edges.
 *
 * Example 1 :
 *
 *
 * Input: n = 4, edges = [[1, 0], [1, 2], [1, 3]]
 *
 * ⁠       0
 * ⁠       |
 * ⁠       1
 * ⁠      / \
 * ⁠     2   3
 *
 * Output: [1]
 *
 *
 * Example 2 :
 *
 *
 * Input: n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]
 *
 * ⁠    0  1  2
 * ⁠     \ | /
 * ⁠       3
 * ⁠       |
 * ⁠       4
 * ⁠       |
 * ⁠       5
 *
 * Output: [3, 4]
 *
 * Note:
 *
 *
 * According to the definition of tree on Wikipedia: “a tree is an undirected
 * graph in which any two vertices are connected by exactly one path. In other
 * words, any connected graph without simple cycles is a tree.”
 * The height of a rooted tree is the number of edges on the longest downward
 * path between the root and a leaf.
 *
 *
 */
class Solution {
public:
  vector<int> findMinHeightTrees(int n, vector<pair<int, int>> &edges) {
    if (n == 1) {
      return {0};
    }

    vector<int> res;
    vector<unordered_set<int>> adj(n);
    for (auto const &edge : edges) {
      auto u = edge.first;
      auto v = edge.second;
      adj[u].insert(v);
      adj[v].insert(u);
    }

    queue<int> q;
    for (int i = 0; i < n; ++i) {
      if (adj[i].size() == 1) {
        q.push(i);
      }
    }

    while (n > 2) {
      auto size = q.size();
      n -= size;

      for (int i = 0; i < size; ++i) {
        int t = q.front();
        q.pop();
        for (auto a : adj[t]) {
          adj[a].erase(t);
          if (adj[a].size() == 1) {
            q.push(a);
          }
        }
      }
    }

    while (!q.empty()) {
      res.push_back(q.front());
      q.pop();
    }

    return res;
  }
};