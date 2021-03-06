#
# [10] Regular Expression Matching
#
# https://leetcode.com/problems/regular-expression-matching/description/
#
# algorithms
# Hard (24.34%)
# Total Accepted:    201.5K
# Total Submissions: 827.9K
# Testcase Example:  '"aa"\n"a"'
#
# Given an input string (s) and a pattern (p), implement regular expression
# matching with support for '.' and '*'.
#
#
# '.' Matches any single character.
# '*' Matches zero or more of the preceding element.
#
#
# The matching should cover the entire input string (not partial).
#
# Note:
#
#
# s could be empty and contains only lowercase letters a-z.
# p could be empty and contains only lowercase letters a-z, and characters like
# . or *.
#
#
# Example 1:
#
#
# Input:
# s = "aa"
# p = "a"
# Output: false
# Explanation: "a" does not match the entire string "aa".
#
#
# Example 2:
#
#
# Input:
# s = "aa"
# p = "a*"
# Output: true
# Explanation: '*' means zero or more of the precedeng element, 'a'. Therefore,
# by repeating 'a' once, it becomes "aa".
#
#
# Example 3:
#
#
# Input:
# s = "ab"
# p = ".*"
# Output: true
# Explanation: ".*" means "zero or more (*) of any character (.)".
#
#
# Example 4:
#
#
# Input:
# s = "aab"
# p = "c*a*b"
# Output: true
# Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore
# it matches "aab".
#
#
# Example 5:
#
#
# Input:
# s = "mississippi"
# p = "mis*is*p*."
# Output: false
#
#
#
class Solution:
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        m = len(s)
        n = len(p)

        dp = [[False for _ in range(n + 1)] for _ in range(m + 1)]
        dp[0][0] = True
        for pLen in range(1, n + 1):
            dp[0][pLen] = p[pLen - 1] == '*' and dp[0][pLen - 2]

        for sLen in range(1, m + 1):
            for pLen in range(1, n + 1):
                if s[sLen - 1] == p[pLen - 1] or p[pLen - 1] == '.':
                    dp[sLen][pLen] = dp[sLen - 1][pLen - 1]
                elif p[pLen - 1] == '*':
                    dp[sLen][pLen] = dp[sLen][pLen - 2]

                    if p[pLen - 2] == '.' or p[pLen - 2] == s[sLen - 1]:
                        dp[sLen][pLen] = dp[sLen][pLen] or dp[sLen - 1][pLen]
        return dp[-1][-1]
