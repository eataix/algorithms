#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class IndexedWord {
public:
  string word;
  int index;
  IndexedWord(string w, int i) : word(w), index(i){};
};

class TrieNode {
public:
  unordered_map<char, shared_ptr<TrieNode>> children;
  int count;
  TrieNode() : count(0) {}
};

class Solution {
private:
  string abbrev(string word, int i) {
    int N = word.size();
    if (N - i <= 3) {
      return word;
    } else {
      return word.substr(0, i + 1) + to_string(N - i - 2) + word[N - 1];
    }
  }

public:
  vector<string> wordsAbbreviation(vector<string> &dict) {
    unordered_map<string, vector<IndexedWord>> groups;
    vector<string> res(dict.size());

    int index = 0;
    for (const auto &word : dict) {
      string ab = abbrev(word, 0);
      groups[ab].push_back(IndexedWord(word, index));
      index += 1;
    }

    for (const auto &kv : groups) {
      const vector<IndexedWord> &group = kv.second;
      auto trie = make_shared<TrieNode>();
      for (IndexedWord iw : group) {
        auto curr = trie;

        for (char letter : iw.word.substr(1)) {
          if (curr->children.find(letter) == curr->children.cend()) {
            curr->children[letter] = make_shared<TrieNode>();
          }
          curr->count += 1;
          curr = curr->children[letter];
        }
      }

      for (IndexedWord iw : group) {
        auto curr = trie;
        int i = 1;
        for (char letter : iw.word.substr(1)) {
          if (curr->count == 1) {
            break;
          }
          curr = curr->children[letter];
          i += 1;
        }
        res[iw.index] = abbrev(iw.word, i - 1);
      }
    }

    return res;
  }
};

#ifdef DEBUG
int main() {
  vector<string> v = {"like",      "god",      "internal",
                      "me",        "internet", "interval",
                      "intension", "face",     "intrusion"};
  Solution sol;
  sol.wordsAbbreviation(v);
}
#endif
