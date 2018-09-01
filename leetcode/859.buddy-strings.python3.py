#
# [889] Buddy Strings
#
# https://leetcode.com/problems/buddy-strings/description/
#
# algorithms
# Easy (26.04%)
# Total Accepted:    2.3K
# Total Submissions: 8.6K
# Testcase Example:  '"ab"\n"ba"'
#
# Given two strings A and B of lowercase letters, return true if and only if we
# can swap two letters in A so that the result equals B.
#
#
#
# Example 1:
#
#
#
# Input: A = "ab", B = "ba"
# Output: true
#
#
#
# Example 2:
#
#
# Input: A = "ab", B = "ab"
# Output: false
#
#
#
# Example 3:
#
#
# Input: A = "aa", B = "aa"
# Output: true
#
#
#
# Example 4:
#
#
# Input: A = "aaaaaaabc", B = "aaaaaaacb"
# Output: true
#
#
#
# Example 5:
#
#
# Input: A = "", B = "aa"
# Output: false
#
#
#
#
# Note:
#
#
# 0 <= A.length <= 20000
# 0 <= B.length <= 20000
# A and B consist only of lowercase letters.
#
#
#
#
#
#
#
#
class Solution:
    def buddyStrings(self, A, B):
        """
        :type A: str
        :type B: str
        :rtype: bool
        """
        if len(A) != len(B):
            return False
        if A == B and len(set(A)) < len(A):
            return True
        differences = []
        for ch1, ch2 in zip(A, B):
            if ch1 != ch2:
                differences.append([ch1, ch2])
            if len(differences) > 2:
                return False
        if len(differences) != 2:
            return False
        c1, c2 = differences[0]
        c3, c4 = differences[1]
        return c1 == c4 and c2 == c3
