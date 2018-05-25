#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
/*
 * [127] Word Ladder
 *
 * https://leetcode.com/problems/word-ladder/description/
 *
 * algorithms
 * Medium (20.11%)
 * Total Accepted:    166.2K
 * Total Submissions: 821.9K
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * Given two words (beginWord and endWord), and a dictionary's word list, find
 * the length of shortest transformation sequence from beginWord to endWord,
 * such that:
 *
 *
 * Only one letter can be changed at a time.
 * Each transformed word must exist in the word list. Note that beginWord is
 * not a transformed word.
 *
 *
 * Note:
 *
 *
 * Return 0 if there is no such transformation sequence.
 * All words have the same length.
 * All words contain only lowercase alphabetic characters.
 * You may assume no duplicates in the word list.
 * You may assume beginWord and endWord are non-empty and are not the same.
 *
 *
 * Example 1:
 *
 *
 * Input:
 * beginWord = "hit",
 * endWord = "cog",
 * wordList = ["hot","dot","dog","lot","log","cog"]
 *
 * Output: 5
 *
 * Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" ->
 * "dog" -> "cog",
 * return its length 5.
 *
 *
 * Example 2:
 *
 *
 * Input:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log"]
 *
 * Output: 0
 *
 * Explanation: The endWord "cog" is not in wordList, therefore no possible
 * transformation.
 *
 *
 *
 *
 *
 */
class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
    unordered_set<string> dict{wordList.begin(), wordList.end()};

    if (dict.find(endWord) == dict.cend()) {
      return 0;
    }

    queue<pair<string, int>> q;
    q.push({beginWord, 1});

    while (!q.empty()) {
      auto kv = q.front();
      q.pop();
      string str{kv.first};
      int level{kv.second};

      if (str == endWord) {
        return level;
      }

      for (int i = 0; i < str.size(); ++i) {
        for (int c = 'a'; c <= 'z'; ++c) {
          if (c == str[i]) {
            continue;
          }
          string newString{str};
          newString[i] = c;
          if (dict.find(newString) != dict.cend()) {
            q.push({newString, level + 1});
            dict.erase(newString);
          }
        }
      }
    }

    return 0;
  }
};

#ifdef DEBUG
int main() {
  string beginWord{"hit"};
  string endWord{"cog"};
  vector<string> wordList{"hot", "dot", "dog", "lot", "log", "cog"};
  Solution sol;

  cout << sol.ladderLength(beginWord, endWord, wordList) << endl;

  string beginWord2{"hit"};
  string endWord2{"cog"};
  vector<string> wordList2{"hot", "dot", "dog", "lot", "log"};
  cout << sol.ladderLength(beginWord2, endWord2, wordList2) << endl;
}
#endif
