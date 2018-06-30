#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
 * [212] Word Search II
 *
 * https://leetcode.com/problems/word-search-ii/description/
 *
 * algorithms
 * Hard (25.35%)
 * Total Accepted:    70.1K
 * Total Submissions: 276.4K
 * Testcase Example:
 * '[["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]]\n["oath","pea","eat","rain"]'
 *
 * Given a 2D board and a list of words from the dictionary, find all words in
 * the board.
 *
 * Each word must be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring. The
 * same letter cell may not be used more than once in a word.
 *
 * Example:
 *
 *
 * Input:
 * words = ["oath","pea","eat","rain"] and board =
 * [
 * ⁠ ['o','a','a','n'],
 * ⁠ ['e','t','a','e'],
 * ⁠ ['i','h','k','r'],
 * ⁠ ['i','f','l','v']
 * ]
 *
 * Output: ["eat","oath"]
 *
 *
 * Note:
 * You may assume that all inputs are consist of lowercase letters a-z.
 */
class TrieNode {
public:
  vector<shared_ptr<TrieNode>> next;
  string word;
  TrieNode() : next(26, nullptr), word("") {}
};

class Solution {
  vector<pair<int, int>> dirs{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

  shared_ptr<TrieNode> buildTrie(const vector<string> &words) {
    auto root = make_shared<TrieNode>();
    for (const auto &word : words) {
      auto p = root;
      for (char ch : word) {
        int i = ch - 'a';
        if (p->next[i] == nullptr) {
          p->next[i] = make_shared<TrieNode>();
        }
        p = p->next[i];
      }
      p->word = word;
    }
    return root;
  }

  string out;
  void dfs(vector<vector<char>> &board, const int r, const int c,
           shared_ptr<TrieNode> node, vector<string> &res) {
    char ch = board[r][c];
    int v = ch - 'a';

    if (ch == '#' || node->next[v] == nullptr) {
      return;
    }

    node = node->next[v];
    if (node->word.size()) {
      res.push_back(node->word);
      node->word = "";
    }

    board[r][c] = '#';

    for (auto dir : dirs) {
      int newR = r + dir.first;
      int newC = c + dir.second;

      if (newR >= 0 && newR < board.size() && newC >= 0 &&
          newC < board[0].size()) {
        out.push_back(ch);
        dfs(board, newR, newC, node, res);
        out.pop_back();
      }
    }

    board[r][c] = ch;
  }

public:
  vector<string> findWords(vector<vector<char>> &board,
                           const vector<string> &words) {
    if (board.empty() || board[0].empty()) {
      return {};
    }
    vector<string> res;

    auto root = buildTrie(words);

    for (int r = 0; r < board.size(); ++r) {
      for (int c = 0; c < board[0].size(); ++c) {
        dfs(board, r, c, root, res);
      }
    }
    return res;
  }
};

#ifdef DEBUG
int main() {
  vector<string> words{"oath", "pea", "eat", "rain"};
  vector<vector<char>> board{{'o', 'a', 'a', 'n'},
                             {'e', 't', 'a', 'e'},
                             {'i', 'h', 'k', 'r'},
                             {'i', 'f', 'l', 'v'}

  };
  Solution sol;
  sol.findWords(board, words);
}
#endif
