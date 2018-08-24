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

const vector<pair<int, int>> dirs{{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

class Solution {
  bool dfs(const vector<vector<char>> &board, const string &word, int row,
           int col, int len, vector<vector<bool>> &visited) {
    if (len == word.size()) {
      return true;
    }
    int numRows = board.size();
    int numCols = board[0].size();

    if (row < 0 || row >= numRows || col < 0 || col >= numCols ||
        board[row][col] != word[len] || visited[row][col]) {
      return false;
    }

    visited[row][col] = true;

    for (auto const &dir : dirs) {
      auto newRow = row + dir.first;
      auto newCol = col + dir.second;
      if (dfs(board, word, newRow, newCol, len + 1, visited)) {
        return true;
      }
    }

    visited[row][col] = false;
    return false;
  }

public:
  bool exist(vector<vector<char>> &board, string word) {
    if (board.empty() || board[0].empty()) {
      return false;
    }
    int numRows = board.size();
    int numCols = board[0].size();

    vector<vector<bool>> visited(numRows, vector<bool>(numRows, false));

    for (int r = 0; r < numRows; ++r) {
      for (int c = 0; c < numCols; ++c) {
        if (dfs(board, word, r, c, 0, visited)) {
          return true;
        }
      }
    }
    return false;
  }
};
