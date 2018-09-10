class Solution:
    """
    @param s: a string which consists of lowercase or uppercase letters
    @return: the length of the longest palindromes that can be built
    """

    def longestPalindrome(self, s):
        from collections import defaultdict
        cnts = defaultdict(int)

        for ch in s:
            cnts[ch] += 1

        res = 0
        for _, v in cnts.items():
            res += v // 2 * 2

            if res % 2 == 0 and v % 2 == 1:
                res += 1

        return res
