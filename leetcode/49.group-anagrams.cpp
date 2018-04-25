#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
/*
 * [49] Group Anagrams
 *
 * https://leetcode.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (38.53%)
 * Total Accepted:    195.2K
 * Total Submissions: 506.6K
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * Given an array of strings, group anagrams together.
 *
 * Example:
 *
 *
 * Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
 * Output:
 * [
 * ⁠ ["ate","eat","tea"],
 * ⁠ ["nat","tan"],
 * ⁠ ["bat"]
 * ]
 *
 * Note:
 *
 *
 * All inputs will be in lowercase.
 * The order of your output does not matter.
 *
 *
 */
class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    unordered_map<string, vector<string>> mapNewStringsToOldOnes;

    for (string str : strs) {
      string str2{str};
      sort(str2.begin(), str2.end());
      mapNewStringsToOldOnes[str2].push_back(str);
    }

    vector<vector<string>> res;
    for (auto kv : mapNewStringsToOldOnes) {
      vector<string> r;
      for (auto oldStr : kv.second) {
        r.push_back(oldStr);
      }
      res.push_back(r);
    }
    return res;
  }
};

#ifdef DEBUG
int main() {
  Solution sol;
  vector<string> s{"eat", "tea", "tan", "ate", "nat", "bat"};
  sol.groupAnagrams(s);
}
#endif
