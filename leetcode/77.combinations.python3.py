#
# [77] Combinations
#
# https://leetcode.com/problems/combinations/description/
#
# algorithms
# Medium (42.70%)
# Total Accepted:    155K
# Total Submissions: 362.9K
# Testcase Example:  '4\n2'
#
# Given two integers n and k, return all possible combinations of k numbers out
# of 1 ... n.
#
# Example:
#
#
# Input: n = 4, k = 2
# Output:
# [
# ⁠ [2,4],
# ⁠ [3,4],
# ⁠ [2,3],
# ⁠ [1,2],
# ⁠ [1,3],
# ⁠ [1,4],
# ]
#
#
#
class Solution:
    def combine(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[List[int]]
        """

        out = []
        res = []

        def dfs(start):
            if len(out) == k:
                res.append(list(out))
                return
            for i in range(start + 1, n + 1):
                out.append(i)
                dfs(i)
                out.pop()

        dfs(0)

        return res