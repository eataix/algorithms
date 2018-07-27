#include <queue>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;
/*
 * [358] Rearrange String k Distance Apart
 *
 * https://leetcode.com/problems/rearrange-string-k-distance-apart/description/
 *
 * algorithms
 * Hard (31.78%)
 * Total Accepted:    15.9K
 * Total Submissions: 50.1K
 * Testcase Example:  '"aabbcc"\n3'
 *
 *
 * Given a non-empty string s and an integer k, rearrange the string such that
 * the same characters are at least distance k from each other.
 *
 *
 * All input strings are given in lowercase letters. If it is not possible to
 * rearrange the string, return an empty string "".
 *
 * Example 1:
 *
 * s = "aabbcc", k = 3
 *
 * Result: "abcabc"
 *
 * The same letters are at least distance 3 from each other.
 *
 *
 *
 * Example 2:
 *
 * s = "aaabc", k = 3
 *
 * Answer: ""
 *
 * It is not possible to rearrange the string.
 *
 *
 *
 * Example 3:
 *
 * s = "aaadbbcc", k = 2
 *
 * Answer: "abacabcd"
 *
 * Another possible answer is: "abcabcda"
 *
 * The same letters are at least distance 2 from each other.
 *
 *
 *
 * Credits:Special thanks to @elmirap for adding this problem and creating all
 * test cases.
 */
class Solution {
public:
  string rearrangeString(string str, int k) {
    if (k == 0) {
      return str;
    }

    int n = str.size();

    string res;
    unordered_map<char, int> dict;
    priority_queue<pair<int, char>> q;

    for (char ch : str) {
      dict[ch] += 1;
    }

    for (auto const &kv : dict) {
      q.push({kv.second, kv.first});
    }

    while (!q.empty()) {
      vector<pair<int, char>> cache;

      int count = min(k, n);

      for (int i = 0; i < count; ++i) {
        if (q.empty()) {
          return "";
        }

        auto kv = q.top();
        q.pop();
        res.push_back(kv.second);
        if (--kv.first > 0) {
          cache.push_back(kv);
        }
        n -= 1;
      }

      for (auto const &kv : cache) {
        q.push(kv);
      }
    }
    return res;
  }
};
