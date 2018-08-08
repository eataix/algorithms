#include <queue>
#include <string>
#include <unordered_map>
using namespace std;
/*
 * [778] Reorganize String
 *
 * https://leetcode.com/problems/reorganize-string/description/
 *
 * algorithms
 * Medium (37.35%)
 * Total Accepted:    8.4K
 * Total Submissions: 22.5K
 * Testcase Example:  '"aab"'
 *
 * Given a string S, check if the letters can be rearranged so that two
 * characters that are adjacent to each other are not the same.
 *
 * If possible, output any possible result.  If not possible, return the empty
 * string.
 *
 * Example 1:
 *
 *
 * Input: S = "aab"
 * Output: "aba"
 *
 *
 * Example 2:
 *
 *
 * Input: S = "aaab"
 * Output: ""
 *
 *
 * Note:
 *
 *
 * S will consist of lowercase letters and have length in range [1, 500].
 *
 *
 *
 */
class Solution {
public:
  string reorganizeString(string S) {
    int k = 2;

    priority_queue<pair<int, char>> pq;
    unordered_map<char, int> m;

    for (char ch : S) {
      m[ch] += 1;
    }

    for (auto const &kv : m) {
      auto ch = kv.first;
      auto freq = kv.second;
      pq.push({freq, ch});
    }

    string res;
    while (!pq.empty()) {
      int sz = min(static_cast<int>(S.size() - res.size()), k);

      vector<pair<int, int>> pairs;
      for (int i = 0; i < sz; ++i) {
        if (pq.empty()) {
          return "";
        }
        pairs.push_back(pq.top());
        pq.pop();
      }

      for (auto &pair : pairs) {
        res += pair.second;
        if (--pair.first > 0) {
          pq.push(pair);
        }
      }
    }
    return res.size() == S.size() ? res : "";
  }
};
