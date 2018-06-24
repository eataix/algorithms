#include <memory>
#include <string>
#include <vector>
using namespace std;

struct TrieNode {
  unordered_map<char, shared_ptr<TrieNode>> children;
  int count;

  TrieNode() : count(0) {}
};

class Solution {
  string abbrev(const string &str, int i) {
    string res = str.substr(0, i);
    int len = str.size() - i - 1;
    res += to_string(len);
    res += str.back();

    return res.size() < str.size() ? res : str;
  }

public:
  /**
   * @param dict: an array of n distinct non-empty strings
   * @return: an array of minimal possible abbreviations for every word
   */
  vector<string> wordsAbbreviation(vector<string> &dict) {
    unordered_map<string, vector<string>> groups;

    for (auto const &word : dict) {
      string aWord = abbrev(word, 1);
      groups[aWord].push_back(word);
    }

    unordered_map<string, string> res;
    for (auto group : groups) {
      auto aWord = group.first;
      auto words = group.second;

      if (words.size() == 1) {
        res[words[0]] = aWord;
        continue;
      }

      shared_ptr<TrieNode> root = make_shared<TrieNode>();
      for (string word : words) {
        auto curr = root;
        for (char ch : word) {
          if (!curr->children.count(ch)) {
            curr->children[ch] = make_shared<TrieNode>();
          }
          curr = curr->children[ch];
          curr->count += 1;
        }
      }

      for (string word : words) {
        auto curr = root;
        for (int i = 0; i < word.size(); ++i) {
          char ch = word[i];
          curr = curr->children[ch];
          if (curr->count == 1) {
            res[word] = abbrev(word, i + 1);
            break;
          }
        }
      }
    }
    vector<string> ret;
    for (auto const &str : dict) {
      ret.push_back(res[str]);
    }
    return ret;
  }
};
