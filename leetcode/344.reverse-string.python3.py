#
# [344] Reverse String
#
# https://leetcode.com/problems/reverse-string/description/
#
# algorithms
# Easy (60.70%)
# Total Accepted:    261.2K
# Total Submissions: 430.2K
# Testcase Example:  '"hello"'
#
# Write a function that takes a string as input and returns the string
# reversed.
#
#
# Example:
# Given s = "hello", return "olleh".
#
#
class Solution:
    def reverseString(self, s):
        """
        :type s: str
        :rtype: str
        """
        return s[::-1]