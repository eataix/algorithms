#include <string>
#include <vector>
using namespace std;
/*
 * [567] Permutation in String
 *
 * https://leetcode.com/problems/permutation-in-string/description/
 *
 * algorithms
 * Medium (36.29%)
 * Total Accepted:    25.3K
 * Total Submissions: 69.7K
 * Testcase Example:  '"ab"\n"eidbaooo"'
 *
 * Given two strings s1 and s2, write a function to return true if s2 contains
 * the permutation of s1. In other words, one of the first string's
 * permutations is the substring of the second string.
 *
 * Example 1:
 *
 * Input:s1 = "ab" s2 = "eidbaooo"
 * Output:True
 * Explanation: s2 contains one permutation of s1 ("ba").
 *
 *
 *
 * Example 2:
 *
 * Input:s1= "ab" s2 = "eidboaoo"
 * Output: False
 *
 *
 *
 * Note:
 *
 * The input strings only contain lower case letters.
 * The length of both given strings is in range [1, 10,000].
 *
 *
 */
class Solution {
  bool allZero(const vector<int> &count) {
    for (int c : count) {
      if (c != 0) {
        return false;
      }
    }
    return true;
  }

public:
  bool checkInclusion(string s1, string s2) {
    int len1 = s1.size();
    int len2 = s2.size();
    if (len1 > len2) {
      return false;
    }

    vector<int> counts(26, 0);

    for (int i = 0; i < len1; ++i) {
      counts[s1[i] - 'a'] += 1;
      counts[s2[i] - 'a'] -= 1;
    }

    if (allZero(counts)) {
      return true;
    }

    for (int i = len1; i < len2; ++i) {
      counts[s2[i] - 'a'] -= 1;
      counts[s2[i - len1] - 'a'] += 1;
      if (allZero(counts)) {
        return true;
      }
    }
    return false;
  }
};
