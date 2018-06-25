#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
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
struct TrieNode {
  unordered_map<char, shared_ptr<TrieNode>> next;
  int count;

  TrieNode() : count(0) {}
};

class Solution {
public:
  string longestCommonPrefix(const vector<string> &strs) {
    if (strs.empty() || strs[0].empty()) {
      return "";
    }
    shared_ptr<TrieNode> root = make_shared<TrieNode>();

    for (auto const &str : strs) {
      auto curr = root;
      for (char ch : str) {
        if (!curr->next.count(ch)) {
          curr->next[ch] = make_shared<TrieNode>();
        }
        curr = curr->next[ch];
        curr->count += 1;
      }
    }

    shared_ptr<TrieNode> curr = root;
    string res;
    for (char ch : strs[0]) {
      curr = curr->next[ch];
      if (curr->count != strs.size()) {
        return res;
      } else {
        res += ch;
      }
    }
    return strs[0];
  }

  string longestCommonPrefix2(vector<string> &strs) {
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

#ifdef DEBUG
int main() {
  Solution sol;
  cout << "'" << sol.longestCommonPrefix({"flower", "flow", "flight"}) << "'"
       << endl;
  cout << "'" << sol.longestCommonPrefix({"dog", "racecar", "car"}) << "'"
       << endl;
  cout << "'" << sol.longestCommonPrefix({"a"}) << "'" << endl;
}
#endif
