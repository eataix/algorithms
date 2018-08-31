#
# [130] Surrounded Regions
#
# https://leetcode.com/problems/surrounded-regions/description/
#
# algorithms
# Medium (20.18%)
# Total Accepted:    107.7K
# Total Submissions: 533.7K
# Testcase Example:  '[["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]'
#
# Given a 2D board containing 'X' and 'O' (the letter O), capture all regions
# surrounded by 'X'.
#
# A region is captured by flipping all 'O's into 'X's in that surrounded
# region.
#
# Example:
#
#
# X X X X
# X O O X
# X X O X
# X O X X
#
#
# After running your function, the board should be:
#
#
# X X X X
# X X X X
# X X X X
# X O X X
#
#
# Explanation:
#
# Surrounded regions shouldn’t be on the border, which means that any 'O' on
# the border of the board are not flipped to 'X'. Any 'O' that is not on the
# border and it is not connected to an 'O' on the border will be flipped to
# 'X'. Two cells are connected if they are adjacent cells connected
# horizontally or vertically.
#
#
dirs = [(-1, 0), (1, 0), (0, 1), (0, -1)]

class Solution:
    def solve(self, board):
        """
        :type board: List[List[str]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        if len(board) == 0 or len(board[0]) == 0:
            return

        numRows = len(board)
        numCols = len(board[0])

        def dfs(row, col, visited):
            if row < 0 or row >= numRows or col < 0 or col >= numCols or (row, col) in visited or board[row][col] != 'O':
                return
            board[row][col] = '$'
            visited.add((row, col))

            for direction in dirs:
                dx, dy = direction
                newRow = row + dx
                newCol = col + dy
                dfs(newRow, newCol, visited)

            visited.remove((row, col))


        for r in range(numRows):
            for c in range(numCols):
                if r == 0 or r == numRows - 1 or c == 0 or c == numCols - 1:
                    if board[r][c] == 'O':
                        dfs(r, c, set())

        for r in range(numRows):
            for c in range(numCols):
                if board[r][c] == 'O':
                    board[r][c] = 'X'

        for r in range(numRows):
            for c in range(numCols):
                if board[r][c] == '$':
                    board[r][c] = 'O'
