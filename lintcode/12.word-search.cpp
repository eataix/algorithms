class Solution {
public:
  /**
   * @param board: A list of lists of character
   * @param word: A string
   * @return: A boolean
   */
  bool exist(vector<vector<char>> &board, string &word) {
    if (board.empty() || board[0].empty()) {
      return word.empty();
    }
    int rows = board.size();
    int cols = board[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    for (int row = 0; row < rows; ++row) {
      for (int col = 0; col < cols; ++col) {
        if (dfs(board, word, 0, row, col, visited)) {
          return true;
        }
      }
    }
    return false;
  }

  bool dfs(const vector<vector<char>> &board, string &word, int idx, int row,
           int col, vector<vector<bool>> &visited) {
    if (idx >= word.size()) {
      return true;
    }
    if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() ||
        visited[row][col] || board[row][col] != word[idx]) {
      return false;
    }

    visited[row][col] = true;
    if (dfs(board, word, idx + 1, row - 1, col, visited)) {
      return true;
    }
    if (dfs(board, word, idx + 1, row + 1, col, visited)) {
      return true;
    }
    if (dfs(board, word, idx + 1, row, col - 1, visited)) {
      return true;
    }
    if (dfs(board, word, idx + 1, row, col + 1, visited)) {
      return true;
    }
    visited[row][col] = false;
    return false;
  }
};
