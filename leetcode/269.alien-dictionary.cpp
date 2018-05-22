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
  string alienOrder(const vector<string> &words) {
    set<pair<char, char>> edges;
    unordered_set<char> chars;
    vector<int> indegree(256, 0);
    queue<char> q;
    string res = "";

    for (const auto &word : words) {
      chars.insert(word.cbegin(), word.cend());
    }

    for (int i = 0; i < words.size() - 1; ++i) {
      int mn = min(words[i].size(), words[i + 1].size());
      int j = 0;
      for (; j < mn; ++j) {
        if (words[i][j] != words[i + 1][j]) {
          edges.insert({words[i][j], words[i + 1][j]});
          break;
        }
      }
      if (j == mn && words[i].size() > words[i + 1].size()) {
        return "";
      }
    }

    for (const auto &e : edges) {
      indegree[e.second] += 1;
    }

    for (const auto &c : chars) {
      if (indegree[c] == 0) {
        q.push(c);
        res += c;
      }
    }

    while (!q.empty()) {
      char c = q.front();
      q.pop();

      for (const auto &edge : edges) {
        if (edge.first == c) {
          indegree[edge.second] -= 1;
          if (indegree[edge.second] == 0) {
            q.push(edge.second);
            res += edge.second;
          }
        }
      }
    }

    return res.size() == chars.size() ? res : "";
  }
};
