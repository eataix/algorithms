#
# [290] Word Pattern
#
# https://leetcode.com/problems/word-pattern/description/
#
# algorithms
# Easy (33.50%)
# Total Accepted:    103.4K
# Total Submissions: 308.7K
# Testcase Example:  '"abba"\n"dog cat cat dog"'
#
# Given a pattern and a string str, find if str follows the same pattern.
# ⁠Here follow means a full match, such that there is a bijection between a
# letter in pattern and a non-empty word in str.
# 
# Examples:
# 
# pattern = "abba", str = "dog cat cat dog" should return true.
# pattern = "abba", str = "dog cat cat fish" should return false.
# pattern = "aaaa", str = "dog cat cat dog" should return false.
# pattern = "abba", str = "dog dog dog dog" should return false.
# 
# 
# 
# 
# Notes:
# You may assume pattern contains only lowercase letters, and str contains
# lowercase letters separated by a single space.
# 
# 
# Credits:Special thanks to @minglotus6 for adding this problem and creating
# all test cases.
#
class Solution:
    def wordPattern(self, pattern, match):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        d = {}
        seen = set()
        words = match.split(' ')
        if len(words) != len(pattern):
            return False

        for idx in range(len(words)):
            word = words[idx]
            ch= pattern[idx]
            if ch in d:
                if d[ch] != word:
                    return False
            else:
                if word in seen:
                    return False
                d[ch] = word
                seen.add(word)
        return True