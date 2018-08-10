#include <string>
#include <vector>
using namespace std;
/*
 * [425] Word Squares
 *
 * https://leetcode.com/problems/word-squares/description/
 *
 * algorithms
 * Hard (42.92%)
 * Total Accepted:    17.1K
 * Total Submissions: 39.7K
 * Testcase Example:  '["area","lead","wall","lady","ball"]'
 *
 * Given a set of words (without duplicates), find all word squares you can
 * build from them.
 *
 * A sequence of words forms a valid word square if the kth row and column read
 * the exact same string, where 0 ≤ k < max(numRows, numColumns).
 *
 * For example, the word sequence ["ball","area","lead","lady"] forms a word
 * square because each word reads the same both horizontally and vertically.
 *
 *
 * b a l l
 * a r e a
 * l e a d
 * l a d y
 *
 *
 * Note:
 *
 * There are at least 1 and at most 1000 words.
 * All words will have the exact same length.
 * Word length is at least 1 and at most 5.
 * Each word contains only lowercase English alphabet a-z.
 *
 *
 *
 * Example 1:
 *
 * Input:
 * ["area","lead","wall","lady","ball"]
 *
 * Output:
 * [
 * ⁠ [ "wall",
 * ⁠   "area",
 * ⁠   "lead",
 * ⁠   "lady"
 * ⁠ ],
 * ⁠ [ "ball",
 * ⁠   "area",
 * ⁠   "lead",
 * ⁠   "lady"
 * ⁠ ]
 * ]
 *
 * Explanation:
 * The output consists of two word squares. The order of output does not matter
 * (just the order of words in each word square matters).
 *
 *
 *
 * Example 2:
 *
 * Input:
 * ["abat","baba","atan","atal"]
 *
 * Output:
 * [
 * ⁠ [ "baba",
 * ⁠   "abat",
 * ⁠   "baba",
 * ⁠   "atan"
 * ⁠ ],
 * ⁠ [ "baba",
 * ⁠   "abat",
 * ⁠   "baba",
 * ⁠   "atal"
 * ⁠ ]
 * ]
 *
 * Explanation:
 * The output consists of two word squares. The order of output does not matter
 * (just the order of words in each word square matters).
 *
 *
 */

class TrieNode {
public:
  vector<string> startsWith;
  vector<TrieNode *> children;
  TrieNode() : children(26, nullptr) {}
};

TrieNode *buildWords(const vector<string> &words) {
  auto root = new TrieNode();

  for (auto const &word : words) {
    auto curr = root;
    for (char ch : word) {
      if (!curr->children[ch - 'a']) {
        curr->children[ch - 'a'] = new TrieNode();
      }
      curr = curr->children[ch - 'a'];
      curr->startsWith.push_back(word);
    }
  }

  return root;
}

vector<string> find(const TrieNode *node, const string &word) {
  auto curr = node;
  for (char ch : word) {
    if (curr->children[ch - 'a'] == nullptr) {
      return {};
    }
    curr = curr->children[ch - 'a'];
  }
  return curr->startsWith;
}

class Solution {
  void dfs(int level, TrieNode *root, vector<vector<string>> &res,
           vector<string> &out, const vector<string> &words) {
    if (level >= words[0].size()) {
      res.push_back(out);
      return;
    }

    string prefix;
    for (int i = 0; i < level; ++i) {
      prefix += out[i][level];
    }

    for (const string &nextWord : find(root, prefix)) {
      out.push_back(nextWord);
      dfs(level + 1, root, res, out, words);
      out.pop_back();
    }
  }

public:
  vector<vector<string>> wordSquares(const vector<string> &words) {
    vector<vector<string>> res;
    auto root = buildWords(words);
    for (auto const &word : words) {
      vector<string> out{word};
      dfs(1, root, res, out, words);
    }
    return res;
  }
};

#ifdef DEBUG
int main() {
  Solution sol;
  sol.wordSquares({"area", "lead", "wall", "lady", "ball"});
}
#endif
