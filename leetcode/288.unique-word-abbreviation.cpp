#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
/*
 * [288] Unique Word Abbreviation
 *
 * https://leetcode.com/problems/unique-word-abbreviation/description/
 *
 * algorithms
 * Medium (18.36%)
 * Total Accepted:    34.2K
 * Total Submissions: 186.1K
 * Testcase Example:
 * '["ValidWordAbbr","isUnique","isUnique","isUnique","isUnique"]\n[[["deer","door","cake","card"]],["dear"],["cart"],["cane"],["make"]]'
 *
 * An abbreviation of a word follows the form <first letter><number><last
 * letter>. Below are some examples of word abbreviations:
 *
 *
 * a) it                      --> it    (no abbreviation)
 *
 * ⁠    1
 * ⁠    ↓
 * b) d|o|g                   --> d1g
 *
 * ⁠             1    1  1
 * ⁠    1---5----0----5--8
 * ⁠    ↓   ↓    ↓    ↓  ↓
 * c) i|nternationalizatio|n  --> i18n
 *
 * ⁠             1
 * ⁠    1---5----0
 * ↓   ↓    ↓
 * d) l|ocalizatio|n          --> l10n
 *
 *
 * Assume you have a dictionary and given a word, find whether its abbreviation
 * is unique in the dictionary. A word's abbreviation is unique if no other
 * word from the dictionary has the same abbreviation.
 *
 * Example:
 *
 *
 * Given dictionary = [ "deer", "door", "cake", "card" ]
 *
 * isUnique("dear") -> false
 * isUnique("cart") -> true
 * isUnique("cane") -> false
 * isUnique("make") -> true
 *
 *
 */
class ValidWordAbbr {
  unordered_map<string, string> m;

  string toAbbr(const string &s) {
    auto len = s.size();
    if (len <= 2) {
      return s;
    }
    return s[0] + to_string(len - 2) + s.back();
  }

public:
  ValidWordAbbr(vector<string> dictionary) {
    for (auto const &word : dictionary) {
      auto abbr = toAbbr(word);
      if (m.count(abbr) && m[abbr] != word) {
        m[abbr] = "";
      } else {
        m[abbr] = word;
      }
    }
  }

  bool isUnique(string word) {
    auto abbr = toAbbr(word);
    return !m.count(abbr) || m[abbr] == word;
  }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj.isUnique(word);
 */
