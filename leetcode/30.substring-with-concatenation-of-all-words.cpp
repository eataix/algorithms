#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
/*
 * [30] Substring with Concatenation of All Words
 *
 * https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/
 *
 * algorithms
 * Hard (22.33%)
 * Total Accepted:    102.9K
 * Total Submissions: 460.9K
 * Testcase Example:  '"barfoothefoobarman"\n["foo","bar"]'
 *
 * You are given a string, s, and a list of words, words, that are all of the
 * same length. Find all starting indices of substring(s) in s that is a
 * concatenation of each word in words exactly once and without any intervening
 * characters.
 *
 * Example 1:
 *
 *
 * Input:
 * ⁠ s = "barfoothefoobarman",
 * ⁠ words = ["foo","bar"]
 * Output: [0,9]
 * Explanation: Substrings starting at index 0 and 9 are "barfoor" and "foobar"
 * respectively.
 * The output order does not matter, returning [9,0] is fine too.
 *
 *
 * Example 2:
 *
 *
 * Input:
 * ⁠ s = "wordgoodstudentgoodword",
 * ⁠ words = ["word","student"]
 * Output: []
 *
 *
 */

class Solution {
public:
  vector<int> findSubstring(string s, vector<string> &words) {
    if (s.empty() || words.empty()) {
      return {};
    }
    unordered_map<string, int> counts;
    for (string word : words) {
      counts[word]++;
    }
    int n = s.length(), num = words.size(), len = words[0].length();
    vector<int> indexes;
    for (int i = 0; i < n - num * len + 1; i++) {
      unordered_map<string, int> seen;
      int j = 0;
      for (; j < num; j++) {
        string word = s.substr(i + j * len, len);
        if (counts.count(word)) {
          seen[word]++;
          if (seen[word] > counts[word]) {
            break;
          }
        } else {
          break;
        }
      }
      if (j == num) {
        indexes.push_back(i);
      }
    }
    return indexes;
  }
};
