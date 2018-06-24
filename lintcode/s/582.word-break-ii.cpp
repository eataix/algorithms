#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  /*
   * @param s: A string
   * @param wordDict: A set of words.
   * @return: All possible sentences.
   */
  vector<string> wordBreak(string &s, unordered_set<string> &wordDict) {
    unordered_map<string, vector<string>> m;

    return wordBreakDFS(s, wordDict, m);
  }

  vector<string> wordBreakDFS(const string &s, unordered_set<string> &wordDict,
                              unordered_map<string, vector<string>> &m) {
    if (s.empty()) {
      return {""};
    }
    if (m.count(s)) {
      return m[s];
    }

    for (auto const &str : wordDict) {
      if (str.empty()) {
        continue;
      }
      string leftStr = s.substr(0, str.size());

      if (leftStr == str) {
        auto righStrs = wordBreakDFS(s.substr(str.size()), wordDict, m);

        for (auto const &rightStr : righStrs) {
          if (rightStr.empty()) {
            m[s].push_back(leftStr);
          } else {
            m[s].push_back(leftStr + " " + rightStr);
          }
        }
      }
    }
    return m[s];
  }
};

#ifdef DEBUG
int main() {
  string s{"a"};
  unordered_set<string> dict{""};
  Solution sol;

  auto ret = sol.wordBreak(s, dict);
}
#endif
