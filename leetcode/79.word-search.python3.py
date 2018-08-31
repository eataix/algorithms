#
# [79] Word Search
#
# https://leetcode.com/problems/word-search/description/
#
# algorithms
# Medium (28.14%)
# Total Accepted:    175.2K
# Total Submissions: 622.7K
# Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
#
# Given a 2D board and a word, find if the word exists in the grid.
#
# The word can be constructed from letters of sequentially adjacent cell, where
# "adjacent" cells are those horizontally or vertically neighboring. The same
# letter cell may not be used more than once.
#
# Example:
#
#
# board =
# [
# ⁠ ['A','B','C','E'],
# ⁠ ['S','F','C','S'],
# ⁠ ['A','D','E','E']
# ]
#
# Given word = "ABCCED", return true.
# Given word = "SEE", return true.
# Given word = "ABCB", return false.
#
#
#
class Solution:
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """

        if len(board) == 0 or len(board[0]) == 0:
            return False

        numRows = len(board)
        numCols = len(board[0])

        def dfs(row, col, level):
            if level == len(word):
                return True
            if row < 0 or row >= numRows or col < 0 or col >= numCols:
                return False
            if board[row][col] != word[level]:
                return False

            ch = board[row][col]
            board[row][col] = '$'
            for dx, dy in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
                if dfs(row + dx, col + dy, level + 1):
                    return True
            board[row][col] = ch
            return False

        from itertools import product
        for r, c in product(range(numRows), range(numCols)):
            if dfs(r, c, 0):
                return True

        return False
