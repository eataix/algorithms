#include <algorithm>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  string alienOrder(vector<string> &words) {
    unordered_set<char> nodes;
    unordered_map<char, int> indegrees;

    for (auto const &word : words) {
      nodes.insert(word.cbegin(), word.cend());
    }

    unordered_map<char, unordered_set<char>> adj;
    for (int i = 0; i < words.size() - 1; ++i) {
      auto currStr = words[i];
      auto nextStr = words[i + 1];
      int j = 0;
      for (; j < min(currStr.size(), nextStr.size()); ++j) {
        if (currStr[j] != nextStr[j]) {
          adj[currStr[j]].insert(nextStr[j]);
          break;
        }
      }

      if (j == min(currStr.size(), nextStr.size()) &&
          currStr.size() > nextStr.size()) {
        return "";
      }
    }

    for (auto const &kv : adj) {
      for (auto const &to : kv.second) {
        indegrees[to] += 1;
      }
    }

    queue<char> q;
    for (auto const &node : nodes) {
      if (indegrees[node] == 0) {
        q.push(node);
      }
    }

    string res;
    while (!q.empty()) {
      auto ch = q.front();
      q.pop();
      res += ch;
      for (char next : adj[ch]) {
        if (--indegrees[next] == 0) {
          q.push(next);
        }
      }
    }

    return res.size() == nodes.size() ? res : "";
  }
};
