#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
/*
 * [140] Word Break II
 *
 * https://leetcode.com/problems/word-break-ii/description/
 *
 * algorithms
 * Hard (24.60%)
 * Total Accepted:    115.4K
 * Total Submissions: 467.2K
 * Testcase Example:  '"catsanddog"\n["cat","cats","and","sand","dog"]'
 *
 * Given a non-empty string s and a dictionary wordDict containing a list of
 * non-empty words, add spaces in s to construct a sentence where each word is
 * a valid dictionary word. Return all such possible sentences.
 *
 * Note:
 *
 *
 * The same word in the dictionary may be reused multiple times in the
 * segmentation.
 * You may assume the dictionary does not contain duplicate words.
 *
 *
 * Example 1:
 *
 *
 * Input:
 * s = "catsanddog"
 * wordDict = ["cat", "cats", "and", "sand", "dog"]
 * Output:
 * [
 * "cats and dog",
 * "cat sand dog"
 * ]
 *
 *
 * Example 2:
 *
 *
 * Input:
 * s = "pineapplepenapple"
 * wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
 * Output:
 * [
 * "pine apple pen apple",
 * "pineapple pen apple",
 * "pine applepen apple"
 * ]
 * Explanation: Note that you are allowed to reuse a dictionary word.
 *
 *
 * Example 3:
 *
 *
 * Input:
 * s = "catsandog"
 * wordDict = ["cats", "dog", "sand", "and", "cat"]
 * Output:
 * []
 *
 */
class Solution {
public:
  vector<string> wordBreak(const string &s, const vector<string> &wordDict) {
    unordered_map<string, vector<string>> m;
    return wordBreakRecursive(s, wordDict, m);
  }
  vector<string> wordBreakRecursive(const string &s,
                                    const vector<string> &wordDict,
                                    unordered_map<string, vector<string>> &m) {
    if (m.find(s) != m.cend()) {
      return m[s];
    }
    if (s.empty()) {
      return {""};
    }
    vector<string> res;
    for (const string &word : wordDict) {
      if (s.substr(0, word.size()) != word) {
        continue;
      }
      vector<string> rem =
          wordBreakRecursive(s.substr(word.size()), wordDict, m);
      for (const string &str : rem) {
        res.push_back(word + (str.empty() ? "" : " ") + str);
      }
    }
    return m[s] = res;
  }
};
