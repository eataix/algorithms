#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  string alienOrder(vector<string> &words) {
    unordered_set<char> nodes;
    unordered_map<char, unordered_set<char>> edges;
    unordered_map<char, int> indegrees;

    for (const auto &word : words) {
      nodes.insert(word.cbegin(), word.cend());
    }

    for (char ch : nodes) {
      indegrees[ch];
      edges[ch];
    }

    for (int i = 0; i < words.size() - 1; ++i) {
      string word1 = words[i];
      string word2 = words[i + 1];

      auto m{word1.size()};
      auto n{word2.size()};

      int j = 0;
      for (; j < min(m, n); ++j) {
        int c1 = word1[j];
        int c2 = word2[j];
        if (c1 != c2) {
          edges[c1].insert(c2);
          break;
        }
      }
      if (j == min(m, n) && m > n) {
        return "";
      }
    }

    for (auto const &kv : edges) {
      for (auto const v : kv.second) {
        indegrees[v] += 1;
      }
    }

    queue<char> q;
    for (char ch : nodes) {
      cout << string(1, ch) << " " << indegrees[ch] << endl;
      if (indegrees[ch] == 0) {
        q.push(ch);
      }
    }

    string res = "";
    while (!q.empty()) {
      char front = q.front();
      q.pop();

      res += front;

      for (auto &n : edges[front]) {
        indegrees[n] -= 1;
        if (indegrees[n] == 0) {
          q.push(n);
        }
      }
    }

    return res.size() == edges.size() ? res : "";
  }
};

#ifdef DEBUG
int main() {
  Solution sol;
  vector<string> s{"wrt", "wrf", "er", "ett", "rftt"};
  cout << sol.alienOrder(s) << endl;
  vector<string> s2{"z", "x"};
  cout << sol.alienOrder(s2) << endl;
  vector<string> s3{"z", "x", "z"};
  cout << sol.alienOrder(s3) << endl;
  vector<string> s4{"ab", "adc"};

  cout << sol.alienOrder(s4) << endl;
}
#endif
