#include <string>
#include <utility>
#include <vector>
using namespace std;
/*
 * [760] Bold Words in String
 *
 * https://leetcode.com/problems/bold-words-in-string/description/
 *
 * algorithms
 * Easy (39.72%)
 * Total Accepted:    4.9K
 * Total Submissions: 12.3K
 * Testcase Example:  '["ab","bc"]\n"aabcd"'
 *
 *
 * Given a set of keywords words and a string S, make all appearances of all
 * keywords in S bold.  Any letters between <b> and </b> tags become bold.
 *
 * The returned string should use the least number of tags possible, and of
 * course the tags should form a valid combination.
 *
 *
 * For example, given that words = ["ab", "bc"] and  S = "aabcd", we should
 * return "a<b>abc</b>d".  Note that returning "a<b>a<b>b</b>c</b>d" would use
 * more tags, so it is incorrect.
 *
 *
 * Note:
 * words has length in range [0, 50].
 * words[i] has length in range [1, 10].
 * S has length in range [0, 500].
 * All characters in words[i] and S are lowercase letters.
 *
 */

class Solution {
  vector<pair<int, int>> merge(vector<pair<int, int>> pairs) {
    vector<pair<int, int>> res;
    sort(pairs.begin(), pairs.end(),
         [](const pair<int, int> &p1, const pair<int, int> &p2) {
           return p1.first < p2.first;
         });
    for (auto const &p : pairs) {
      if (!res.empty() && p.first <= res.back().second) {
        res.back().second = max(res.back().second, p.second);
      } else {
        res.push_back(p);
      }
    }
    return res;
  }

  vector<pair<int, int>> findPairs(const string &s, const vector<string> &kws) {
    vector<pair<int, int>> res;
    for (auto const &kw : kws) {
      auto n = kw.size();
      for (int i = 0; (i = s.find(kw, i)) != string::npos; ++i) {
        res.push_back({i, i + n});
      }
    }
    return res;
  }

public:
  string boldWords(vector<string> &words, string S) {
    auto pairs = findPairs(S, words);
    pairs = merge(pairs);
    for (auto it = pairs.rbegin(); it != pairs.rend(); ++it) {
      S.insert(it->second, "</b>");
      S.insert(it->first, "<b>");
    }
    return S;
  }
};
