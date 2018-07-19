#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
/*
 * [399] Evaluate Division
 *
 * https://leetcode.com/problems/evaluate-division/description/
 *
 * algorithms
 * Medium (42.77%)
 * Total Accepted:    34.4K
 * Total Submissions: 80.5K
 * Testcase Example:  '[ ["a","b"],["b","c"] ]\n[2.0,3.0]\n[
 * ["a","c"],["b","c"],["a","e"],["a","a"],["x","x"] ]'
 *
 *
 * Equations are given in the format A / B = k, where  A and B are variables
 * represented as strings, and k is a real number (floating point number).
 * Given some queries, return the answers. If the answer does not exist, return
 * -1.0.
 *
 * Example:
 * Given  a / b = 2.0, b / c = 3.0. queries are:  a / c = ?,  b / a = ?, a / e
 * = ?,  a / a = ?, x / x = ? . return  [6.0, 0.5, -1.0, 1.0, -1.0 ].
 *
 *
 * The input is:  vector<pair<string, string>> equations, vector<double>&
 * values, vector<pair<string, string>> queries , where equations.size() ==
 * values.size(), and the values are positive. This represents the equations.
 * Return  vector<double>.
 *
 *
 * According to the example above:
 * equations = [ ["a", "b"], ["b", "c"] ],
 * values = [2.0, 3.0],
 * queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"]
 * ].
 *
 *
 *
 * The input is always valid. You may assume that evaluating the queries will
 * result in no division by zero and there is no contradiction.
 *
 */
class Solution {
  double check(string num, string den,
               unordered_map<string, unordered_map<string, double>> &edges,
               unordered_set<string> &visited) {
    if (edges[num].count(den)) {
      return edges[num][den];
    }

    for (auto edge : edges[num]) {
      auto nei = edge.first;
      auto w = edge.second;
      if (!visited.count(nei)) {
        visited.insert(nei);
        auto r = check(nei, den, edges, visited);
        if (r) {
          return w * r;
        }
      }
    }
    return 0;
  }

public:
  vector<double> calcEquation(vector<pair<string, string>> equations,
                              vector<double> &values,
                              vector<pair<string, string>> queries) {
    unordered_map<string, unordered_map<string, double>> edges;
    vector<double> res;
    for (int i = 0; i < values.size(); ++i) {
      auto u = equations[i].first;
      auto v = equations[i].second;
      edges[u][v] = values[i];
      if (values[i] != 0) {
        edges[v][u] = 1 / values[i];
      }
    }

    for (auto const &query : queries) {
      unordered_set<string> s;
      auto r = check(query.first, query.second, edges, s);
      if (r) {
        res.push_back(r);
      } else {
        res.push_back(-1);
      }
    }
    return res;
  }
};
