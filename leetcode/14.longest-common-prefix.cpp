#include <algorithm>
#include <string>
#include <vector>
using namespace std;
/*
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (31.60%)
 * Total Accepted:    263.9K
 * Total Submissions: 835.4K
 * Testcase Example:  '[]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 *
 */
class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    if (strs.size() == 0) {
      return "";
    }
    string firstStr = strs[0];
    int minLength = firstStr.length();
    for (string str : strs) {
      if (str.length() < minLength) {
        minLength = str.length();
      }
    }
    int i = 0;
    for (; i < minLength; ++i) {
      bool same = true;
      for (int j = 1; j < strs.size(); ++j) {
        if (strs[j][i] != firstStr[i]) {
          same = false;
          break;
        }
      }
      if (!same) {
        break;
      }
    }
    return firstStr.substr(0, i);
  }
};
