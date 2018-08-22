#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
/*
 * [249] Group Shifted Strings
 *
 * https://leetcode.com/problems/group-shifted-strings/description/
 *
 * algorithms
 * Medium (45.30%)
 * Total Accepted:    37.1K
 * Total Submissions: 82K
 * Testcase Example:  '["abc","bcd","acef","xyz","az","ba","a","z"]'
 *
 * Given a string, we can "shift" each of its letter to its successive letter,
 * for example: "abc" -> "bcd". We can keep "shifting" which forms the
 * sequence:
 *
 *
 * "abc" -> "bcd" -> ... -> "xyz"
 *
 * Given a list of strings which contains only lowercase alphabets, group all
 * strings that belong to the same shifting sequence.
 *
 * Example:
 *
 *
 * Input: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"],
 * Output:
 * [
 * ⁠ ["abc","bcd","xyz"],
 * ⁠ ["az","ba"],
 * ⁠ ["acef"],
 * ⁠ ["a","z"]
 * ]
 *
 *
 */
static inline string shift(const string &s) {
  string t;

  for (int i = 1; i < s.size(); ++i) {
    int diff = s[i] - s[i - 1];
    if (diff < 0) {
      diff += 26;
    }
    t += 'a' + diff + ',';
  }
  return t;
}

class Solution {

public:
  vector<vector<string>> groupStrings(const vector<string> &strings) {
    unordered_map<string, vector<string>> m;
    for (auto const &s : strings) {
      m[shift(s)].push_back(s);
    }

    vector<vector<string>> groups;
    for (auto const &kv : m) {
      groups.push_back(kv.second);
    }
    return groups;
  }
};
