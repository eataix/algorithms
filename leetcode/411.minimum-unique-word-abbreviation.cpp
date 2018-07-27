#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
 * [411] Minimum Unique Word Abbreviation
 *
 * https://leetcode.com/problems/minimum-unique-word-abbreviation/description/
 *
 * algorithms
 * Hard (33.76%)
 * Total Accepted:    8.1K
 * Total Submissions: 24K
 * Testcase Example:  '"apple"\n["blade"]'
 *
 * A string such as "word" contains the following abbreviations:
 *
 * ["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d",
 * "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
 *
 *
 * Given a target string and a set of strings in a dictionary, find an
 * abbreviation of this target string with the smallest possible length such
 * that it does not conflict with abbreviations of the strings in the
 * dictionary.
 *
 * Each number or letter in the abbreviation is considered length = 1. For
 * example, the abbreviation "a32bc" has length = 4.
 *
 * Note:
 *
 * In the case of multiple answers as shown in the second example below, you
 * may return any one of them.
 * Assume length of target string = m, and dictionary size = n. You may assume
 * that m ≤ 21, n ≤ 1000, and log2(n) + m ≤ 20.
 *
 *
 *
 * Examples:
 *
 * "apple", ["blade"] -> "a4" (because "5" or "4e" conflicts with "blade")
 *
 * "apple", ["plain", "amber", "blade"] -> "1p3" (other valid answers include
 * "ap3", "a3e", "2p2", "3le", "3l1").
 *
 *
 */

class TrieNode {
public:
  vector<TrieNode *> next;
  TrieNode() : next(26, nullptr) {}
};

class Solution {
  TrieNode *build(const vector<string> &dict) {
    auto root = new TrieNode();
    for (auto const &d : dict) {
      auto curr = root;
      for (char ch : d) {
        if (curr->next[ch - 'a'] == nullptr) {
          curr->next[ch - 'a'] = new TrieNode();
        }
        curr = curr->next[ch - 'a'];
      }
    }
    return root;
  }

  void generate_abbrs(vector<string> &abbrs, string &s, string curr, int pos,
                      int len) {
    if (pos == s.size()) {
      if (len == 0) {
        abbrs.push_back(curr);
      }
      return;
    }

    if (len == 0) {
      return;
    }

    if (len == 1) {
      if (pos != s.size()) {
        for (int i = pos; i < s.size(); ++i) {
          curr += '?';
        }
        abbrs.push_back(curr);
      }
      return;
    }

    generate_abbrs(abbrs, s, curr + s[pos], pos + 1, len - 1);
    for (int i = pos + 1; i < s.size(); ++i) {
      curr += '?';
      generate_abbrs(abbrs, s, curr + s[i], i + 1, len - 2);
    }
  }

  bool valid(TrieNode *root, const string &s, int i) {
    if (i == s.size()) {
      return false;
    }

    if (s[i] == '?') {
      for (int j = 0; j < 26; ++j) {
        if (root->next[j] != nullptr && !valid(root->next[j], s, i + 1)) {
          return false;
        }
      }
      return true;
    } else {
      if (root->next[s[i] - 'a'] == nullptr) {
        return true;
      }

      return valid(root->next[s[i] - 'a'], s, i + 1);
    }
  }

  string encode(const string &s) {
    string res;
    int cnt = 0;
    for (char ch : s) {
      if (ch == '?') {
        cnt += 1;
      } else if (cnt == 0) {
        res += ch;
      } else {
        res += to_string(cnt) + ch;
        cnt = 0;
      }
    }

    if (cnt > 0) {
      res += to_string(cnt);
    }

    return res;
  }

public:
  string minAbbreviation(string target, vector<string> dictionary) {
    int n = target.size();
    vector<string> dict;
    for (auto const &d : dictionary) {
      if (d.size() == n) {
        dict.push_back(d);
      }
    }

    auto root = build(dict);

    for (int len = 1; len < n; ++len) {
      vector<string> abbrs;
      generate_abbrs(abbrs, target, "", 0, len);
      for (auto s : abbrs) {
        if (valid(root, s, 0)) {
          return encode(s);
        }
      }
    }
    return target;
  }
};
