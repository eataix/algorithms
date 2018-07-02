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

class Solution {
  class TrieNode {
  public:
    vector<shared_ptr<TrieNode>> next;
    string word;

    TrieNode() : next(26, nullptr), word("") {}
  };

  shared_ptr<TrieNode> makeRoot(const vector<string> &words) {
    auto root = make_shared<TrieNode>();

    for (auto const &word : words) {
      auto curr = root;
      for (auto ch : word) {
        int v = ch - 'a';
        if (curr->next[v] == nullptr) {
          curr->next[v] = make_shared<TrieNode>();
        }
        curr = curr->next[v];
      }
      curr->word = word;
    }

    return root;
  }
  vector<pair<int, int>> dirs{{
                                  0,
                                  1,
                              },
                              {0, -1},
                              {1, 0},
                              {-1, 0}};

  void dfs(vector<vector<char>> &board, int r, int c, shared_ptr<TrieNode> node,
           vector<string> &res) {
    int numRows = board.size();
    int numCols = board[0].size();

    if (r < 0 || r >= numRows || c < 0 || c >= numCols) {
      return;
    }

    if (board[r][c] == '#' || node->next[board[r][c] - 'a'] == nullptr) {
      return;
    }

    node = node->next[board[r][c] - 'a'];
    if (!node->word.empty()) {
      res.push_back(node->word);
      node->word = "";
    }
    char ch = board[r][c];
    board[r][c] = '#';
    for (auto dir : dirs) {
      int newR = r + dir.first;
      int newC = c + dir.second;

      dfs(board, newR, newC, node, res);
    }
    board[r][c] = ch;
  }

public:
  vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
    auto root = makeRoot(words);
    int numRows = board.size();
    int numCols = board[0].size();
    vector<string> res;
    for (int r = 0; r < numRows; ++r) {
      for (int c = 0; c < numCols; ++c) {
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
