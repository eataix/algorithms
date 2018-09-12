#
# [329] Longest Increasing Path in a Matrix
#
# https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/
#
# algorithms
# Hard (37.61%)
# Total Accepted:    56.9K
# Total Submissions: 151.3K
# Testcase Example:  '[[9,9,4],[6,6,8],[2,1,1]]'
#
# Given an integer matrix, find the length of the longest increasing path.
#
# From each cell, you can either move to four directions: left, right, up or
# down. You may NOT move diagonally or move outside of the boundary (i.e.
# wrap-around is not allowed).
#
# Example 1:
#
#
# Input: nums =
# [
# ⁠ [9,9,4],
# ⁠ [6,6,8],
# ⁠ [2,1,1]
# ]
# Output: 4
# Explanation: The longest increasing path is [1, 2, 6, 9].
#
#
# Example 2:
#
#
# Input: nums =
# [
# ⁠ [3,4,5],
# ⁠ [3,2,6],
# ⁠ [2,2,1]
# ]
# Output: 4
# Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally
# is not allowed.
#
#
#
class Solution:
    def longestIncreasingPath(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: int
        """

        if len(matrix) == 0 or len(matrix[0]) == 0:
            return 0

        numRows = len(matrix)
        numCols = len(matrix[0])
        dp = [[0 for _ in range(numCols)] for _ in range(numRows)]
        res = 0

        def dfs(r, c):
            if dp[r][c] > 0:
                return dp[r][c]
            for dx, dy in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
                newR = r + dx
                newC = c + dy
                if newR >= 0 and newR < numRows and newC >= 0 and newC < numCols and matrix[newR][newC] > matrix[r][c]:
                    dp[r][c] = max(dp[r][c], dfs(newR, newC))
            dp[r][c] += 1
            nonlocal res
            res = max(res, dp[r][c])
            return dp[r][c]

        from itertools import product
        for r, c in product(range(numRows), range(numCols)):
            dfs(r, c)
        return res
