#include <set>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
/*
 * [336] Palindrome Pairs
 *
 * https://leetcode.com/problems/palindrome-pairs/description/
 *
 * algorithms
 * Hard (27.30%)
 * Total Accepted:    39.6K
 * Total Submissions: 144.9K
 * Testcase Example:  '["abcd","dcba","lls","s","sssll"]'
 *
 *
 * ⁠   Given a list of unique words, find all pairs of distinct indices (i, j)
 * in the given list, so that the concatenation of the two words, i.e. words[i]
 * + words[j] is a palindrome.
 *
 *
 *
 * ⁠   Example 1:
 * ⁠   Given words = ["bat", "tab", "cat"]
 * ⁠   Return [[0, 1], [1, 0]]
 * ⁠   The palindromes are ["battab", "tabbat"]
 *
 *
 * ⁠   Example 2:
 * ⁠   Given words = ["abcd", "dcba", "lls", "s", "sssll"]
 * ⁠   Return [[0, 1], [1, 0], [3, 2], [2, 4]]
 * ⁠   The palindromes are ["dcbaabcd", "abcddcba", "slls", "llssssll"]
 *
 *
 * Credits:Special thanks to @dietpepsi for adding this problem and creating
 * all test cases.
 */
class Solution {
private:
  bool isPal(const string &s, int left, int right) {
    while (left < right) {
      if (s[left++] != s[right--]) {
        return false;
      }
    }
    return true;
  }

public:
  vector<vector<int>> palindromePairs(vector<string> &words) {
    vector<vector<int>> res;
    unordered_map<string, int> m;
    set<int> s;
    if (words.size() <= 1) {
      return res;
    }

    for (int i = 0; i < words.size(); ++i) {
      m[words[i]] = i;
      s.insert(words[i].size());
    }

    for (int i = 0; i < words.size(); ++i) {
      string curr = words[i];
      int len = curr.size();

      reverse(begin(curr), end(curr));

      if (m.find(curr) != cend(m) && m[curr] != i) {
        res.push_back({i, m[curr]});
      }

      auto end = s.find(len);

      for (auto it = begin(s); it != end; ++it) {
        int l = *it;

        string left = curr.substr(len - l);

        if (isPal(curr, 0, len - l - 1) && m.find(left) != cend(m)) {
          res.push_back({i, m[left]});
        }

        string right = curr.substr(0, l);
        if (isPal(curr, l, len - 1) && m.find(right) != cend(m)) {
          res.push_back({m[right], i});
        }
      }
    }
    return res;
  }
};
