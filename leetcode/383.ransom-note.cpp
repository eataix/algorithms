#include <string>
#include <unordered_map>
using namespace std;
/*
 * [383] Ransom Note
 *
 * https://leetcode.com/problems/ransom-note/description/
 *
 * algorithms
 * Easy (47.81%)
 * Total Accepted:    78.1K
 * Total Submissions: 163.3K
 * Testcase Example:  '"a"\n"b"'
 *
 *
 * Given an arbitrary ransom note string and another string containing letters
 * from all the magazines, write a function that will return true if the
 * ransom
 * note can be constructed from the magazines ; otherwise, it will return
 * false.
 *
 *
 * Each letter in the magazine string can only be used once in your ransom
 * note.
 *
 *
 * Note:
 * You may assume that both strings contain only lowercase letters.
 *
 *
 *
 * canConstruct("a", "b") -> false
 * canConstruct("aa", "ab") -> false
 * canConstruct("aa", "aab") -> true
 *
 *
 */
class Solution {
public:
  bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char, int> m;
    for (char ch : magazine) {
      m[ch] += 1;
    }

    for (char ch : ransomNote) {
      m[ch] -= 1;
    }

    for (auto kv : m) {
      if (kv.second < 0) {
        return false;
      }
    }
    return true;
  }
};

#ifdef DEBUG
#include <iostream>
int main() {
  Solution sol;
  cout << sol.canConstruct("a", "b") << endl;
  cout << sol.canConstruct("aa", "ab") << endl;
  cout << sol.canConstruct("aa", "aab") << endl;
}
#endif
