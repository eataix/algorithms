#include <algorithm>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
/*
 * [720] Longest Word in Dictionary
 *
 * https://leetcode.com/problems/longest-word-in-dictionary/description/
 *
 * algorithms
 * Easy (41.69%)
 * Total Accepted:    17.7K
 * Total Submissions: 42.4K
 * Testcase Example:  '["w","wo","wor","worl","world"]'
 *
 * Given a list of strings words representing an English Dictionary, find the
 * longest word in words that can be built one character at a time by other
 * words in words.  If there is more than one possible answer, return the
 * longest word with the smallest lexicographical order.  If there is no
 * answer, return the empty string.
 *
 * Example 1:
 *
 * Input:
 * words = ["w","wo","wor","worl", "world"]
 * Output: "world"
 * Explanation:
 * The word "world" can be built one character at a time by "w", "wo", "wor",
 * and "worl".
 *
 *
 *
 * Example 2:
 *
 * Input:
 * words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
 * Output: "apple"
 * Explanation:
 * Both "apply" and "apple" can be built from other words in the dictionary.
 * However, "apple" is lexicographically smaller than "apply".
 *
 *
 *
 * Note:
 * All the strings in the input will only contain lowercase letters.
 * The length of words will be in the range [1, 1000].
 * The length of words[i] will be in the range [1, 30].
 *
 */
class Solution {

public:
  string longestWord(vector<string> &words) {
    unordered_set<string> dict{words.cbegin(), words.cend()};

    sort(words.begin(), words.end(), [](auto const &str1, auto const &str2) {
      return str1.size() > str2.size() ||
             (str1.size() == str2.size() && str1 < str2);
    });

    for (auto const &word : words) {
      int prefixLen = 1;
      for (; prefixLen < word.size(); ++prefixLen) {
        if (!dict.count(word.substr(0, prefixLen))) {
          break;
        }
      }
      if (prefixLen == word.size()) {
        return word;
      }
    }
    return "";
  }
};
