#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
/*
 * [126] Word Ladder II
 *
 * https://leetcode.com/problems/word-ladder-ii/description/
 *
 * algorithms
 * Hard (15.01%)
 * Total Accepted:    84.6K
 * Total Submissions: 562.5K
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * Given two words (beginWord and endWord), and a dictionary's word list, find
 * all shortest transformation sequence(s) from beginWord to endWord, such
 * that:
 *
 *
 * Only one letter can be changed at a time
 * Each transformed word must exist in the word list. Note that beginWord is
 * not a transformed word.
 *
 *
 * Note:
 *
 *
 * Return an empty list if there is no such transformation sequence.
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
 * Output:
 * [
 * ⁠ ["hit","hot","dot","dog","cog"],
 * ["hit","hot","lot","log","cog"]
 * ]
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
 * Output: []
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
  vector<vector<string>> findLadders(string beginWord, string endWord,
                                     vector<string> &wordList) {
    vector<vector<string>> res;
    queue<vector<string>> paths;
    unordered_set<string> dict{wordList.cbegin(), wordList.cend()};

    paths.push({beginWord});
    int level = 1;
    int minLevel = numeric_limits<int>::max();

    unordered_set<string> visited;

    while (!paths.empty()) {
      auto path = paths.front();
      paths.pop();

      if (path.size() > level) {
        for (string w : visited) {
          dict.erase(w);
        }
        visited.clear();
        if (path.size() > minLevel) {
          break;
        } else {
          level = path.size();
        }
      }

      string last = path.back();
      for (int i = 0; i < last.size(); ++i) {
        string newStr = last;

        for (char c = 'a'; c <= 'z'; ++c) {
          newStr[i] = c;
          if (dict.count(newStr)) {
            vector<string> newPath = path;
            newPath.push_back(newStr);
            visited.insert(newStr);
            if (newStr == endWord) {
              minLevel = level;
              res.push_back(newPath);
            } else {
              paths.push(newPath);
            }
          }
        }
      }
    }
    return res;
  }
};

class Solution {
  int bfs(string beginWord, string endWord, unordered_set<string> wordDict) {
    if (!wordDict.count(endWord)) {
      return -1;
    }
    queue<pair<string, int>> q;
    q.push({beginWord, 0});

    while (!q.empty()) {
      auto front = q.front();
      if (front.first == endWord) {
        return front.second;
      }
      q.pop();

      auto str = front.first;
      for (int i = 0; i < str.size(); ++i) {
        string newStr{str};
        for (char ch = 'a'; ch <= 'z'; ++ch) {
          if (str[i] != ch) {
            newStr[i] = ch;

            if (wordDict.count(newStr)) {
              q.push({newStr, front.second + 1});
              wordDict.erase(newStr);
            }
          }
        }
      }
    }
    return -1;
  }

  void dfs(string beginWord, string endWord, unordered_set<string> &wordDict,
           int level, int maxLevel, vector<string> &out,
           vector<vector<string>> &res) {
    if (level > maxLevel) {
      return;
    }
    if (beginWord == endWord) {
      res.push_back(out);
      return;
    }

    for (int i = 0; i < beginWord.size(); ++i) {
      string newStr{beginWord};
      for (char ch = 'a'; ch <= 'z'; ++ch) {
        if (beginWord[i] != ch) {
          newStr[i] = ch;

          if (wordDict.count(newStr)) {
            out.push_back(newStr);
            dfs(newStr, endWord, wordDict, level + 1, maxLevel, out, res);
            out.pop_back();
          }
        }
      }
    }
  }

public:
  vector<vector<string>> findLadders(string beginWord, string endWord,
                                     vector<string> wordList) {
    unordered_set<string> wordDict{wordList.cbegin(), wordList.cend()};
    auto depth = bfs(beginWord, endWord, wordDict);
#ifdef DEBUG
    cout << "depth: " << depth << endl;
#endif
    if (depth == -1) {
      return {};
    }
    vector<vector<string>> res;
    vector<string> out{beginWord};
    dfs(beginWord, endWord, wordDict, 0, depth, out, res);
#ifdef DEBUG
    for (auto r : res) {
      for (auto s : r) {
        cout << s << "  ";
      }
      cout << endl;
    }
#endif
    return res;
  }
};

#ifdef DEBUG
int main() {
  Solution sol;
  sol.findLadders("hit", "cog", {"hot", "dot", "dog", "lot", "log", "cog"});
}
#endif
