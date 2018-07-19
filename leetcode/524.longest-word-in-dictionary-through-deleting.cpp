#include <string>
#include <vector>
using namespace std;
/*
 * [524] Longest Word in Dictionary through Deleting
 *
 * https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/description/
 *
 * algorithms
 * Medium (43.38%)
 * Total Accepted:    25.2K
 * Total Submissions: 58.1K
 * Testcase Example:  '"abpcplea"\n["ale","apple","monkey","plea"]'
 *
 *
 * Given a string and a string dictionary, find the longest string in the
 * dictionary that can be formed by deleting some characters of the given
 * string. If there are more than one possible results, return the longest word
 * with the smallest lexicographical order. If there is no possible result,
 * return the empty string.
 *
 * Example 1:
 *
 * Input:
 * s = "abpcplea", d = ["ale","apple","monkey","plea"]
 *
 * Output:
 * "apple"
 *
 *
 *
 *
 * Example 2:
 *
 * Input:
 * s = "abpcplea", d = ["a","b","c"]
 *
 * Output:
 * "a"
 *
 *
 *
 * Note:
 *
 * All the strings in the input will only contain lower-case letters.
 * The size of the dictionary won't exceed 1,000.
 * The length of all the strings in the input won't exceed 1,000.
 *
 *
 */
class Solution {
  bool isSubsequence(const string &str1, const string &str2) {
    int j = 0;
    for (int i = 0; i < str2.size() && j < str1.size(); ++i) {
      if (str1[j] == str2[i]) {
        j += 1;
      }
    }

    return j == str1.size();
  }

public:
  string findLongestWord(string s, vector<string> &d) {
    string maxStr;

    for (auto const &word : d) {
      if (isSubsequence(word, s)) {
        if (word.size() > maxStr.size() ||
            (word.size() == maxStr.size() && word < maxStr)) {
          maxStr = word;
        }
      }
    }
    return maxStr;
  }
};
