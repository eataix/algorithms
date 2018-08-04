#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
/*
 * [211] Add and Search Word - Data structure design
 *
 * https://leetcode.com/problems/add-and-search-word-data-structure-design/description/
 *
 * algorithms
 * Medium (26.38%)
 * Total Accepted:    82.7K
 * Total Submissions: 313.6K
 * Testcase Example:
 * '["WordDictionary","addWord","addWord","addWord","search","search","search","search"]\n[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]'
 *
 * Design a data structure that supports the following two operations:
 *
 *
 * void addWord(word)
 * bool search(word)
 *
 *
 * search(word) can search a literal word or a regular expression string
 * containing only letters a-z or .. A . means it can represent any one
 * letter.
 *
 * Example:
 *
 *
 * addWord("bad")
 * addWord("dad")
 * addWord("mad")
 * search("pad") -> false
 * search("bad") -> true
 * search(".ad") -> true
 * search("b..") -> true
 *
 *
 * Note:
 * You may assume that all words are consist of lowercase letters a-z.
 *
 */
class TrieNode {
public:
  unordered_map<char, vector<TrieNode *>> children;
  bool isEnd;
  TrieNode() : isEnd(false) {}
};

class WordDictionary {
  TrieNode *root;

public:
  /** Initialize your data structure here. */
  WordDictionary() { root = new TrieNode(); }

  /** Adds a word into the data structure. */
  void addWord(string word) {
    auto curr = root;

    for (char ch : word) {
      if (curr->children[ch].empty()) {
        auto newNode = new TrieNode();
        curr->children[ch].push_back(newNode);
        curr->children['.'].push_back(newNode);
      }
      curr = curr->children[ch][0];
    }

    curr->isEnd = true;
  }

  /** Returns if the word is in the data structure. A word could contain the dot
   * character '.' to represent any one letter. */
  bool search(string word) { return search(word, root, 0); }

  bool search(string word, TrieNode *node, int idx) {
    if (idx == word.size()) {
      return node != nullptr && node->isEnd;
    }

    char ch = word[idx];
    if (!node->children.count(ch)) {
      return false;
    }

    for (auto next : node->children[ch]) {
      if (search(word, next, idx + 1)) {
        return true;
      }
    }
    return false;
  }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
