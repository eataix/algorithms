#include <set>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
/*
 * [332] Reconstruct Itinerary
 *
 * https://leetcode.com/problems/reconstruct-itinerary/description/
 *
 * algorithms
 * Medium (30.05%)
 * Total Accepted:    51.3K
 * Total Submissions: 170.6K
 * Testcase Example: '[["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]'
 *
 * Given a list of airline tickets represented by pairs of departure and
 * arrival airports [from, to], reconstruct the itinerary in order. All of the
 * tickets belong to a man who departs from JFK. Thus, the itinerary must begin
 * with JFK.
 *
 * Note:
 *
 *
 * If there are multiple valid itineraries, you should return the itinerary
 * that has the smallest lexical order when read as a single string. For
 * example, the itinerary ["JFK", "LGA"] has a smaller lexical order than
 * ["JFK", "LGB"].
 * All airports are represented by three capital letters (IATA code).
 * You may assume all tickets form at least one valid itinerary.
 *
 *
 * Example 1:
 *
 *
 * Input: tickets = [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR",
 * "SFO"]]
 * Output: ["JFK", "MUC", "LHR", "SFO", "SJC"]
 *
 *
 * Example 2:
 *
 *
 * Input: tickets =
 * [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
 * Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
 * Explanation: Another possible reconstruction is
 * ["JFK","SFO","ATL","JFK","ATL","SFO"]. But it is larger in lexical order.
 *
 *
 * Credits:
 * Special thanks to @dietpepsi for adding this problem and creating all test
 * cases.
 *
 */

class Solution {
  void dfs(unordered_map<string, multiset<string>> &m, const string &currCity,
           vector<string> &res) {
    while (!m[currCity].empty()) {
      auto it = m[currCity].begin();
      auto nextCity = *it;
      m[currCity].erase(it);
      dfs(m, nextCity, res);
    }
    res.push_back(currCity);
  }

public:
  vector<string> findItinerary(vector<pair<string, string>> tickets) {
    if (tickets.empty()) {
      return {};
    }
    vector<string> res;
    unordered_map<string, multiset<string>> m;
    for (auto const &ticket : tickets) {
      string from = ticket.first;
      string to = ticket.second;
      m[from].insert(to);
    }

    dfs(m, "JFK", res);
    return vector<string>{res.rbegin(), res.rend()};
  }
};
