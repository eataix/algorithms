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
  bool dfs(string num, string den,
           unordered_map<string, unordered_map<string, double>> &edgeWeights,
           unordered_set<string> &visited, double &res) {
    if (edgeWeights[num].count(den)) {
      res = edgeWeights[num][den];
      return true;
    }

    for (auto const &edge : edgeWeights[num]) {
      auto nei = edge.first;
      auto weight = edge.second;
      if (!visited.count(nei)) {
        visited.insert(nei);
        if (dfs(nei, den, edgeWeights, visited, res)) {
          res *= weight;
          return true;
        }
      }
    }

    return false;
  }

public:
  vector<double> calcEquation(vector<pair<string, string>> equations,
                              vector<double> &values,
                              vector<pair<string, string>> queries) {

    int n = equations.size();

    unordered_map<string, unordered_map<string, double>> edgeWeights;
    for (int i = 0; i < n; ++i) {
      auto eq = equations[i];
      auto num = eq.first;
      auto den = eq.second;
      edgeWeights[num][den] = values[i];
      edgeWeights[den][num] = 1.0 / values[i];
    }

    vector<double> res;
    for (auto const &query : queries) {
      auto num = query.first;
      auto den = query.second;
      unordered_set<string> visited{num};
      double v = -1.0;
      dfs(num, den, edgeWeights, visited, v);
      res.push_back(v);
    }
    return res;
  }
};
