#include <string>
#include <vector>
using namespace std;
/*
 * [79] Word Search
 *
 * https://leetcode.com/problems/word-search/description/
 *
 * algorithms
 * Medium (28.14%)
 * Total Accepted:    175.2K
 * Total Submissions: 622.7K
 * Testcase Example:
 * '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * Given a 2D board and a word, find if the word exists in the grid.
 *
 * The word can be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring. The
 * same letter cell may not be used more than once.
 *
 * Example:
 *
 *
 * board =
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 *
 * Given word = "ABCCED", return true.
 * Given word = "SEE", return true.
 * Given word = "ABCB", return false.
 *
 *
 */
class Solution {
public:
  bool exist(const vector<vector<char>> &board, string word) {
    if (board.empty() || board[0].empty()) {
      return false;
    }
    int n = board.size();
    int m = board[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (findWord(board, i, j, word, 0, visited)) {
          return true;
        }
      }
    }
    return false;
  }

  bool findWord(const vector<vector<char>> &board, int i, int j,
                const string &word, int idx, vector<vector<bool>> &visited) {

    if (idx == word.size()) {
      return true;
    }
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() ||
        visited[i][j] || board[i][j] != word[idx]) {
      return false;
    }

    visited[i][j] = true;
    if (findWord(board, i, j - 1, word, idx + 1, visited)) {
      return true;
    }
    if (findWord(board, i, j + 1, word, idx + 1, visited)) {
      return true;
    }
    if (findWord(board, i - 1, j, word, idx + 1, visited)) {
      return true;
    }
    if (findWord(board, i + 1, j, word, idx + 1, visited)) {
      return true;
    }
    visited[i][j] = false;
    return false;
  }
};
