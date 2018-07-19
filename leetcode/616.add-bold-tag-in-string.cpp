#include <string>
#include <utility>
#include <vector>
using namespace std;
/*
 * [616] Add Bold Tag in String
 *
 * https://leetcode.com/problems/add-bold-tag-in-string/description/
 *
 * algorithms
 * Medium (38.02%)
 * Total Accepted:    13.3K
 * Total Submissions: 34.9K
 * Testcase Example:  '"abcxyz123"\n["abc","123"]'
 *
 * Given a string s and a list of strings dict, you need to add a closed pair
 * of bold tag <b> and </b> to wrap the substrings in s that exist in dict. If
 * two such substrings overlap, you need to wrap them together by only one pair
 * of closed bold tag. Also, if two substrings wrapped by bold tags are
 * consecutive, you need to combine them.
 *
 * Example 1:
 *
 * Input:
 * s = "abcxyz123"
 * dict = ["abc","123"]
 * Output:
 * "<b>abc</b>xyz<b>123</b>"
 *
 *
 *
 * Example 2:
 *
 * Input:
 * s = "aaabbcc"
 * dict = ["aaa","aab","bc"]
 * Output:
 * "<b>aaabbc</b>c"
 *
 *
 *
 * Note:
 *
 * The given dict won't contain duplicates, and its length won't exceed 100.
 * All the strings in input have length in range [1, 1000].
 *
 *
 */
class Solution {
  vector<pair<int, int>> merge(vector<pair<int, int>> &pairs) {
    vector<pair<int, int>> r;
    sort(pairs.begin(), pairs.end(),
         [](const pair<int, int> &p1, const pair<int, int> &p2) {
           return p1.first < p2.first ||
                  (p1.first == p2.first && p1.second < p2.second);
         });

    for (int i = 0, j = -1; i < pairs.size(); ++i) {
      if (j < 0 || pairs[i].first > r[j].second) {
        r.push_back(pairs[i]);
        j += 1;
      } else {
        r[j].second = max(r[j].second, pairs[i].second);
      }
    }
    return r;
  }

  vector<pair<int, int>> findPairs(const string &s,
                                   const vector<string> &dict) {
    vector<pair<int, int>> res;
    for (auto const &w : dict) {
      auto n = w.size();
      for (int i = 0; (i = s.find(w, i)) != string::npos; ++i) {
        res.push_back({i, i + n});
      }
    }
    return res;
  }

public:
  string addBoldTag(string s, vector<string> &dict) {
    auto ranges = findPairs(s, dict);
    ranges = merge(ranges);
    for (auto it = ranges.rbegin(); it != ranges.rend(); ++it) {
      s.insert(it->second, "</b>");
      s.insert(it->first, "<b>");
    }
    return s;
  }
};
