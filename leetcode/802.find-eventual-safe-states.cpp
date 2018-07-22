#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
/*
 * [820] Find Eventual Safe States
 *
 * https://leetcode.com/problems/find-eventual-safe-states/description/
 *
 * algorithms
 * Medium (38.62%)
 * Total Accepted:    6.3K
 * Total Submissions: 16.3K
 * Testcase Example:  '[[1,2],[2,3],[5],[0],[5],[],[]]'
 *
 * In a directed graph, we start at some node and every turn, walk along a
 * directed edge of the graph.  If we reach a node that is terminal (that is,
 * it has no outgoing directed edges), we stop.
 *
 * Now, say our starting node is eventually safe if and only if we must
 * eventually walk to a terminal node.  More specifically, there exists a
 * natural number K so that for any choice of where to walk, we must have
 * stopped at a terminal node in less than K steps.
 *
 * Which nodes are eventually safe?  Return them as an array in sorted order.
 *
 * The directed graph has N nodes with labels 0, 1, ..., N-1, where N is the
 * length of graph.  The graph is given in the following form: graph[i] is a
 * list of labels j such that (i, j) is a directed edge of the graph.
 *
 *
 * Example:
 * Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
 * Output: [2,4,5,6]
 * Here is a diagram of the above graph.
 *
 *
 *
 *
 *
 * Note:
 *
 *
 * graph will have length at most 10000.
 * The number of edges in the graph will not exceed 32000.
 * Each graph[i] will be a sorted list of different integers, chosen within the
 * range [0, graph.length - 1].
 *
 */
class Solution {
public:
  vector<int> eventualSafeNodes(const vector<vector<int>> &graph) {
    unordered_map<int, vector<int>> edges;

    for (int i = 0; i < graph.size(); ++i) {
      edges[i];
    }
    for (int i = 0; i < graph.size(); ++i) {
      for (int from : graph[i]) {
        edges[from].push_back(i);
      }
    }

    unordered_set<int> safe;
    queue<int> q;
    vector<int> indegrees(graph.size(), 0);
    for (auto const &kv : edges) {
      for (auto v : kv.second) {
        indegrees[v] += 1;
      }
    }

    for (int i = 0; i < graph.size(); ++i) {
      if (indegrees[i] == 0) {
        q.push(i);
      }
    }

    while (!q.empty()) {
      auto n = q.front();
      q.pop();

      safe.insert(n);

      for (auto next : edges[n]) {
        indegrees[next] -= 1;
        if (indegrees[next] == 0) {
          q.push(next);
        }
      }
    }

    vector<int> res;
    for (int i = 0; i < graph.size(); ++i) {
      if (safe.count(i)) {
        res.push_back(i);
      }
    }
    return res;
  }
};

#ifdef DEBUG
int main() {
  Solution sol;
  sol.eventualSafeNodes({{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}});
}
#endif
