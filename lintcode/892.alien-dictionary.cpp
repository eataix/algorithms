#include <algorithm>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  /**
   * @param words: a list of words
   * @return: a string which is correct order
   */
  string alienOrder(vector<string> &words) {
    string res = "";
    if (words.size() <= 1) {
      return res;
    }
    unordered_map<char, unordered_set<char>> edges;
    unordered_set<char> nodes;
    unordered_map<char, int> indegrees;

    for (auto const &word : words) {
      nodes.insert(cbegin(word), cend(word));
    }

    for (char node : nodes) {
      edges[node];
      indegrees[node];
    }

    for (int i = 0; i < words.size() - 1; ++i) {
      string wordA = words[i];
      string wordB = words[i + 1];
      int n = wordA.size();
      int m = wordB.size();

      int j = 0;
      for (; j < min(n, m); ++j) {
        if (wordA[j] != wordB[j]) {
          edges[wordA[j]].insert(wordB[j]);
          break;
        }
      }

      if (j == min(n, m) && n > m) {
        return "";
      }
    }
    for (const auto &kv : edges) {
      for (char n : kv.second) {
        indegrees[n] += 1;
      }
    }
    priority_queue<char, vector<char>, greater<char>> q;
    for (const auto &kv : indegrees) {
      if (kv.second == 0) {
        q.push(kv.first);
      }
    }

    while (!q.empty()) {
      char front = q.top();
      q.pop();
      res += front;
      for (char n : edges[front]) {
        indegrees[n] -= 1;
        if (indegrees[n] == 0) {
          q.push(n);
        }
      }
    }
    return res;
  }
};
