class Solution:
    """
    @param s: a string
    @return: return a boolean
    """

    def repeatedSubstringPattern(self, s):
        n = len(s)

        for i in range(1, n):
            if n % i == 0:
                if s[:i] * (n // i) == s:
                    return True
        return False
