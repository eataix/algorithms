#include <vector>
using namespace std;
/*
 * [37] Sudoku Solver
 *
 * https://leetcode.com/problems/sudoku-solver/description/
 *
 * algorithms
 * Hard (32.20%)
 * Total Accepted:    93.4K
 * Total Submissions: 288.4K
 * Testcase Example:
 * '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 *
 * A sudoku solution must satisfy all of the following rules:
 *
 *
 * Each of the digits 1-9 must occur exactly once in each row.
 * Each of the digits 1-9 must occur exactly once in each column.
 * Each of the the digits 1-9 must occur exactly once in each of the 9 3x3
 * sub-boxes of the grid.
 *
 *
 * Empty cells are indicated by the character '.'.
 *
 *
 * A sudoku puzzle...
 *
 *
 * ...and its solution numbers marked in red.
 *
 * Note:
 *
 *
 * The given board contain only digits 1-9 and the character '.'.
 * You may assume that the given Sudoku puzzle will have a single unique
 * solution.
 * The given board size is always 9x9.
 *
 *
 */
class Solution {
public:
  void solveSudoku(vector<vector<char>> &board) { solveSudokuDFS(board, 0, 0); }

  bool solveSudokuDFS(vector<vector<char>> &board, int r, int c) {
    if (r == 9) {
      return true;
    }

    if (c >= 9) {
      return solveSudokuDFS(board, r + 1, 0);
    }

    if (board[r][c] == '.') {
      for (int k = 1; k <= 9; ++k) {
        board[r][c] = k + '0';
        if (isValid(board, r, c)) {
          if (solveSudokuDFS(board, r, c + 1)) {
            return true;
          }
        }
        board[r][c] = '.';
      }
    } else {
      return solveSudokuDFS(board, r, c + 1);
    }
    return false;
  }

  bool isValid(const vector<vector<char>> &board, int r, int c) {
    for (int col = 0; col < 9; ++col) {
      if (col != c && board[r][c] == board[r][col]) {
        return false;
      }
    }
    for (int row = 0; row < 9; ++row) {
      if (row != r && board[r][c] == board[row][c]) {
        return false;
      }
    }

    for (int row = r / 3 * 3; row < (r / 3 + 1) * 3; ++row) {
      for (int col = c / 3 * 3; col < (c / 3 + 1) * 3; ++col) {
        if (row != r && col != c && board[row][col] == board[r][c]) {
          return false;
        }
      }
    }
    return true;
  }
};
