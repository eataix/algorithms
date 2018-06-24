#include <vector>

using namespace std;

class Solution {
public:
  /**
   * @param board: the sudoku puzzle
   * @return: nothing
   */
  void solveSudoku(vector<vector<int>> &board) { dfs(board, 0, 0); }

  bool dfs(vector<vector<int>> &board, int row, int col) {
    if (row >= 9) {
      return true;
    }

    if (col >= 9) {
      return dfs(board, row + 1, 0);
    }

    if (board[row][col] == 0) {
      for (int v = 1; v <= 9; ++v) {
        board[row][col] = v;
        if (isValid(board, row, col) && dfs(board, row, col + 1)) {
          return true;
        }
      }
      board[row][col] = 0;
      return false;
    } else {
      return dfs(board, row, col + 1);
    }
  }

  bool isValid(const vector<vector<int>> &board, int r, int c) {
    vector<int> rows(9, false);
    vector<int> cols(9, false);
    vector<int> boxes(9, false);

    for (int offset = 0; offset < 9; ++offset) {
      if (offset != c && board[r][c] == board[r][offset]) {
        return false;
      }
      if (offset != r && board[r][c] == board[offset][c]) {
        return false;
      }
    }

    for (int newR = r / 3 * 3; newR < (r / 3 + 1) * 3; ++newR) {
      for (int newC = c / 3 * 3; newC < (c / 3 + 1) * 3; ++newC) {
        if (newR != r && newC != c && board[newR][newC] == board[r][c]) {
          return false;
        }
      }
    }
    return true;
  }
};
