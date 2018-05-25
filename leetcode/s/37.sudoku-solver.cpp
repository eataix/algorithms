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

  bool solveSudokuDFS(vector<vector<char>> &board, int row, int col) {
    if (row == 9) {
      return true;
    } else if (col >= 9) {
      return solveSudokuDFS(board, row + 1, 0);
    } else {
      if (board[row][col] == '.') {
        for (int i = 1; i <= 9; ++i) {
          board[row][col] = i + '0';
          if (isValid(board, row, col) && solveSudokuDFS(board, row, col + 1)) {
            return true;
          }
        }
        // backtrack
        board[row][col] = '.';
        return false;
      } else {
        return solveSudokuDFS(board, row, col + 1);
      }
    }
  }

  bool isValid(const vector<vector<char>> &board, int row, int col) {
    for (int r = 0; r < 9; ++r) {
      if (r != row && board[row][col] == board[r][col]) {
        return false;
      }
    }
    for (int c = 0; c < 9; ++c) {
      if (c != col && board[row][col] == board[row][c]) {
        return false;
      }
    }

    for (int r = row / 3 * 3; r < (row / 3 + 1) * 3; ++r) {
      for (int c = col / 3 * 3; c < (col / 3 + 1) * 3; ++c) {
        if (r != row && c != col && board[r][c] == board[row][col]) {
          return false;
        }
      }
    }
    return true;
  }
};
