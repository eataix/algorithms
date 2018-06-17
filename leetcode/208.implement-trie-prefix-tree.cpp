#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

/*
 * [208] Implement Trie (Prefix Tree)
 *
 * https://leetcode.com/problems/implement-trie-prefix-tree/description/
 *
 * algorithms
 * Medium (31.05%)
 * Total Accepted:    111.2K
 * Total Submissions: 357.9K
 * Testcase Example:  '["Trie","search"]\n[[],["a"]]'
 *
 *
 * Implement a trie with insert, search, and startsWith methods.
 *
 *
 *
 * Note:
 * You may assume that all inputs are consist of lowercase letters a-z.
 *
 */
class Trie {
  class TrieNode {
  public:
    unordered_map<char, TrieNode *> next;
    bool endHere;

    TrieNode() : endHere(false) {}
  };

  TrieNode root;

public:
  /** Initialize your data structure here. */
  Trie() {}

  /** Inserts a word into the trie. */
  void insert(string word) {
    TrieNode *curr = &root;

    for (char ch : word) {
      if (curr->next.find(ch) == curr->next.cend()) {
        curr->next[ch] = new TrieNode();
      }
      curr = curr->next[ch];
    }

    curr->endHere = true;
  }

  /** Returns if the word is in the trie. */
  bool search(string word) {
    TrieNode *curr = &root;

    for (char ch : word) {
      if (curr->next.find(ch) == curr->next.cend()) {
        return false;
      }
      curr = curr->next[ch];
    }

    return curr->endHere;
  }

  /** Returns if there is any word in the trie that starts with the given
   * prefix. */
  bool startsWith(string prefix) {
    TrieNode *curr = &root;

    for (char ch : prefix) {
      if (curr->next.find(ch) == curr->next.cend()) {
        return false;
      }
      curr = curr->next[ch];
    }

    return true;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */

#ifdef DEBUG
int main() {
  Trie trie;
  trie.insert("apple");
  cout << trie.search("apple") << endl;   // returns true
  cout << trie.search("app") << endl;     // returns false
  cout << trie.startsWith("app") << endl; // returns true
  trie.insert("app");
  cout << trie.search("app") << endl; // returns true
}
#endif
