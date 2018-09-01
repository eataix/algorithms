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
public:
  int numMatchingSubseq(string S, vector<string> &words) {
    vector<vector<pair<string::const_iterator, string::const_iterator>>>
        waiting(128);

    for (auto const &word : words) {
      waiting[word[0]].push_back({word.cbegin(), word.cend()});
    }
    int res = 0;
    for (char ch : S) {
      auto advance = waiting[ch];
      waiting[ch].clear();
      for (auto p : advance) {
        auto it = p.first;
        auto iEnd = p.second;
        if (it + 1 == iEnd) {
          res += 1;
        } else {
          waiting[*(it + 1)].push_back({it + 1, iEnd});
        }
      }
    }
    return res;
  }
};
