#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class TrieNode {
public:
  char ch;
  int count;
  unordered_map<char, shared_ptr<TrieNode>> children;
  TrieNode(char c) : ch(c), count(0) {}
};

class Solution {
public:
  vector<string> wordsAbbreviation(vector<string> &dict) {
    unordered_map<string, vector<string>> groups;
    unordered_map<string, string> result;

    for (const auto &word : dict) {
      string a = word.front() + to_string(word.size() - 2) + word.back();
      if (a.size() >= word.size()) {
        a = word;
      }

      groups[a].push_back(word);
      result[word] = a;
    }

    for (const auto &kv : groups) {
      if (kv.second.size() == 1) {
        continue;
      }
      shared_ptr<TrieNode> root = make_shared<TrieNode>(kv.first[0]);

      for (const string &s : kv.second) {
        shared_ptr<TrieNode> curr = root;
        for (int i = 0; i < s.size(); ++i) {
          curr->count += 1;
          if (i < s.size() - 1) {
            // Not last
            char nextChar = s[i + 1];
            if (curr->children.find(nextChar) == curr->children.cend()) {
              curr->children[nextChar] = make_shared<TrieNode>(nextChar);
            }
            curr = curr->children[nextChar];
          }
        }
      }

      for (const string &s : kv.second) {
        shared_ptr<TrieNode> curr = root;
        for (int i = 0; i < s.size(); ++i) {
          if (curr->count == 1) {
            string a =
                s.substr(0, i + 1) + to_string(s.size() - 2 - i) + s.back();
            if (a.size() >= s.size()) {
              a = s;
            }

            result[s] = a;
            break;
          }

          if (i < s.size() - 1) {
            // Not last
            char nextChar = s[i + 1];
            curr = curr->children[nextChar];
          }
        }
      }
    }

    vector<string> res;
    for (const auto &str : dict) {
      res.push_back(result[str]);
    }
    return res;
  }
};

#ifdef DEBUG
int main() {
  vector<string> s{"like",     "god",       "internal", "me",       "internet",
                   "interval", "intension", "face",     "intrusion"};
  Solution sol;
  sol.wordsAbbreviation(s);
}
#endif
