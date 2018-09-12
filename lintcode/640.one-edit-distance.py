class Solution:
    """
    @param s: a string
    @param t: a string
    @return: true if they are both one edit distance apart or false
    """

    def isOneEditDistance(self, s, t):
        n = len(s)
        m = len(t)

        nm = min(n, m)

        for i in range(nm):
            if s[i] != t[i]:
                return s[i + 1:] == t[i] or s[i +
                                              1:] == t[i +
                                                       1:] or s[i:] == t[i +
                                                                         1:]

        return abs(n - m) == 1
