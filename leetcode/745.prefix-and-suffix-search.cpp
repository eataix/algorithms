#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
/*
 * [746] Prefix and Suffix Search
 *
 * https://leetcode.com/problems/prefix-and-suffix-search/description/
 *
 * algorithms
 * Hard (26.37%)
 * Total Accepted:    6.1K
 * Total Submissions: 23K
 * Testcase Example:  '["WordFilter","f"]\n[[["apple"]], ["a","e"]]'
 *
 *
 * Given many words, words[i] has weight i.
 *
 * Design a class WordFilter that supports one function, WordFilter.f(String
 * prefix, String suffix).
 * It will return the word with given prefix and suffix with maximum weight.
 * If no word exists, return -1.
 *
 *
 * Examples:
 *
 * Input:
 * WordFilter(["apple"])
 * WordFilter.f("a", "e") // returns 0
 * WordFilter.f("b", "") // returns -1
 *
 *
 * Note:
 *
 * words has length in range [1, 15000].
 * For each test case, up to words.length queries WordFilter.f may be made.
 * words[i] has length in range [1, 10].
 * prefix, suffix have lengths in range [0, 10].
 * words[i] and prefix, suffix queries consist of lowercase letters only.
 *
 *
 */

class WordFilter {
  unordered_map<string, int> m;

public:
  WordFilter(vector<string> words) {
    for (int k = 0; k < words.size(); ++k) {
      for (int i = 0; i <= words[k].size(); ++i) {
        for (int j = 0; j <= words[k].size(); ++j) {
          m[words[k].substr(0, i) + "#" +
            words[k].substr(words[k].size() - j)] = k;
        }
      }
    }
  }

  int f(string prefix, string suffix) {
    return (m.count(prefix + "#" + suffix)) ? m[prefix + "#" + suffix] : -1;
  }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter obj = new WordFilter(words);
 * int param_1 = obj.f(prefix,suffix);
 */
