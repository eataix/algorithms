#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
/*
 * [676] Implement Magic Dictionary
 *
 * https://leetcode.com/problems/implement-magic-dictionary/description/
 *
 * algorithms
 * Medium (49.08%)
 * Total Accepted:    14.2K
 * Total Submissions: 29K
 * Testcase Example:  '["MagicDictionary", "buildDict", "search", "search",
 * "search", "search"]\n[[], [["hello","leetcode"]], ["hello"], ["hhllo"],
 * ["hell"], ["leetcoded"]]'
 *
 *
 * Implement a magic directory with buildDict, and search methods.
 *
 *
 *
 * For the method buildDict, you'll be given a list of non-repetitive words to
 * build a dictionary.
 *
 *
 *
 * For the method search, you'll be given a word, and judge whether if you
 * modify exactly one character into another character in this word, the
 * modified word is in the dictionary you just built.
 *
 *
 * Example 1:
 *
 * Input: buildDict(["hello", "leetcode"]), Output: Null
 * Input: search("hello"), Output: False
 * Input: search("hhllo"), Output: True
 * Input: search("hell"), Output: False
 * Input: search("leetcoded"), Output: False
 *
 *
 *
 * Note:
 *
 * You may assume that all the inputs are consist of lowercase letters a-z.
 * For contest purpose, the test data is rather small by now. You could think
 * about highly efficient algorithm after the contest.
 * Please remember to RESET your class variables declared in class
 * MagicDictionary, as static/class variables are persisted across multiple
 * test cases. Please see here for more details.
 *
 *
 */
class MagicDictionary {
  unordered_map<int, vector<string>> m;

public:
  /** Initialize your data structure here. */
  MagicDictionary() {}

  /** Build a dictionary through a list of words */
  void buildDict(vector<string> dict) {
    m.clear();
    for (auto const &word : dict) {
      m[word.size()].push_back(word);
    }
  }

  int countDifference(const string &s1, const string &s2) {
    int cnt = 0;
    for (int i = 0; i < s1.size(); ++i) {
      if (s1[i] != s2[i]) {
        cnt += 1;
      }

      if (cnt >= 2) {
        break;
      }
    }
    return cnt;
  }

  /** Returns if there is any word in the trie that equals to the given word
   * after modifying exactly one character */
  bool search(string word) {
    if (m.count(word.size())) {
      for (auto const &w : m[word.size()]) {
        if (countDifference(word, w) == 1) {
          return true;
        }
      }
    }
    return false;
  }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */
