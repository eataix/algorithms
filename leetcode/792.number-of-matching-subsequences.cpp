#include <string>
#include <vector>
using namespace std;
/*
 * [808] Number of Matching Subsequences
 *
 * https://leetcode.com/problems/number-of-matching-subsequences/description/
 *
 * algorithms
 * Medium (36.85%)
 * Total Accepted:    8.2K
 * Total Submissions: 22.2K
 * Testcase Example:  '"abcde"\n["a","bb","acd","ace"]'
 *
 * Given string S and a dictionary of words words, find the number of words[i]
 * that is a subsequence of S.
 *
 *
 * Example :
 * Input:
 * S = "abcde"
 * words = ["a", "bb", "acd", "ace"]
 * Output: 3
 * Explanation: There are three words in words that are a subsequence of S:
 * "a", "acd", "ace".
 *
 *
 * Note:
 *
 *
 * All words in words and S will only consists of lowercase letters.
 * The length of S will be in the range of [1, 50000].
 * The length of words will be in the range of [1, 5000].
 * The length of words[i] will be in the range of [1, 50].
 *
 */
class Solution {
  bool isSubsequence(string s, string t) {
    auto si = s.cbegin();
    auto ti = t.cbegin();

    for (; si != s.cend() && ti != t.cend(); ++ti) {
      if (*si == *ti) {
        si += 1;
      }
    }

    return si == s.cend();
  }

public:
  int numMatchingSubseq(string S, vector<string> &words) {
    vector<vector<pair<int, int>>> waiting(128, vector<pair<int, int>>());
    for (int i = 0; i < words.size(); ++i) {
      waiting[words[i][0]].push_back({i, 1});
    }

    for (char c : S) {
      auto advance = waiting[c];
      waiting[c].clear();
      for (auto it : advance) {
        waiting[words[it.first][it.second++]].push_back(it);
      }
    }
    return waiting[0].size();
  }

  int numMatchingSubseq2(string S, vector<string> &words) {
    int count = 0;
    for (auto const &word : words) {
      if (isSubsequence(word, S)) {
        count += 1;
      }
    }
    return count;
  }
};
