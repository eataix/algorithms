#include <iostream>
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
  vector<string> wordBreak(string &s, const unordered_set<string> &wordDict) {
    unordered_map<string, vector<string>> m;

    return wordBreakRecursive(s, wordDict, m);
  }

  vector<string> wordBreakRecursive(string &str,
                                    const unordered_set<string> &wordDict,
                                    unordered_map<string, vector<string>> m) {
#ifdef DEBUG
    cout << "str: " << str << endl;
#endif
    if (m.find(str) != cend(m)) {
      return m[str];
    } else if (str.empty()) {
      return vector<string>{""};
    } else {
      vector<string> res;

      for (string word : wordDict) {
        string left = str.substr(0, word.size());
        if (left != word) {
          continue;
        }
        string right = str.substr(word.size());
#ifdef DEBUG
        cout << "left: " << left << " right: " << right << endl;
#endif
        auto ret = wordBreakRecursive(right, wordDict, m);
        for (auto r : ret) {
          res.push_back(r.empty() ? left : left + ' ' + r);
        }
      }
      m[str] = res;
      return res;
    }
  }
};

#ifdef DEBUG
int main() {
  string s{"lintcode"};
  unordered_set<string> dict{"de", "ding", "co", "code", "lint"};
  Solution sol;

  auto ret = sol.wordBreak(s, dict);
  for (auto r : ret) {
    cout << "'" << r << "'" << endl;
  }
}
#endif
