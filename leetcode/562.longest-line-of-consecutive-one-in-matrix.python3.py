#
# [562] Longest Line of Consecutive One in Matrix
#
# https://leetcode.com/problems/longest-line-of-consecutive-one-in-matrix/description/
#
# algorithms
# Medium (41.16%)
# Total Accepted:    8.1K
# Total Submissions: 19.8K
# Testcase Example:  '[[0,1,1,0],[0,1,1,0],[0,0,0,1]]'
#
# Given a 01 matrix M, find the longest line of consecutive one in the matrix.
# The line could be horizontal, vertical, diagonal or anti-diagonal.
#
# Example:
#
# Input:
# [[0,1,1,0],
# ⁠[0,1,1,0],
# ⁠[0,0,0,1]]
# Output: 3
#
#
#
#
# Hint:
# The number of elements in the given matrix will not exceed 10,000.
#
#
class Solution:
    def longestLine(self, M):
        """
        :type M: List[List[int]]
        :rtype: int
        """
        if len(M) == 0 or len(M[0]) == 0:
            return 0

        numRows = len(M)
        numCols = len(M[0])
        dp = [[[0 for _ in range(4)] for _ in range(numCols)]
              for _ in range(numRows)]

        from itertools import product
        res = 0
        for r, c in product(range(numRows), range(numCols)):
            if M[r][c] == 1:
                dp[r][c][0] = 1 + (dp[r - 1][c][0] if r > 0 else 0)
                dp[r][c][1] = 1 + (dp[r][c - 1][1] if c > 0 else 0)
                dp[r][c][2] = 1 + (dp[r - 1][c - 1][2]
                                   if r > 0 and c > 0 else 0)
                dp[r][c][3] = 1 + (dp[r - 1][c + 1][3]
                                   if r > 0 and c < numCols - 1 else 0)

                res = max(res, dp[r][c][0], dp[r][c][1], dp[r][c][2],
                          dp[r][c][3])
        return res
