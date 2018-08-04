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
    string res;

    unordered_map<char, int> m;
    priority_queue<pair<int, char>> pq;

    for (char ch : S) {
      m[ch] += 1;
    }

    for (auto const &kv : m) {
      auto ch = kv.first;
      auto freq = kv.second;
      if (freq > (S.size() + 1) / 2) {
        return "";
      }
      pq.push({freq, ch});
    }

    while (pq.size() >= 2) {
      auto t1 = pq.top();
      pq.pop();
      auto t2 = pq.top();
      pq.pop();

      res.push_back(t1.second);
      res.push_back(t2.second);

      if (--t1.first > 0) {
        pq.push(t1);
      }

      if (--t2.first > 0) {
        pq.push(t2);
      }
    }

    if (pq.size() > 0) {
      res.push_back(pq.top().second);
    }
    return res;
  }
};
