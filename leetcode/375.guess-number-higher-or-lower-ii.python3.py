#
# [375] Guess Number Higher or Lower II
#
# https://leetcode.com/problems/guess-number-higher-or-lower-ii/description/
#
# algorithms
# Medium (36.25%)
# Total Accepted:    32.8K
# Total Submissions: 90.5K
# Testcase Example:  '1'
#
# We are playing the Guess Game. The game is as follows:
#
# I pick a number from 1 to n. You have to guess which number I picked.
#
# Every time you guess wrong, I'll tell you whether the number I picked is
# higher or lower.
#
# However, when you guess a particular number x,  and you guess wrong, you pay
# $x. You win the game when you guess the number I picked.
#
#
# Example:
#
# n = 10, I pick 8.
#
# First round:  You guess 5, I tell you that it's higher. You pay $5.
# Second round: You guess 7, I tell you that it's higher. You pay $7.
# Third round:  You guess 9, I tell you that it's lower. You pay $9.
#
# Game over. 8 is the number I picked.
#
# You end up paying $5 + $7 + $9 = $21.
#
#
#
# Given a particular n ≥ 1, find out how much money you need to have to
# guarantee a win.
#
# Credits:Special thanks to @agave and @StefanPochmann for adding this problem
# and creating all test cases.
#


class Solution:
    def getMoneyAmount(self, n):
        """
        :type n: int
        :rtype: int
        """
        dp = [[0 for _ in range(n + 1)] for _ in range(n + 1)]

        for length in range(2, n + 1):
            for start in range(1, n + 1):
                end = start + length - 1
                if end > n:
                    break

                dp[start][end] = float('inf')

                for k in range(start, end + 1):
                    if k == start:
                        dp[start][end] = min(dp[start][end],
                                             dp[k + 1][end] + k)
                    elif k == end:
                        dp[start][end] = min(dp[start][end],
                                             dp[start][k - 1] + k)
                    else:
                        dp[start][end] = min(
                            dp[start][end],
                            k + max(dp[start][k - 1], dp[k + 1][end]))

        return dp[1][n]